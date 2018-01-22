/* adapter_addrpair.h
 *
 * Convert an address (pointer) to a pair of 32-bit words.
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

#ifndef ADAPTER_ADDDRPAIR_H_
#define ADAPTER_ADDRPAIR_H_

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

#include "basic_defs.h" // Type definitions uint32_t.

/*----------------------------------------------------------------------------
 * Adapter_AddrToWordPair
 *
 * Convert address (void *) to a pair of 32-bit words.
 *
 * Address_p (input)
 *     The address to be converted.
 * Offset (input)
 *     Integer offset to be added to the address.
 * WordLow_p (output)
 *     Least significant address word.
 * WordHigh_p (output)
 *     Most significant address word.
 */
static inline void
Adapter_AddrToWordPair(
    const void *Address_p,
    const int Offset,
    uint32_t *WordLow_p,
    uint32_t *WordHigh_p)
{
#ifdef ADAPTER_64BIT_HOST
    uint64_t IntAddr;
    IntAddr = (uint64_t)Address_p + Offset;
    *WordLow_p = IntAddr & 0xFFFFFFFF;
    *WordHigh_p = IntAddr >> 32;
#else
    *WordLow_p = (uint32_t)Address_p + Offset;
    *WordHigh_p = 0;
#endif
}


#endif /* ADAPTER_ADDRPAIR_H */


/* end of file adapter_addrpair.h */
