/* dmares_mgmt.h
 *
 * Driver Framework, DMAResource API, Management functions
 *
 * The document "Driver Framework Porting Guide" contains the detailed
 * specification of this API. The information contained in this header file
 * is for reference only.
 */

/*****************************************************************************
* Copyright (c) 2007-2013 INSIDE Secure B.V. All Rights Reserved.
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

#ifndef INCLUDE_GUARD_DMARES_MGMT_H
#define INCLUDE_GUARD_DMARES_MGMT_H

#include "basic_defs.h"         // bool, uint32_t, inline
#include "dmares_types.h"       // DMAResource_Handle/Record/AddrPair_t


/*****************************************************************************
 * DMA Resource API
 *
 * This API is related to management of memory buffers that can be accessed by
 * the host as well as a device, using Direct Memory Access (DMA). A driver
 * must typically support many of these shared resources. This API helps with
 * administration of these resources.
 *
 * This API maintains administration records that the caller can read and
 * write directly. A handle is also provided to abstract the record.
 * The handle cannot be used to directly access the resource and is therefore
 * considered safe to pass around in the system, even to applications.
 *
 * Another important aspect of this API is to provide a point where resources
 * can be handed over between the host and the device. The driver library or
 * adapter must call the PreDMA and PostDMA functions to indicate the hand over
 * of access right between the host and the device for an entire resource, or
 * part thereof. The implementation can use these calls to manage the
 * data coherence for the resource, for example in a cached system.
 *
 * Dynamic DMA resources such as DMA-safe buffers covered by this API
 * are different from static Device resources (see the Device API)
 * which represent device-internal resources with possible read and write
 * side-effects.
 *
 * On the fly endianess conversion (byte swap) for integers is supported for
 * DMA resources by means of the Read32 and Write32 functions.
 *
 * Note: If multiple devices with a different memory view need to use the same
 * DMA resource, then the caller should consider separate records for each
 * device (for the same buffer).
 */


/*----------------------------------------------------------------------------
 * DMAResource_Init
 *
 * This function must be used to initialize the DMAResource administration.
 * It must be called before any of the other DMAResource_* functions may be
 * called. It may be called anew only after DMAResource_UnInit has been called.
 *
 * Return Value
 *     true   Initialization successfully, rest of the API may now be used.
 *     false  Initialization failed.
 */
bool
DMAResource_Init(void);


/*----------------------------------------------------------------------------
 * DMAResource_UnInit
 *
 * This function can be used to uninitialize the DMAResource administration.
 * The caller must make sure that handles will not be used after this function
 * returns.
 * If memory was allocated by DMAResource_Init, this function will free it.
 */
void
DMAResource_UnInit(void);


/*----------------------------------------------------------------------------
 * DMAResource_CreateRecord
 *
 * This function can be used to create a record. The function returns a handle
 * for the record. Use DMAResource_Handle2RecordPtr to access the record.
 * Destroy the record when no longer required, see DMAResource_Destroy.
 * This function initializes the record to all zeros.
 *
 * Return Values
 *     Handle for the DMA Resource.
 *     NULL is returned when the creation failed.
 */
DMAResource_Handle_t
DMAResource_CreateRecord(void);


/*----------------------------------------------------------------------------
 * DMAResource_DestroyRecord
 *
 * This function invalidates the handle and the record instance.
 *
 * Handle
 *     A valid handle that was once returned by DMAResource_CreateRecord or
 *     one of the DMA Buffer Management functions (DMAResource_Alloc /
 *     DMAResource_CheckAndRegister / DMAResource_Attach).
 *
 * Return Values
 *     None
 */
void
DMAResource_DestroyRecord(
        const DMAResource_Handle_t Handle);


/*----------------------------------------------------------------------------
 * DMAResource_IsValidHandle
 *
 * This function tells whether a handle is valid.
 *
 * Handle
 *     A valid handle that was once returned by DMAResource_CreateRecord or
 *     one of the DMA Buffer Management functions (DMAResource_Alloc /
 *     DMAResource_CheckAndRegister / DMAResource_Attach).
 *
 * Return Value
 *     true   The handle is valid
 *     false  The handle is NOT valid
 */
bool
DMAResource_IsValidHandle(
        const DMAResource_Handle_t Handle);


/*----------------------------------------------------------------------------
 * DMAResource_Handle2RecordPtr
 *
 * This function can be used to get a pointer to the DMA resource record
 * (DMAResource_Record_t) for the provided handle. The pointer is valid until
 * the record and handle are destroyed.
 *
 * Handle
 *     A valid handle that was once returned by DMAResource_CreateRecord or
 *     one of the DMA Buffer Management functions (DMAResource_Alloc /
 *     DMAResource_CheckAndRegister / DMAResource_Attach).
 *
 * Return Value
 *     Pointer to the DMAResource_Record_t memory for this handle.
 *     NULL is returned if the handle is invalid.
 */
DMAResource_Record_t *
DMAResource_Handle2RecordPtr(
        const DMAResource_Handle_t Handle);


#endif /* Include Guard */

/* end of file dmares_mgmt.h */
