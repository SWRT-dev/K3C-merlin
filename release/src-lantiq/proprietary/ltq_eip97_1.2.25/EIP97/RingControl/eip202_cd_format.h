/* eip202_cd_format.h
 *
 * EIP-202 Ring Control Driver Library Command Descriptor Internal interface
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

#ifndef EIP202_CD_FORMAT_H_
#define EIP202_CD_FORMAT_H_


/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */

// Descriptor I/O Driver Library API implementation
#include "eip202_cdr.h"                // EIP202_ARM_CommandDescriptor_t


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"                // bool, uint32_t, uint8_t

// Driver Framework DMA Resource API
#include "dmares_types.h"              // DMAResource_Handle_t


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// This is valid for ATP mode only
#define EIP202_CD_MAX_WORD_COUNT    EIP202_CDR_DSCR_MAX_WORD_COUNT


/*----------------------------------------------------------------------------
 * Local variables
 */


/*----------------------------------------------------------------------------
 * EIP202_CD_Make_ControlWord
 *
 * This helper function returns the Control Word that can be written to
 * the EIP-202 Command Descriptor.
 *
 * This function is re-entrant.
 *
 */
uint32_t
EIP202_CD_Make_ControlWord(
        const uint8_t TokenWordCount,
        const uint32_t SegmentByteCount,
        const bool fFirstSegment,
        const bool fLastSegment);


/*----------------------------------------------------------------------------
 * EIP202_CD_Write
 *
 * This helper function writes the EIP-202 Logical Command Descriptor to the CDR
 *
 * This function is not re-entrant.
 *
 */
void
EIP202_CD_Write(
        DMAResource_Handle_t Handle,
        const unsigned int WordOffset,
        const EIP202_ARM_CommandDescriptor_t * const Descr_p);


#endif /* EIP202_CD_FORMAT_H_ */


/* end of file eip202_cd_format.h */
