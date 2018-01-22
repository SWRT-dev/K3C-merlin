/* adapter_lock_internal.h
 *
 * Adapter concurrency (locking) management
 * Internal interface
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

#ifndef INCLUDE_GUARD_ADAPTER_LOCK_INTERNAL_H
#define INCLUDE_GUARD_ADAPTER_LOCK_INTERNAL_H


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // bool


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Internal critical section data structure
typedef struct
{
    // Generic lock pointer
    void * Lock_p;

    // True if the lock is taken
    volatile bool fLocked;

} Adapter_Lock_CS_Internal_t;


#endif // INCLUDE_GUARD_ADAPTER_LOCK_INTERNAL_H


/* end of file adapter_lock_internal.h */
