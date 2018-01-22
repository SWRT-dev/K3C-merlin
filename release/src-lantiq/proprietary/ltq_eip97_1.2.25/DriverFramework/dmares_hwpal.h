/* dmares_hwpal.h
 *
 * HW and OS abstraction API
 * for the Driver Framework DMAResource API implementation
 *
 */

/*****************************************************************************
* Copyright (c) 2012-2013 INSIDE Secure B.V. All Rights Reserved.
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

#ifndef DMARES_HWPAL_H_
#define DMARES_HWPAL_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework DMAResource Types API
#include "dmares_types.h"

// Driver Framework C Library abstraction APi
#include "clib.h"


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_MaxAlignment_Get
 */
unsigned int
HWPAL_DMAResource_MaxAlignment_Get(void);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_DCache_Alignment_Get
 */
unsigned int
HWPAL_DMAResource_DCache_Alignment_Get(void);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_MemAlloc
 */
void *
HWPAL_DMAResource_MemAlloc(
        size_t ByteCount);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_MemFree
 */
void
HWPAL_DMAResource_MemFree(
        void * Buf_p);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Lock_Alloc
 */
void *
HWPAL_DMAResource_Lock_Alloc(void);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Lock_Free
 */
void
HWPAL_DMAResource_Lock_Free(void * Lock_p);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Lock_Acquire
 */
void
HWPAL_DMAResource_Lock_Acquire(
        void * Lock_p,
        unsigned long * Flags);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Lock_Release
 */
void
HWPAL_DMAResource_Lock_Release(
        void * Lock_p,
        unsigned long * Flags);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Alloc
 */
int
HWPAL_DMAResource_Alloc(
        const DMAResource_Properties_t RequestedProperties,
        DMAResource_AddrPair_t * const AddrPair_p,
        DMAResource_Handle_t * const Handle_p);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Release
 */
int
HWPAL_DMAResource_Release(
        const DMAResource_Handle_t Handle);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Init
 */
bool
HWPAL_DMAResource_Init(void);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_UnInit
 */
void
HWPAL_DMAResource_UnInit(void);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_CheckAndRegister
 */
int
HWPAL_DMAResource_CheckAndRegister(
        const DMAResource_Properties_t RequestedProperties,
        const DMAResource_AddrPair_t AddrPair,
        const char AllocatorRef,
        DMAResource_Handle_t * const Handle_p);


/*----------------------------------------------------------------------------
 * HWPAL_DMAResource_Record_Update
 */
int
HWPAL_DMAResource_Record_Update(
        const int Identifier,
        DMAResource_Record_t * const Rec_p);


#endif // DMARES_HWPAL_H_


/* end of file dmares_hwpal.h */
