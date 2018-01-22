/* cs_eip201.h
 *
 * Configuration Settings for the EIP-201 Driver Library module.
 */

/*****************************************************************************
* Copyright (c) 2008-2013 INSIDE Secure B.V. All Rights Reserved.
*
* This confidential and proprietary software may be used only as authorized
* by a licensing agreement from INSIDE Secure.
*
* The entire notice above must be reproduced on all authorized copies that
* may only be made to the extent permitted by a licensing agreement from
* INSIDE Secure.
*
* For more information or support, please go to our online support system at
* https://essoemsupport.insidesecure.com.
* In case you do not have an account for this system, please send an e-mail
* to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#include "cs_driver.h"      // top-level driver configuration

// set this option to enable checking of all arguments to all EIP201 functions
// disable it to reduce code size and reduce overhead
#ifndef DRIVER_PERFORMANCE
#define EIP201_STRICT_ARGS
#endif

// maximum number of interrupts as defined for this instance
#define EIP201_STRICT_ARGS_MAX_NUM_OF_INTERRUPTS  32

/* EIP201_REMOVE_*
 *
 * These switches allow removal of unused API functions
 * to reduce footprint and increase code-coverage figures
 */
#define EIP201_REMOVE_CONFIG_CHANGE
#define EIP201_REMOVE_CONFIG_READ
//#define EIP201_REMOVE_SOURCEMASK_ENABLESOURCE
//#define EIP201_REMOVE_SOURCEMASK_DISABLESOURCE
#define EIP201_REMOVE_SOURCEMASK_SOURCEISENABLED
#define EIP201_REMOVE_SOURCEMASK_READALL
#define EIP201_REMOVE_SOURCESTATUS_ISENABLEDSOURCEPENDING
#define EIP201_REMOVE_SOURCESTATUS_ISRAWSOURCEPENDING
//#define EIP201_REMOVE_SOURCESTATUS_READALLENABLED
#define EIP201_REMOVE_SOURCESTATUS_READALLRAW
//#define EIP201_REMOVE_INITIALIZE
//#define EIP201_REMOVE_ACKNOWLEDGE

#ifdef DRIVER_POLLING
// disable all functions
#define EIP201_REMOVE_CONFIG_CHANGE
#define EIP201_REMOVE_CONFIG_READ
#define EIP201_REMOVE_SOURCEMASK_ENABLESOURCE
#define EIP201_REMOVE_SOURCEMASK_DISABLESOURCE
#define EIP201_REMOVE_SOURCEMASK_SOURCEISENABLED
#define EIP201_REMOVE_SOURCEMASK_READALL
#define EIP201_REMOVE_SOURCESTATUS_ISENABLEDSOURCEPENDING
#define EIP201_REMOVE_SOURCESTATUS_ISRAWSOURCEPENDING
#define EIP201_REMOVE_SOURCESTATUS_READALLENABLED
#define EIP201_REMOVE_SOURCESTATUS_READALLRAW
#define EIP201_REMOVE_INITIALIZE
#define EIP201_REMOVE_ACKNOWLEDGE
#endif /* DRIVER_POLLING */

/* end of file cs_eip201.h */
