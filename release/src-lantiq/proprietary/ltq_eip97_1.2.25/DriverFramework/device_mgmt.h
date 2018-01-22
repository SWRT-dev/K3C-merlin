/* device_mgmt.h
 *
 * Driver Framework, Device API, Management functions
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

#ifndef INCLUDE_GUARD_DEVICE_MGMT_H
#define INCLUDE_GUARD_DEVICE_MGMT_H

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Device API API
#include "device_types.h"   // Device_Handle_t, Device_Reference_t

// Driver Framework Basic Definitions API
#include "basic_defs.h"     // bool, uint32_t, inline


/*----------------------------------------------------------------------------
 * Device_Initialize
 *
 * This function must be called exactly once to initialize the Device
 * implementation before any other API function may be used.
 *
 * CustomInitData_p
 *     This anonymous parameter can be used to pass information from the caller
 *     to the driver framework implementation.
 *
 * Return Value
 *     0    Success
 *     <0   Error code (implementation specific)
 */
int
Device_Initialize(
        void * CustomInitData_p);


/*----------------------------------------------------------------------------
 * Device_UnInitialize
 *
 * This function can be called to shut down the Device implementation. The
 * caller must make sure none of the other API functions are called after or
 * during the invocation of this UnInitialize function. After this call
 * returns the API state is back in "uninitialized" and the Device_Initialize
 * function may be called anew.
 *
 * Return Value
 *     None
 */
void
Device_UnInitialize(void);


/*----------------------------------------------------------------------------
 * Device_Find
 *
 * This function must be used to retrieve a handle for a certain device that
 * is identified by a string. The exact strings supported is implementation
 * specific and will differ from product to product.
 * Note that this function may be called more than once to retrieve the same
 * handle for the same device.
 *
 * DeviceName_p (input)
 *     Pointer to the (zero-terminated) string that represents the device.
 *
 * Return Value
 *     NULL    No device found with requested
 *     !NULL   Device handle that can be used in the Device API
 */
Device_Handle_t
Device_Find(
        const char * szDeviceName_p);


/*-----------------------------------------------------------------------------
 * Device_GetReference
 *
 * This function can be used to obtain the implementation-specific device
 * reference
 *
 * Device (input)
 *     Handle for the device instance as returned by Device_Find for which
 *     the reference must be obtained.
 *
 * Return Value
 *     NULL    No reference found for the requested device instance
 *     !NULL   Device reference
 */
Device_Reference_t
Device_GetReference(
        const Device_Handle_t Device);


#endif /* Include Guard */

/* end of file device_mgmt.h */
