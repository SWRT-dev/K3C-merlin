/* cs_hwpal_lkm.h
 *
 * Configuration Settings for Driver Framework Implementation for
 * Linux kernel-space.
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

#ifndef INCLUDE_GUARD_CS_HWPAL_LKM_H
#define INCLUDE_GUARD_CS_HWPAL_LKM_H

// we accept a few settings from the top-level configuration file
#include "cs_hwpal.h"

// Enable cache-coherent DMA buffer allocation
//#define HWPAL_DMARESOURCE_ALLOC_CACHE_COHERENT

// Use minimum required cache-control functionality for DMA-safe buffers
//#define HWPAL_DMARESOURCE_MINIMUM_CACHE_CONTROL

#if defined(DRIVER_SWAPENDIAN) && defined(DRIVER_ENABLE_SWAP_SLAVE)
#define HWPAL_DEVICE_ENABLE_SWAP
#endif // DRIVER_SWAPENDIAN

#endif // INCLUDE_GUARD_CS_HWPAL_LKM_H


/* end of file cs_hwpal_lkm.h */
