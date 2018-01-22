/* adapter_ring_eip202.h
 *
 * Interface to EIP-202 ring-specific functionality.
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

#ifndef ADAPTER_RING_EIP202_H_
#define ADAPTER_RING_EIP202_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // bool


/*----------------------------------------------------------------------------
 * Adapter_Ring_EIP202_Configure
 *
 * This routine configures the SafeXcel-IP-202 ring-specific functionality
 * with parameters that are obtained via the Global Control
 * interface.
 *
 * HostDataWidth (input)
 *         Host interface data width:
 *              0 = 32 bits, 1 = 64 bits, 2 = 128 bits, 3 = 256 bits
 *
 * CF_Size (input)
 *         Command Descriptor FIFO size, the actual size is 2^CF_Size 32-bit
 *         words.
 *
 * RF_Size (input)
 *         Result Descriptor FIFO size, the actual size is 2^RF_Size 32-bit
 *         words.
 *
 * This function is re-entrant.
 */
void
Adapter_Ring_EIP202_Configure(
        const uint8_t HostDataWidth,
        const uint8_t CF_Size,
        const uint8_t RF_Size);


#endif /* ADAPTER_RING_EIP202_H_ */


/* end of file adapter_ring_eip202.h */
