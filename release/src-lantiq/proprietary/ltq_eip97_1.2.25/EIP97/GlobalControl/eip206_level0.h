/* eip206_level0.h
 *
 * EIP-206 Processing Engine Level0 Internal interface
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

#ifndef EIP206_LEVEL0_H_
#define EIP206_LEVEL0_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // BIT definitions, bool, uint32_t

// EIP-206 HW interface
#include "eip206_hw_interface.h"

// Driver Framework Device API
#include "device_types.h"       // Device_Handle_t
#include "device_rw.h"          // Read32, Write32


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


/*----------------------------------------------------------------------------
 * Local variables
 */


/*----------------------------------------------------------------------------
 * EIP206_Read32
 *
 * This routine writes to a Register location in the EIP-206.
 */
static inline uint32_t
EIP206_Read32(
        Device_Handle_t Device,
        const unsigned int Offset)
{
    return Device_Read32(Device, Offset);
}


/*----------------------------------------------------------------------------
 * EIP206_Write32
 *
 * This routine writes to a Register location in the EIP-206.
 */
static inline void
EIP206_Write32(
        Device_Handle_t Device,
        const unsigned int Offset,
        const uint32_t Value)
{
    Device_Write32(Device, Offset, Value);
}


static inline bool
EIP206_REV_SIGNATURE_MATCH(
        const uint32_t Rev)
{
    return (((uint16_t)Rev) == EIP206_SIGNATURE);
}


static inline void
EIP206_EIP_REV_RD(
        Device_Handle_t Device,
        const unsigned int PEnr,
        uint8_t * const EipNumber,
        uint8_t * const ComplmtEipNumber,
        uint8_t * const HWPatchLevel,
        uint8_t * const MinHWRevision,
        uint8_t * const MajHWRevision)
{
    uint32_t RevRegVal;

    RevRegVal = EIP206_Read32(Device, EIP206_REG_VERSION(PEnr));

    *MajHWRevision     = (uint8_t)((RevRegVal >> 24) & MASK_4_BITS);
    *MinHWRevision     = (uint8_t)((RevRegVal >> 20) & MASK_4_BITS);
    *HWPatchLevel      = (uint8_t)((RevRegVal >> 16) & MASK_4_BITS);
    *ComplmtEipNumber  = (uint8_t)((RevRegVal >> 8)  & MASK_8_BITS);
    *EipNumber         = (uint8_t)((RevRegVal)       & MASK_8_BITS);
}


static inline void
EIP206_OPTIONS_RD(
        Device_Handle_t Device,
        const unsigned int PEnr,
        uint8_t * const PE_Type,
        uint8_t * const InClassifier,
        uint8_t * const OutClassifier,
        uint8_t * const NofMAC_Channels,
        uint8_t * const InDbufSizeKB,
        uint8_t * const InTbufSizeKB,
        uint8_t * const OutDbufSizeKB,
        uint8_t * const OutTbufSizeKB)
{
    uint32_t RevRegVal;

    RevRegVal = EIP206_Read32(Device, EIP206_REG_OPTIONS(PEnr));

    *OutTbufSizeKB   = (uint8_t)((RevRegVal >> 28) & MASK_4_BITS);
    *OutDbufSizeKB   = (uint8_t)((RevRegVal >> 24) & MASK_4_BITS);
    *InTbufSizeKB    = (uint8_t)((RevRegVal >> 20) & MASK_4_BITS);
    *InDbufSizeKB    = (uint8_t)((RevRegVal >> 16) & MASK_4_BITS);
    *NofMAC_Channels = (uint8_t)((RevRegVal >> 12) & MASK_4_BITS);
    *OutClassifier   = (uint8_t)((RevRegVal >> 10) & MASK_2_BITS);
    *InClassifier    = (uint8_t)((RevRegVal >> 8)  & MASK_2_BITS);
    *PE_Type         = (uint8_t)((RevRegVal)       & MASK_8_BITS);
}


static inline void
EIP206_IN_DBUF_THRESH_DEFAULT_WR(
        Device_Handle_t Device,
        const unsigned int PEnr)
{
    EIP206_Write32(Device,
                   EIP206_IN_REG_DBUF_TRESH(PEnr),
                   EIP206_IN_REG_DBUF_TRESH_DEFAULT);
}


static inline void
EIP206_IN_DBUF_THRESH_WR(
        Device_Handle_t Device,
        const unsigned int PEnr,
        const uint8_t MinTresh,
        const uint8_t MaxTresh)
{
    uint32_t RegVal = EIP206_IN_REG_DBUF_TRESH_DEFAULT;

    RegVal |= (uint32_t)((((uint32_t)MaxTresh) & MASK_4_BITS) << 12);
    RegVal |= (uint32_t)((((uint32_t)MinTresh) & MASK_4_BITS) << 8);

    EIP206_Write32(Device, EIP206_IN_REG_DBUF_TRESH(PEnr), RegVal);
}


static inline void
EIP206_IN_TBUF_THRESH_DEFAULT_WR(
        Device_Handle_t Device,
        const unsigned int PEnr)
{
    EIP206_Write32(Device,
                   EIP206_IN_REG_TBUF_TRESH(PEnr),
                   EIP206_IN_REG_TBUF_TRESH_DEFAULT);
}


static inline void
EIP206_IN_TBUF_THRESH_WR(
        Device_Handle_t Device,
        const unsigned int PEnr,
        const uint8_t MinTresh,
        const uint8_t MaxTresh)
{
    uint32_t RegVal = EIP206_IN_REG_TBUF_TRESH_DEFAULT;

    RegVal |= (uint32_t)((((uint32_t)MaxTresh) & MASK_4_BITS) << 12);
    RegVal |= (uint32_t)((((uint32_t)MinTresh) & MASK_4_BITS) << 8);

    EIP206_Write32(Device, EIP206_IN_REG_TBUF_TRESH(PEnr), RegVal);
}


static inline void
EIP206_OUT_DBUF_THRESH_DEFAULT_WR(
        Device_Handle_t Device,
        const unsigned int PEnr)
{
    EIP206_Write32(Device,
                   EIP206_OUT_REG_DBUF_TRESH(PEnr),
                   EIP206_OUT_REG_DBUF_TRESH_DEFAULT);
}


static inline void
EIP206_OUT_DBUF_THRESH_WR(
        Device_Handle_t Device,
        const unsigned int PEnr,
        const uint8_t MinTresh,
        const uint8_t MaxTresh)
{
    uint32_t RegVal = EIP206_OUT_REG_DBUF_TRESH_DEFAULT;

    RegVal |= (uint32_t)((((uint32_t)MaxTresh) & MASK_4_BITS) << 4);
    RegVal |= (uint32_t)((((uint32_t)MinTresh) & MASK_4_BITS));

    EIP206_Write32(Device, EIP206_OUT_REG_DBUF_TRESH(PEnr), RegVal);
}


static inline void
EIP206_OUT_TBUF_THRESH_DEFAULT_WR(
        Device_Handle_t Device,
        const unsigned int PEnr)
{
    EIP206_Write32(Device,
                   EIP206_OUT_REG_TBUF_TRESH(PEnr),
                   EIP206_OUT_REG_TBUF_TRESH_DEFAULT);
}


static inline void
EIP206_OUT_TBUF_THRESH_WR(
        Device_Handle_t Device,
        const unsigned int PEnr,
        const uint8_t MinTresh,
        const uint8_t MaxTresh)
{
    uint32_t RegVal = EIP206_OUT_REG_TBUF_TRESH_DEFAULT;

    RegVal |= (uint32_t)((((uint32_t)MaxTresh) & MASK_4_BITS) << 4);
    RegVal |= (uint32_t)((((uint32_t)MinTresh) & MASK_4_BITS));

    EIP206_Write32(Device, EIP206_OUT_REG_TBUF_TRESH(PEnr), RegVal);
}


#endif /* EIP206_LEVEL0_H_ */


/* end of file eip206_level0.h */
