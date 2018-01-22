/* cs_eip97_global.h
 *
 * Top-level configuration parameters
 * for the EIP-97 Global Control Driver Library
 *
 */

/*****************************************************************************
* Copyright (c) 2011-2013 INSIDE Secure B.V. All Rights Reserved.
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

#ifndef CS_EIP97_GLOBAL_H_
#define CS_EIP97_GLOBAL_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */
#include "cs_driver.h"

/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Number of Processing Engines to use
// Maximum number of processing that should be used
// Should not exceed the number of engines physically available
#ifdef DRIVER_MAX_NOF_PE_TO_USE
#define EIP97_GLOBAL_MAX_NOF_PE_TO_USE       DRIVER_MAX_NOF_PE_TO_USE
#endif

// Number of Ring interfaces
// Maximum number of Ring interfaces that should be used
// Should not exceed the number of rings physically available
#ifdef DRIVER_MAX_NOF_RING_TO_USE
#define EIP97_GLOBAL_MAX_NOF_RING_TO_USE     DRIVER_MAX_NOF_RING_TO_USE
#endif

#ifdef DRIVER_ENABLE_SWAP_SLAVE
#define EIP97_GLOBAL_ENABLE_SWAP_REG_DATA
#endif

#if defined(EIP97_BUS_VERSION_AXI3)
// For AXI v3
#define EIP97_GLOBAL_BUS_BURST_SIZE          8
#elif defined(EIP97_BUS_VERSION_AXI4)
// For AXI v4
#define EIP97_GLOBAL_BUS_BURST_SIZE          4
#elif defined(EIP97_BUS_VERSION_PLB)
// For PLB
#define EIP97_GLOBAL_BUS_BURST_SIZE          7
#else
#error "Error: EIP97_BUS_VERSION_[PLB|AXI3|AXI4] not configured"
#endif

#ifdef DRIVER_ENABLE_SWAP_MASTER
// Enable Flow Lookup Data Endianness Conversion
// by the Classification Engine hardware master interface
#define EIP97_GLOBAL_BYTE_SWAP_FLUE_DATA

// Enable Flow Record Data Endianness Conversion
// by the Classification Engine hardware master interface
#define EIP97_GLOBAL_BYTE_SWAP_FLOW_DATA

// Enable Context Data Endianness Conversion
// by the Processing Engine hardware master interface
#define EIP97_GLOBAL_BYTE_SWAP_CONTEXT_DATA

// Enable ARC4 Context Data Endianness Conversion
// by the PE hardware master interface
#define EIP97_GLOBAL_BYTE_SWAP_ARC4_CONTEXT_DATA

// One or several of the following methods must be configured:
// Swap bytes within each 32 bit word
#define EIP97_GLOBAL_BYTE_SWAP_METHOD_32
// Swap 32 bit chunks within each 64 bit chunk
//#define EIP97_GLOBAL_BYTE_SWAP_METHOD_64
// Swap 64 bit chunks within each 128 bit chunk
//#define EIP97_GLOBAL_BYTE_SWAP_METHOD_128
// Swap 128 bit chunks within each 256 bit chunk
//#define EIP97_GLOBAL_BYTE_SWAP_METHOD_256
#endif

// Packet Engine hold output data.
// This parameter can be used for the in-place packet transformations when
// the transformed result packet is larger than the original packet.
// In-place means that the same packet buffer is used to store the original
// as well as the transformed packet data.
// This value of this parameter defines the number of last the 8-byte blocks
// that the packet engine will hold in its internal result packet buffer
// until the packet processing is completed.
#ifdef DRIVER_PE_HOLD_OUTPUT_DATA
#define EIP97_GLOBAL_EIP96_PE_HOLD_OUTPUT_DATA      \
                                DRIVER_PE_HOLD_OUTPUT_DATA
#endif // EIP97_GLOBAL_EIP96_PE_HOLD_OUTPUT_DATA

// Strict argument checking for the input parameters
// If required then define this parameter in the top-level configuration
#define EIP97_GLOBAL_STRICT_ARGS

// Finite State Machine that can be used for verifying that the Driver Library
// API is called in a correct order
#define EIP97_GLOBAL_DEBUG_FSM

// Configuration parameter extensions
#include "cs_eip97_global_ext.h"


#endif /* CS_EIP97_GLOBAL_H_ */


/* end of file cs_eip97_global.h */
