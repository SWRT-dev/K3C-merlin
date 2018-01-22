/* cs_eip206_ext.h
 *
 * Top-level EIP-206 Driver Library configuration extensions
 *
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
* In case you do not have an account for
* this system, please send an e-mail to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef CS_EIP206_EXT_H_
#define CS_EIP206_EXT_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Read/Write register constants

/*****************************************************************************
 * Byte offsets of the EIP-206 Processing Engine registers
 *****************************************************************************/

// Processing Packet Engine n (n - number of the PE)
// Input Side
#define EIP206_IN_DBUF_BASE           0x10000
#define EIP206_IN_TBUF_BASE           0x10100

// Output Side
#define EIP206_OUT_DBUF_BASE          0x11C00
#define EIP206_OUT_TBUF_BASE          0x11D00

// PE Options and Version
#define EIP206_VER_BASE               0x11FFC


#endif /* CS_EIP206_EXT_H_ */


/* end of file cs_eip206_ext.h */
