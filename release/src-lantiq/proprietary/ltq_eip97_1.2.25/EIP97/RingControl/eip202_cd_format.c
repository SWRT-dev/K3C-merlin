/* eip202_cd_format.c
 *
 * EIP-202 Ring Control Driver Library
 * Command Descriptor Internal interface
 *
 * This module contains the EIP-202 Command Descriptor specific functionality
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

/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */

#include "eip202_cd_format.h"

// Descriptor I/O Driver Library API implementation
#include "eip202_cdr.h"                 // EIP202_ARM_CommandDescriptor_t


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Default configuration
#include "c_eip202_ring.h"

// EIP-202 Ring Control Driver Library Internal interfaces
#include "eip202_ring_internal.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"                // bool, uint32_t, uint8_t

// Driver Framework DMA Resource API
#include "dmares_types.h"              // DMAResource_Handle_t
#include "dmares_rw.h"                 // DMAResource_Write/Read


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


/*----------------------------------------------------------------------------
 * Local variables
 */


/*----------------------------------------------------------------------------
 * EIP202_CD_Make_ControlWord
 */
uint32_t
EIP202_CD_Make_ControlWord(
        const uint8_t TokenWordCount,
        const uint32_t SegmentByteCount,
        const bool fFirstSegment,
        const bool fLastSegment)
{
    uint32_t Value = 0;

    if(fFirstSegment)
        Value |= BIT_23;

    if(fLastSegment)
        Value |= BIT_22;

    Value |= ((((uint32_t)TokenWordCount) & MASK_8_BITS) << 24);
    Value |= ((((uint32_t)SegmentByteCount) & MASK_20_BITS));

    return Value;
}


/*----------------------------------------------------------------------------
 * EIP202_CD_Write
 */
void
EIP202_CD_Write(
        DMAResource_Handle_t Handle,
        const unsigned int WordOffset,
        const EIP202_ARM_CommandDescriptor_t * const Descr_p)

{
#ifdef EIP202_64BIT_DEVICE
    // Write Control Word
    DMAResource_Write32(Handle, WordOffset, Descr_p->ControlWord);

    // Lengths greater than 20 bits not supported yet.
    DMAResource_Write32(Handle, WordOffset + 1, 0);

    // Write Source Packet Data address
    DMAResource_Write32(Handle, WordOffset + 2, Descr_p->SrcPacketAddr.Addr);
    DMAResource_Write32(Handle, WordOffset + 3, Descr_p->SrcPacketAddr.UpperAddr);

    // Write Token Data address
    DMAResource_Write32(Handle, WordOffset + 4, Descr_p->TokenDataAddr.Addr);
    DMAResource_Write32(Handle, WordOffset + 5, Descr_p->TokenDataAddr.UpperAddr);


    // Write Token Header
    DMAResource_Write32(Handle, WordOffset + 6, Descr_p->TokenHeader);

   // Write Application ID
#ifdef EIP202_RING_ANTI_DMA_RACE_CONDITION_CDS
    DMAResource_Write32(Handle, WordOffset + 7, EIP202_DSCR_DONE_PATTERN);
#else
    DMAResource_Write32(Handle, WordOffset + 7, Descr_p->ApplicationId);
#endif // EIP202_RING_ANTI_DMA_RACE_CONDITION_CDS

    DMAResource_Write32(Handle, WordOffset + 8, Descr_p->ContextDataAddr.Addr);
    DMAResource_Write32(Handle, WordOffset + 9, Descr_p->ContextDataAddr.UpperAddr);
#ifdef EIP202_USE_EXTENDED_DESCRIPTOR
    DMAResource_Write32(Handle, WordOffset + 10, Descr_p->Control2);
    DMAResource_Write32(Handle, WordOffset + 11, Descr_p->Control3);
#else

#endif

#else
    // Write Control Word
    DMAResource_Write32(Handle, WordOffset, Descr_p->ControlWord);

    // Write Source Packet Data address
    DMAResource_Write32(Handle, WordOffset + 1, Descr_p->SrcPacketAddr.Addr);

    // Write Token Data address
    DMAResource_Write32(Handle, WordOffset + 2, Descr_p->TokenDataAddr.Addr);

    // Write Token Header
    DMAResource_Write32(Handle, WordOffset + 3, Descr_p->TokenHeader);

   // Write Application ID
#ifdef EIP202_RING_ANTI_DMA_RACE_CONDITION_CDS
    DMAResource_Write32(Handle, WordOffset + 4, EIP202_DSCR_DONE_PATTERN);
#else
    DMAResource_Write32(Handle, WordOffset + 4, Descr_p->ApplicationId);
#endif // EIP202_RING_ANTI_DMA_RACE_CONDITION_CDS

#ifdef EIP202_USE_EXTENDED_DESCRIPTOR
    DMAResource_Write32(Handle, WordOffset + 5, Descr_p->ContextDataAddr.Addr);
    DMAResource_Write32(Handle, WordOffset + 6, Descr_p->ContextDataAddr.UpperAddr);
    DMAResource_Write32(Handle, WordOffset + 7, Descr_p->Control2);
    DMAResource_Write32(Handle, WordOffset + 8, Descr_p->Control3);
#else

    // Write Context Data address
    DMAResource_Write32(Handle, WordOffset + 5, Descr_p->ContextDataAddr.Addr);
#endif

#endif

    return;
}


/* end of file eip202_cd_format.c */
