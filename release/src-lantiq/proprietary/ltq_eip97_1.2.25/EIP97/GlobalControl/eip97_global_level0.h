/* eip97_global_level0.h
 *
 * EIP-97 Global Control Level0 Internal interface
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

#ifndef EIP97_GLOBAL_LEVEL0_H_
#define EIP97_GLOBAL_LEVEL0_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Default configuration
#include "c_eip97_global.h"     // EIP97_RC_BASE, EIP97_BASE

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // BIT definitions, bool, uint32_t

// Driver Framework Device API
#include "device_types.h"       // Device_Handle_t
#include "device_rw.h"          // Read32, Write32


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Read/Write register constants

// Byte offsets of the EIP-97 Engine registers

// EIP-97 Engine EIP number (0x61) and complement (0x9E)
#define EIP97_SIGNATURE    ((uint16_t)0x9E61)

#define EIP97_REG_OFFS     4

#define EIP97_REG_CS_DMA_CTRL2  ((EIP97_RC_BASE)+(0x01 * EIP97_REG_OFFS))

#define EIP97_REG_MST_CTRL ((EIP97_BASE)+(0x00 * EIP97_REG_OFFS))
#define EIP97_REG_OPTIONS  ((EIP97_BASE)+(0x01 * EIP97_REG_OFFS))
#define EIP97_REG_VERSION  ((EIP97_BASE)+(0x02 * EIP97_REG_OFFS))

#define EIP97_REG_MST_CTRL_DEFAULT      0x00000010
#define EIP97_REG_CS_DMA_CTRL2_DEFAULT  0x00000000


/*----------------------------------------------------------------------------
 * Local variables
 */


/*----------------------------------------------------------------------------
 * EIP97_Read32
 *
 * This routine writes to a Register location in the EIP-97.
 */
static inline uint32_t
EIP97_Read32(
        Device_Handle_t Device,
        const unsigned int Offset)
{
    return Device_Read32(Device, Offset);
}


/*----------------------------------------------------------------------------
 * EIP97_Write32
 *
 * This routine writes to a Register location in the EIP97.
 */
static inline void
EIP97_Write32(
        Device_Handle_t Device,
        const unsigned int Offset,
        const uint32_t Value)
{
    Device_Write32(Device, Offset, Value);
}


static inline bool
EIP97_REV_SIGNATURE_MATCH(
        const uint32_t Rev)
{
    return (((uint16_t)Rev) == EIP97_SIGNATURE);
}


static inline void
EIP97_EIP_REV_RD(
        Device_Handle_t Device,
        uint8_t * const EipNumber,
        uint8_t * const ComplmtEipNumber,
        uint8_t * const HWPatchLevel,
        uint8_t * const MinHWRevision,
        uint8_t * const MajHWRevision)
{
    uint32_t RevRegVal;

    RevRegVal = EIP97_Read32(Device, EIP97_REG_VERSION);

    *MajHWRevision     = (uint8_t)((RevRegVal >> 24) & MASK_4_BITS);
    *MinHWRevision     = (uint8_t)((RevRegVal >> 20) & MASK_4_BITS);
    *HWPatchLevel      = (uint8_t)((RevRegVal >> 16) & MASK_4_BITS);
    *ComplmtEipNumber  = (uint8_t)((RevRegVal >> 8)  & MASK_8_BITS);
    *EipNumber         = (uint8_t)((RevRegVal)       & MASK_8_BITS);
}


static inline void
EIP97_OPTIONS_RD(
        Device_Handle_t Device,
        uint8_t * const NofPes,
        uint8_t * const InTbufSize,
        uint8_t * const InDbufSize,
        uint8_t * const OutTbufSize,
        uint8_t * const OutDbufSize,
        bool * const fTG,
        bool * const fTRC)
{
    uint32_t RevRegVal;

    RevRegVal = EIP97_Read32(Device, EIP97_REG_OPTIONS);

    *fTRC         = ((RevRegVal & BIT_31) != 0);
    *fTG          = ((RevRegVal & BIT_30) != 0);
    *OutDbufSize  = (uint8_t)((RevRegVal >> 16) & MASK_4_BITS);
    *OutTbufSize  = (uint8_t)((RevRegVal >> 12) & MASK_4_BITS);
    *InDbufSize   = (uint8_t)((RevRegVal >> 8)  & MASK_4_BITS);
    *InTbufSize   = (uint8_t)((RevRegVal >> 4)  & MASK_4_BITS);
    *NofPes       = (uint8_t)((RevRegVal)       & MASK_4_BITS);
}


static inline void
EIP97_MST_CTRL_WR(
        const Device_Handle_t Device,
        const unsigned int PENr,
        const uint8_t SwapMethod)
{
    uint32_t RegVal = EIP97_REG_MST_CTRL_DEFAULT;

    IDENTIFIER_NOT_USED(PENr);

    RegVal |= (uint32_t)((((uint32_t)SwapMethod) & MASK_4_BITS) << 8);

    EIP97_Write32(Device, EIP97_REG_MST_CTRL, RegVal);
}


static inline void
EIP97_CS_DMA_CTRL2_WR(
        const Device_Handle_t Device,
        const uint8_t FLUE_Swap_Mask,
        const uint8_t FRC_Swap_Mask,
        const uint8_t TRC_Swap_Mask,
        const uint8_t ARC4_Swap_Mask)
{
    uint32_t RegVal = EIP97_REG_CS_DMA_CTRL2_DEFAULT;

    RegVal |= (uint32_t)((((uint32_t)FLUE_Swap_Mask) & MASK_4_BITS) << 24);
    RegVal |= (uint32_t)((((uint32_t)ARC4_Swap_Mask) & MASK_4_BITS) << 16);
    RegVal |= (uint32_t)((((uint32_t)TRC_Swap_Mask)  & MASK_4_BITS) << 8);
    RegVal |= (uint32_t)((((uint32_t)FRC_Swap_Mask)  & MASK_4_BITS));

    EIP97_Write32(Device, EIP97_REG_CS_DMA_CTRL2, RegVal);
}


#endif /* EIP97_GLOBAL_LEVEL0_H_ */


/* end of file eip97_global_level0.h */
