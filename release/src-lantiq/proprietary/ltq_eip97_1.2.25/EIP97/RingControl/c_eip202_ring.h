/* c_eip202_ring.h
 *
 * Default configuration of the EIP-202 Ring Control Driver Library
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
* In case you do not have an account for this system, please send an e-mail
* to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef C_EIP202_RING_H_
#define C_EIP202_RING_H_

/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */

// Top-level configuration, can override default configuration
// parameters specified in this file
#include "cs_eip202_ring.h"


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Set to 1 to enable RDR interrupt generation per packet
// instead of interrupt generation per result descriptor
#ifndef EIP202_RING_RD_INTERRUPTS_PER_PACKET_FLAG
#define EIP202_RING_RD_INTERRUPTS_PER_PACKET_FLAG  1
#endif

// Enables the 64-bit DMA addresses support in the device
//#define EIP202_64BIT_DEVICE

// Enable anti DMA race condition CDS mechanism.
// When enabled the Application ID field in the descriptors cannot be used
// by the Ring Control Driver Library users.
//#define EIP202_RING_ANTI_DMA_RACE_CONDITION_CDS

// Disable clustered write operations, e.g. every write operation to
// an EIP-202 RD register will be followed by one read operation to
// a pre-defined EIP-202 register
//#define EIP202_CLUSTERED_WRITES_DISABLE

// Strict argument checking for the input parameters
// If required then define this parameter in the top-level configuration
//#define EIP202_RING_STRICT_ARGS

// Finite State Machine that can be used for verifying that the Driver Library
// API is called in a correct order
//#define EIP202_RING_DEBUG_FSM

// Define if the hardware uses extended command and result descriptors.
//#define EIP202_USE_EXTENDED_DESCRIPTOR


#endif /* C_EIP202_RING_H_ */


/* end of file c_eip202_ring.h */
