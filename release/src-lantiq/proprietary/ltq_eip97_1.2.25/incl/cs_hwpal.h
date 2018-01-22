/* cs_hwpal.h
 *
 * Configuration Settings for Driver Framework Implementation
 * for the SafeXcel-IP-97 Driver.
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

#ifndef INCLUDE_GUARD_CS_HWPAL_H
#define INCLUDE_GUARD_CS_HWPAL_H

// we accept a few settings from the top-level configuration file
#include "cs_driver.h"
#include "cs_adapter.h"

// Host hardware platform specific extensions
#include "cs_hwpal_ext.h"

// Engine specific extensions
#include "cs_hwpal_ext2.h"


// logging level for HWPAL Device
// Choose from LOG_SEVERITY_INFO, LOG_SEVERITY_WARN, LOG_SEVERITY_CRIT
#undef LOG_SEVERITY_MAX
#ifdef DRIVER_PERFORMANCE
#define HWPAL_LOG_SEVERITY  LOG_SEVERITY_CRITICAL
#else // DRIVER_PERFORMANCE
//#define HWPAL_LOG_SEVERITY  LOG_SEVERITY_NO_OUTPUT
#define HWPAL_LOG_SEVERITY LOG_SEVERITY_INFO
#endif // DRIVER_PERFORMANCE

// maximum allowed length for a device name
#define HWPAL_MAX_DEVICE_NAME_LENGTH 64

#define HWPAL_DEVICE_MAGIC   54333

#ifdef DRIVER_NAME
#define HWPAL_DRIVER_NAME DRIVER_NAME
#endif

// Trace memory leaks for DMAResource API implementation
#define HWPAL_TRACE_DMARESOURCE_LEAKS

// Is host platform 64-bit?
#ifdef DRIVER_64BIT_HOST
#define HWPAL_64BIT_HOST
// Is device 64-bit? Only makes sense on 64-bit host.
#ifdef DRIVER_64BIT_DEVICE
#define HWPAL_DMARESOURCE_64BIT
#endif  // DRIVER_64BIT_DEVICE
#endif  // DRIVER_64BIT_HOST

// only define this if the platform hardware guarantees cache coherence of
// DMA buffers, i.e. when SW does not need to do coherence management.
#ifdef ARCH_X86
#define HWPAL_ARCH_COHERENT
#else
#undef HWPAL_ARCH_COHERENT
#endif

// Logging / tracing control
#ifndef DRIVER_PERFORMANCE
#define HWPAL_STRICT_ARGS_CHECK
#ifdef ARCH_X86
// Enabled for DMAResource API implementation on x86 debugging purposes only
#undef HWPAL_ARCH_COHERENT
#endif
#define HWPAL_TRACE_DEVICE_FIND
#define HWPAL_TRACE_DEVICE_READ
#define HWPAL_TRACE_DEVICE_WRITE
#define HWPAL_TRACE_DMARESOURCE_WRITE
#define HWPAL_TRACE_DMARESOURCE_READ
#define HWPAL_TRACE_DMARESOURCE_PREPOSTDMA
#define HWPAL_TRACE_DMARESOURCE_BUF
#endif

// Use sleepable or non-sleepable lock ?
//#define HWPAL_LOCK_SLEEPABLE

#define HWPAL_DMA_NRESOURCES     ADAPTER_MAX_DMARESOURCE_HANDLES

// Use direct I/O bypassing the OS functions,
// I/O device must swap bytes in words
#ifdef DRIVER_ENABLE_SWAP_SLAVE
#define HWPAL_DEVICE_DIRECT_MEMIO
#endif

// Enable use of UMDevXS and SHDevXS API's
// Note: This parameter must be used for the Driver PEC or PEC-PCL build!
//#ifdef DRIVER_USE_SHDEVXS_PCI_DEVICE
//#define HWPAL_USE_UMDEVXS_PCI_DEVICE
//#endif


#endif // INCLUDE_GUARD_CS_HWPAL_H


/* end of file cs_hwpal.h */
