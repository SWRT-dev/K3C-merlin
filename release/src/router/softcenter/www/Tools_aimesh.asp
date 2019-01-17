<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<html xmlns:v>
<head>
<meta http-equiv="X-UA-Compatible" content="IE=Edge"/>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta HTTP-EQUIV="Pragma" CONTENT="no-cache">
<meta HTTP-EQUIV="Expires" CONTENT="-1">
<link rel="shortcut icon" href="images/favicon.png">
<link rel="icon" href="images/favicon.png">
<title>Aimesh教程</title>
<link rel="stylesheet" type="text/css" href="index_style.css">
<link rel="stylesheet" type="text/css" href="form_style.css">
<script language="JavaScript" type="text/javascript" src="/state.js"></script>
<script language="JavaScript" type="text/javascript" src="/general.js"></script>
<script language="JavaScript" type="text/javascript" src="/form.js"></script>
<script language="JavaScript" type="text/javascript" src="/help.js"></script>
<script language="JavaScript" type="text/javascript" src="/popup.js"></script>
<script language="JavaScript" type="text/javascript" src="/js/jquery.js"></script>
<script type="text/javascript" src="/js/httpApi.js"></script>
<style>
</style>
<script>
function initial(){
	show_menu();
}
</script>
</head>
<body onload="initial();" onunLoad="return unload_body();">
<div id="TopBanner"></div>
<div id="Loading" class="popup_bg"></div>

<iframe name="hidden_frame" id="hidden_frame" src="" width="0" height="0" frameborder="0"></iframe>

<form method="post" name="form" id="ruleForm" action="/start_apply.htm" target="hidden_frame">
<input type="hidden" name="current_page" value="Tools_aimesh.asp">
<input type="hidden" name="preferred_lang" id="preferred_lang" value="<% nvram_get("preferred_lang"); %>">
<table class="content" align="center" cellpadding="0" cellspacing="0">
	<tr>
		<td width="17">&nbsp;</td>
	<!--=====Beginning of Main Menu=====-->
		<td valign="top" width="202">
			<div id="mainMenu"></div>
			<div id="subMenu"></div>
		</td>
		<td valign="top">
			<div id="tabMenu" class="submenuBlock"></div>
		<!--===================================Beginning of Main Content===========================================-->
			<table width="98%" border="0" align="left" cellpadding="0" cellspacing="0">
				<tr>
					<td valign="top" >
						<table width="760px" border="0" cellpadding="4" cellspacing="0" class="FormTitle" id="FormTitle">
							<tbody>
							<tr>
								<td bgcolor="#4D595D" valign="top">
										<div>&nbsp;</div>
										<div style="float:left;" class="formfonttitle">Aimesh教程</div>
										<div style="float:right; width:15px; height:25px;margin-top:10px"><img id="return_btn" onclick="reload_Soft_Center();" align="right" style="cursor:pointer;position:absolute;margin-left:-30px;margin-top:-25px;" title="返回软件中心" src="/images/backprev.png" onMouseOver="this.src='/images/backprevclick.png'" onMouseOut="this.src='/images/backprev.png'"></img></div>
										<div style="margin-left:5px;margin-top:10px;margin-bottom:10px"><img src="/images/New_ui/export/line_export.png"></div>
										<div class="formfontdesc" style="padding-top:5px;margin-top:0px;float: left;" id="cmdDesc">说明</div>
										<div style="color:#FC0;padding-top:5px;margin-top:25px;margin-left:0px;float: left;" id="NoteBox" >
                                                                                        <li style="margin-top:5px;">支持主路由及节点模式 </li>
                                                                                        <li style="margin-top:5px;">支持华硕原装及K3C</li>
										</div>
										<div>&nbsp;</div>
										<table style="margin:10px 0px 0px 0px;" width="100%" border="1" align="center" cellpadding="4" cellspacing="0" bordercolor="#6b8fa3" class="FormTable" id="routing_table">
											<thead>
												<tr>
													<td colspan="2">Aimesh教程</td>
												</tr>
											</thead>
											<tr>
											<th width="30%" style="border-top: 0 none;">第一步</th>
											<td style="border-top: 0 none;">
											<div>连接节点路由的WAN口到主路由的LAN口，并重置节点路由（捅菊花）</div>
											</td>
											</tr>
											<tr>
											<th width="30%" style="border-top: 0 none;">第二步</th>
											<td style="border-top: 0 none;">
											<div>等待节点路由重启完成后，点击主路由的搜索Aimesh节点</div>
											</td>
											</tr>
											<tr>
											<th width="30%" style="border-top: 0 none;">第三步</th>
											<td style="border-top: 0 none;">
											<div>等待5分钟安装完，如失败重复第一步和第二步</div>
											</td>
											</tr>
											<tr>
											<th width="30%" style="border-top: 0 none;">第四步</th>
											<td style="border-top: 0 none;">
											<div>安装完成后，节点列表会出现对应节点，这时可以拔下网线，几秒后自动转为无线回程</div>
											</td>
											</tr>
										</table>
										<table style="margin:10px 0px 0px 0px;" width="100%" border="1" align="center" cellpadding="4" cellspacing="0" bordercolor="#6b8fa3" class="FormTable" id="routing_table">
											<thead>
												<tr>
													<td colspan="2">日常使用说明</td>
												</tr>
											</thead>
											<tr>
											<th width="30%" style="border-top: 0 none;">当主路由重启或关机后，节点列表会清空，这时只需要开启节点等待5分钟就会自动加入</th>
											</tr>
											<tr>
											<th width="30%" style="border-top: 0 none;">如果没有自动加入，连接节点WAN口到路由的LAN口并重启，成功加入后拔掉网线即可</th>
											</tr>
											<tr>
											<th width="30%" style="border-top: 0 none;">节点重置后，主路由只有删除对应节点后才能再次加入</th>
											</tr>
										</table>
								</td>
							</tr>
							</tbody>
						</table>
					</td>
				</tr>
			</table>
		<!--===================================Ending of Main Content===========================================-->
		</td>
		<td width="10" align="center" valign="top">&nbsp;</td>
	</tr>
</table>
</form>
<div id="footer"></div>
</body>
</html>
