/* adapter_lock_ext.h
 *
 * Adapter concurrency (locking) management
 * extensions for Linux kernel-space
 *
 */

/*****************************************************************************
* Copyright (c) 2013 INSIDE Secure B.V. All Rights Reserved.
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

#ifndef INCLUDE_GUARD_ADAPTER_LOCK_EXT_H
#define INCLUDE_GUARD_ADAPTER_LOCK_EXT_H

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Linux Kernel API
#include <linux/spinlock.h>     // spinlock_*


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


#define ADAPTER_LOCK_DEFINE(Lock)   DEFINE_SPINLOCK(Lock)


#endif // INCLUDE_GUARD_ADAPTER_LOCK_EXT_H


/* end of file adapter_lock_ext.h */
