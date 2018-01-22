/* clib.h
 *
 * Driver Framework v4, C Library Abstraction
 *
 * This header function guarantees the availability of a select list of
 * Standard C APIs. This makes the user of this API compiler independent.
 * It also gives a single customization point for these functions.
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

#ifndef INCLUDE_GUARD_CLIB_H
#define INCLUDE_GUARD_CLIB_H

/* guaranteed APIs:

    memcpy
    memmove
    memset
    memcmp
    offsetof
    strcmp

*/

/* Note: This is a template. Copy and customize according to your needs! */

#if 1
//#if defined(linux) && defined(MODULE)

#include <linux/string.h>     // memmove, memcpy, memset, strcmp
#include <linux/stddef.h>     // offsetof

#else

#include <string.h>           // memmove, memset, strcmp
#include <memory.h>           // memcpy, etc.
#include <stddef.h>           // offsetof

#endif


/* Zero-init macro
 *
 *   _x (input)
 *              Name of the variable that must be zeroed
 *
 */
#define ZEROINIT(_x)  memset(&_x, 0, sizeof(_x))


#endif /* Inclusion Guard */


/* end of file clib.h */
