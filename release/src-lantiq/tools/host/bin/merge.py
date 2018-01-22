#! /opt/TWWfsw/bin/python

###################################################################################
#        Copyright (c) 2014 
#
#        Lantiq Beteiligungs-GmbH & Co. KG 
#
#        Lilienthalstrasse 15, 85579 Neubiberg, Germany  
#
#        For licensing information, see the file 'LICENSE' in the root folder of 
#
#        this software module.
###################################################################################

''' Merges all control and data XMLs

This utility is used to 

1. Merges all control and data XMLs by properly comparing the hierarchy
   of nodes in differnt XMLs

2. Validates the merged XMLs with an XSD file to make sure that the
   merged XML has all the attributes required during runtime.

EXTERNAL DEPENDENCIES
--------------------
lxml

HOW TO USE
----------

python merge.py -v XSDFILE 1_control.xml 2_control.xml -o target_control.xml
python merge.py 1_control.xml 2_control.xml -o target_control.xml -> Without validation

python merge.py -v XSDFILE *_data.xml -o target_data.xml

INFO
----

python merge.py --help
'''

import sys, os

''' Using lxml library compiled and kept in staging_dir_host '''
sys.path.append(os.path.join(os.path.dirname(sys.path[0]),'lib'))

from lxml import etree
import argparse
import textwrap
import re
import itertools
import subprocess
import shutil

def remove_attrib(tree, attrib):
    '''
    Removes an attribute from the whole tree

    tree(INOUT) -> Tree from with attribute should be removed
    attrib(IN)  -> Attribute that is to be removed
    '''
    root = tree.getroot()
    for node in root.iter():
        try:
            del node.attrib[attrib]
        except:
            pass

    return tree


def get_full_path(node):
    '''
    Function for fully qualifying a node name for header files.

    node(IN) -> Node for which you want to return full hierarchy string
    '''
    sDefine = '' + node.tag
    while node.getparent() != None:
        sDefine = node.getparent().tag + '_' + sDefine
        node = node.getparent()
    return sDefine.upper()


def prepare_for_validation(tree):
    '''
    1. Renames node names as either 'Object' or 'Parameter' to make
    validation with xsd simple

    2. Adds type attribute

    tree(IN) -> XML Tree for which you want to change node names
    '''
    root = tree.getroot()
    if decode_xml(tree) == False:
	print ('\n \n \n \n @@@@@@ VALIDATION FAILED @@@@@@@ \n \n \n \n')
	sys.exit(1)
    for child in root:
        for node in child.iter():
            #if no. of children is 0, that is a parameter node
            node.attrib['Name'] = node.tag
            if len(node) ==  0:
                node.tag = "Parameter"
            else:
                node.tag = "Object"
    tree.write('./modified_xml_for_validation.xml', pretty_print=True)
    return tree

def decode_xml(tree):
    """
    Reads the encoded 'Flag' attribute and regenerates back all the attributes.
    This is necessary for generating original xml back from id added xml. It uses
    the same mapping used from encoding to regenerate the encoded attributes.

    ARGS:
        INOUT: tree -> xml tree
    """
    syntax = {'int':0x1,'unsignedInt':0x2,'string':0x4,'dateTime':0x8, 'boolean':0x10, 'float': 0x10000000, \
                  'hexBinary':0x20, 'long':0x40,'unsignedLong':0x80,'base64':0x100, 'none':0x200}

    XSI = "http://www.w3.org/2001/XMLSchema-instance"
    XSD = "http://www.w3.org/2001/XMLSchema"
    decFlg = True
    for node in tree.iter():
        flag = node.get('Flag')

        if flag == None or node.tag == 'Value' or len(node) != 0:
            continue

        for type_key in syntax:
            #print(node.tag, syntax[type_key], flag)
            flag = flag.strip()
            type_value = syntax[type_key]
            #temporary fix for ipv6 empty Flag attribute
            try:
                and_val = type_value & int(flag, 16)
            except:
                continue
            #print(and_val, type_value)
            if and_val == type_value:
		minVal = node.get('minInclusive')
		maxVal = node.get('maxInclusive')
		minLen = node.get('minLength')
		maxLen = node.get('maxLength')
		objPath = get_full_path_validate(node)
                if type_key == 'int' :
                    if node.text == None or node.text == ' ' :
                        print('Schema Validation Failed for Integer DataType ==> Object='  + objPath + ' @@@VALUE CAN NOT BE EMPTY@@@'  )
			decFlg = False
		    elif minVal != None:
			try:
			    int(minVal) or int(node.text)
			except ValueError:
   			    continue
		        if int(minVal) > int(node.text):
                    	    print('Schema Validation Failed for Integer DataType ==> Object='  + objPath  + ' ParameterValue=' + node.text +' @@@ INVALID VALUE SHOULD BE GREATER THAN MININCLUSIVE  @@@'  )
			    decFlg = False
		    elif maxVal != None: 
			try:
			    int(maxVal) or int(node.text)
			except ValueError:
   			    continue
			if int(maxVal) < int(node.text):
                    	    print('Schema Validation Failed for Integer DataType ==> Object=' + objPath + ' ParameterValue=' + node.text +' @@@ INVALID VALUE SHOULD BE LESS THAN MAXINCLUSIVE  @@@'  )
			    decFlg = False
		elif type_key == 'unsignedInt' :
                    if node.text == None or node.text == ' ': 
                    	print('Schema Validation Failed for unsignedInt DataType ==> Object=' + objPath  + ' @@@VALUE CAN NOT BE EMPTY@@@'  )
			decFlg = False
		    if node.text < str(0):
                    	print('Schema Validation Failed for unsignedInt DataType ==> Object=' + objPath + ' ParameterValue=' + node.text +' @@@ NEGATIVE VALUE NOT ALLOWED@@@'  )
			decFlg = False
		    if minVal != None: 
		        try:
			    int(minVal) or int(node.text)
			except ValueError:
   			    continue
		        if int(minVal) > int(node.text):
                    	    print('Schema Validation Failed for unsignedInt DataType ==> Object=' + objPath + ' ParameterValue=' + node.text +' @@@ INVALID VALUE SHOULD BE GREATER THAN MININCLUSIVE  @@@'  )
			    decFlg = False
		    if maxVal != None: 
		        try:
			    int(maxVal) or int(node.text)
			except ValueError:
   			    continue
			if int(maxVal) < int(node.text):
                    	    print('Schema Validation Failed for unsignedInt DataType ==> Object=' + objPath + ' ParameterValue=' + node.text +' @@@ INVALID VALUE SHOULD BE LESS THAN MAXINCLUSIVE  @@@'  )
			    decFlg = False
		elif type_key == 'boolean':
                    if node.text == None or node.text == ' ': 
                    	print('Schema Validation Failed for boolean DataType ==> Object=' + objPath + ' @@@VALUE CAN NOT BE EMPTY@@@'  )
			decFlg = False
                    elif node.text.lower() != 'true' and node.text.lower() != 'false' and node.text != str(0) and node.text != str(1): 
                    	print('Schema Validation Failed for boolean DataType ==> Object=' + objPath + ' ParameterValue=' + node.text +' @@@INVALID VALUE@@@'  )
			decFlg = False
		elif type_key == 'string':
		    if node.text != None:
		        strlen = len(node.text)
		    	if  minLen != None:
			    try:
			        int(minLen)
			    except ValueError:
			        continue
			    if strlen < int(minLen):
			        print('Schema Validation Failed for string DataType ==> Object=' + objPath  + ' @@@ INVALID VALUE SHOULD BE GREATER THAN MINLENGTH  @@@'  )
			        decFlg = False
		        if maxLen != None: 
			    try:
			        int(maxLen)
			    except ValueError:
			        continue
			    if strlen > int(maxLen):
			        print('Schema Validation Failed for string DataType ==> Object=' + objPath + ' @@@ INVALID VALUE SHOULD BE LESS THAN MAXLENGTH  @@@'  )
			        decFlg = False
                    	if node.text != ' ' and node.get('enum') != None: 
				if node.text in node.get('enum'):
				    continue
				else:
			            print('Schema Validation Failed for string DataType ==> Object=' + objPath + '  Enum list ==> ' + node.get('enum') + ' @@@ Enum value should be empty or any one of the value from the eum list  @@@'  )
				    decFlg = False
    return decFlg

def validate(xmltree, schemaxml):
    '''
    Validates xml against xsd

    xmltree(IN)   -> Tree of XML that should be validated
    schemaxml(IN) -> Schema XML on which the xml tree should be
                     validated against

    NOTE: Make sure that this function is the last step. A fresh copy of
    xml tree is created here so that all the manipulations to tree are
    lost after this function. your pointer mechanics no longer work
    '''
    try:
        schematree = etree.XMLSchema(etree.parse(schemaxml))
    except:
        print('Could not parse schema file')
        sys.exit(1)
    #-- adding namespace to xml before validation
    XSI = "http://www.w3.org/2001/XMLSchema-instance"
    XSD = "http://www.w3.org/2001/XMLSchema"

    nsmap = {'xsi': XSI, 'xsd':XSD }

    root = xmltree.getroot()
    new_root = etree.Element(root.tag, nsmap=nsmap)
    new_root[:] = root[:]
    xmltree = new_root.getroottree()
    xmlparser = etree.XMLParser(schema=schematree)

    xmltree = prepare_for_validation(xmltree)
    if schematree.validate(xmltree) == False:
        print('!!! VALIDATION FAILURE WITH XSD !!!')
        #xmllint --noout --schema Time_control.xsd modified.xml 
        command = ("xmllint", "--noout", "--schema", schemaxml, "modified_xml_for_validation.xml")
        popen = subprocess.Popen(command,stdout=subprocess.PIPE)
        popen.wait()
        output = popen.stdout.read()
        print(output)
        raise AttributeError('Attributes not validated as per xsd')
    else:
        print('@@@ XML VALIDATES WITH XSD @@@')
    return xmltree

def best_match(str1, str2):
    '''
    Compares 2 strings containing '_'s which represent full hierarchy of a node.
    Returns an integer representing number of hierarchical level
    matchins. This is used for finding siblings while performing a deep
    merge.

    str1(IN) -> String 1 representing node 1 hierarchy
    str2(IN) -> String 2 representing node 2 hierarchy
    '''
   
    #print('matching ###', small, big)
    match = None
    count = 0
    if len(str1) > len(str2):
        match = re.match(str2, str1)
    else:
        match = re.match(str1, str2)
    if match != None:
        count = match.group(0).count('_')
        if count == 1:
            print('matched -->', str1, str2, count)
    return count


def restructure_xml(tree):
    '''
    Returns a restructured xml tree moving parameter nodes above child object nodes.

    tree(INOUT) -> XML Tree that you want to restructure
    '''
    #parser = etree.XMLParser(remove_blank_text=True) # lxml.etree only!
    #tree = etree.parse(xml, parser)
    root = tree.getroot()
    #Moving parameter nodes twice because the order will be reversed
    #during 1st iteration
    for count in range(2):
        for child in root:
            for node in child.iter():
                #if no. of children is 0, that is a parameter node
                if len(node) ==  0:
                    node.getparent().insert(0, node)
    return tree


def get_full_path_validate(node):
    '''
    Function for fully qualifying a node name for header files.

    node(IN) -> Node for which you want to return full hierarchy string
    '''
    sDefine = '' + node.tag
    while node.getparent() != None:
	if node.get('Instance') != None : 
        	sDefine = node.getparent().tag + '.'+ node.get('Instance') + '.' + sDefine
	else:
        	sDefine = node.getparent().tag + '.'+ sDefine
        node = node.getparent()
    return str(sDefine)

def remove_unsupported(tree):
    for node in tree:
        if len(node) == 0:
            node.getparent().remove(node)
        elif len(node) is not 0 and node.get('Id') == str(-1):
            node.getparent().remove(node) #In case of recursive merge, don't do this in future

def deep_merge(tree):
    '''
    (Deep)merge the nodes with same hirerachy.

    After appending all the XMLs, it is possible that 2 nodes might be
    of same hierarcy. We need to merge all the children of such nodes.

    Take a node and compare it with all its siblings.

    Node1 --> Check every non-leaf node inside a node. 
    Node2 --> Check all the siblings and match the node with same hireachy 

    Move matched Node2 elements to Node1 and Delete Node2.

    We need to check only siblings because others will have diffent
    parents and hirerachy will change

    tree(IN) -> XML tree from which merging should be performed
    '''

    #iterate through every (just)child node under device
    #If you want to do a recursive merge, replace getroot() with iter()
    for node1 in tree.getroot():
        #get the siblings of above node
        for node2 in node1.itersiblings():
            #Merge the siblings if hirerachy matches. 
            #Ignore the leaf nodes as we cannot move one leaf node into other.
            #Instances in data xmls have same name. We shouldn't merge instances. Ignore them.
            if len(node1) != 0 and get_full_path(node2) == get_full_path(node1) and node1.get('Instance') == None:

	
                #We'll move everything inside node 2 into node 1.
                #If node1 is notSupported object, attributes of
                #supported object should be retained
                if node1.get('Id') == str(-1):
                    #clean unsupported parameters and objects before merging
                    #remove_unsupported(node1)
                    #Remove the attributes of notSupported node
                    for attrib in node1.attrib:
                        try:
                            del node1.attrib[attrib]
                        except:
                            pass
                    #move the attributes of supported object into
                    #notSupported object
                    for attrib in node2.attrib:
                        node1.attrib[attrib] = node2.get(attrib)
                elif node2.get('Id') == str(-1):
                    #clean unsupported parameters and objects before merging
                    #remove_unsupported(node2)
                    pass
                else:
                    error_msg = 'Merge error. Could not merge ' + node1.tag + ' and ' + node2.tag + '. Atleast one should be unsupported'
                    raise NameError(error_msg)
                print('merging-->',node1.tag, node2.tag)
                #move everything inside node2 to node1 n delete the remains of node2
                for node in node2:
                    #In control xmls, check if children are mutally exclusive during
                    #merge. Don't care incase of data xmls (Instances will have same name)
                    if node.get('Instance') == None and node1.find(node.tag) is not None:
                        error_msg = 'Children in nodes that are being merged should be mutally exclusive. Both the nodes has --> ' + node.tag
                        raise NameError(error_msg)
                    node1.append(node)
                node2.getparent().remove(node2)
        restructure_xml(tree)
    return tree   

def renameTag(xmlList):
    for filename in xmlList:
        DevFlag = 0
	wrFlag = 0
	tree = etree.parse(filename)
    	for node in tree.iter():
	    if node.tag == 'Device' and DevFlag == 0 :
	        DevFlag = 1
	    elif node.tag == 'Device' and DevFlag == 1:
		node.tag = "__DeviceTmp__"
		wrFlag = 1
	if wrFlag == 1:
            tree.write(filename, pretty_print=True)

def revertTag(tree):
    for node in tree.iter():
        if node.tag == '__DeviceTmp__':
	    node.tag = "Device"
    return tree

def stitch_xmls(xmlList):
    '''
    Stitches all the xmls in xmlList and strips the extra 'Device' nodes (level corrected)
    This operation creates a single XML tree out of multiple XMLs. 

    But keep in mind that same node hierarchy might exist in different
    XMLs. deep_merge will do the merging of same hierarchy nodes in this
    full XML tree

    xmlList(IN) -> List of XMLs that should be merged
    '''
    renameTag(xmlList)
    count = 0
    tree = None
    service_xmls = []
    for filename in xmlList:
        if count == 0:
            try:
                tree = etree.parse(filename)
            except:
                import traceback
                print('@@@@@@@@@@ Could not parse the file -->' + filename)
                traceback.print_exc()
                sys.exit(1)
            count = 1
            continue
        elif count != 0 and tree != None:
            try:
                tree_next = etree.parse(filename)
            except:
                import traceback
                print('@@@@@@@@@@ Could not parse the file -->' + filename)
                traceback.print_exc()
                sys.exit(1)
            root = tree_next.getroot()
            tree.getroot().append(tree_next.getroot())
    etree.strip_tags(tree.getroot(), 'Device')
    revertTag(tree)
    return tree

##################### for parsing command line options and arguments ######################

def arg_parse_init():
    '''
    Defines a structure for command line arguments. All the violations
    in commandline arguments will be reported with a 'help' output
    '''

    parser = argparse.ArgumentParser(formatter_class=argparse.RawDescriptionHelpFormatter, description=textwrap.dedent('''\
        Usage Examples
    --------------------------------
    python merge.py *_control.xml -o target_control.xml
    python merge.py *_data.xml    -o target_data.xml

    python merge.py -v XSD_FILE *_control.xml -o target_control.xml

    NOTE: By default, output file is placed in current folder with name 'output.xml' '''))

    parser.add_argument('input_files', nargs='+', help='optional input xml files')
    parser.add_argument('-o', '--outputfile', dest="outputfilepath", default= "output.xml", help="Output file name")
    parser.add_argument('-v', '--validate', dest="xsdfile", help = "Performs validation against XSD file specified")
    parser.add_argument('--debug', dest="debug", action='store_true', help = "Keeps the modified xml file which is used for validation")

    ipargs = parser.parse_args()
    return ipargs

def merge(ipargs):
    '''
    Start merging XMLs provided by input args

    ipargs(IN) -> Command line options
    '''
    print('####################################')
    print('              MERGING           ')
    print('####################################')

    print('merging these files -->', ipargs.input_files)

    tree = stitch_xmls(ipargs.input_files)
    tree = deep_merge(tree)
    #remove node attribute before generating target xml
    tree = remove_attrib(tree, 'node')

    tree.write(ipargs.outputfilepath, pretty_print=True)

    if ipargs.xsdfile != None:
        modified_xmltree = validate(tree, ipargs.xsdfile)
        if ipargs.debug == False:
            try:
                #os.remove('./modified_xml_for_validation.xml')
                pass
            except:
                print("Couldn't remove folders")

    print('DONE')

if __name__ == '__main__':
    ipargs = arg_parse_init()
    merge(ipargs)
