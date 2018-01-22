/* adapter_lock.h
 *
 * Adapter concurrency (locking) management
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

#ifndef INCLUDE_GUARD_ADAPTER_LOCK_H
#define INCLUDE_GUARD_ADAPTER_LOCK_H

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // bool


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Lock, use Adapter_Lock_NULL to set to a known uninitialized value
typedef void * Adapter_Lock_t;

// Critical section
typedef struct
{
    volatile void * p [2]; // Place holder

} Adapter_Lock_CS_t;


/*----------------------------------------------------------------------------
 * Adapter_Lock_t
 *
 * This handle can be assigned to a variable of type Adapter_Lock_t.
 *
 */
extern const Adapter_Lock_t Adapter_Lock_NULL;


/*----------------------------------------------------------------------------
 * Adapter_Lock_Alloc
 */
Adapter_Lock_t
Adapter_Lock_Alloc(void);


/*----------------------------------------------------------------------------
 * Adapter_Lock_Free
 */
void
Adapter_Lock_Free(
        Adapter_Lock_t Lock);


/*----------------------------------------------------------------------------
 * Adapter_Lock_Acquire
 */
void
Adapter_Lock_Acquire(
        Adapter_Lock_t Lock,
        unsigned long * Flags);


/*----------------------------------------------------------------------------
 * Adapter_Lock_Release
 */
void
Adapter_Lock_Release(
        Adapter_Lock_t Lock,
        unsigned long * Flags);


/*----------------------------------------------------------------------------
 * Adapter_Lock_CS_Set
 *
 * Set the lock for the critical section.
 *
 * Note: This function must be called prior to calling Adapter_Lock_CS_Enter()
 *       or Adapter_Lock_CS_Leave() functions.
 *       The lock cannot be changes while the critical section is entered.
 *
 * CS_p (output):
 *      Critical section where the Lock data must be set.
 *
 * Lock (input):
 *      Pointer to a lock instantiated by the ADAPTER_LOCK_DEFINE macro or
 *      allocated by Adapter_Lock_Alloc() function
 *
 */
void
Adapter_Lock_CS_Set(
        Adapter_Lock_CS_t * const CS_p,
        Adapter_Lock_t Lock);


/*----------------------------------------------------------------------------
 * Adapter_Lock_CS_Get
 *
 * Get the lock for the critical section.
 *
 * CS_p (input):
 *      Critical section for which the Lock object must be obtained.
 *
 */
Adapter_Lock_t
Adapter_Lock_CS_Get(
        Adapter_Lock_CS_t * const CS_p);


/*----------------------------------------------------------------------------
 * Adapter_Lock_CS_Enter
 *
 * Although the critical section is left there can be
 * only one execution context executing the code before the matching call
 * for the same Lock_p parameter to Adapter_Lock_CS_Leave at a time
 *
 * Return code:
 *      true - section entered
 *      false - section not entered, another context is already executing it
 *
 */
bool
Adapter_Lock_CS_Enter(
        Adapter_Lock_CS_t * const CS_p);


/*----------------------------------------------------------------------------
 * Adapter_Lock_CS_Leave
 */
void
Adapter_Lock_CS_Leave(
        Adapter_Lock_CS_t * const CS_p);


// Adapter Locking API extensions
#include "adapter_lock_ext.h"           // ADAPTER_LOCK_DEFINE


#endif // INCLUDE_GUARD_ADAPTER_LOCK_H


/* end of file adapter_lock.h */
