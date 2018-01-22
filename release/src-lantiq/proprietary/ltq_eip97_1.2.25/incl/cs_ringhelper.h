/* cs_ringhelper.h
 *
 * Ring Helper Configuration File
 */

/*****************************************************************************
* Copyright (c) 2010-2013 INSIDE Secure B.V. All Rights Reserved.
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
* In case you do not have an account for
* this system, please send an e-mail to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef INCLUDE_GUARD_CS_RINGHELPER_H
#define INCLUDE_GUARD_CS_RINGHELPER_H

#include "cs_driver.h"

// when enabled, all function call parameters are sanity-checked
// comment-out to disable this code
#ifndef DRIVER_PERFORMANCE
#define RINGHELPER_STRICT_ARGS
#endif

// the following switch removes support for the Status Callback Function
//#define RINGHELPER_REMOVE_STATUSFUNC

// the following switch removes support for separate rings
// use when only overlapping rings are used
//#define RINGHELPER_REMOVE_SEPARATE_RING_SUPPORT


#endif /* Include Guard */


/* end of file cs_ringhelper.h */
