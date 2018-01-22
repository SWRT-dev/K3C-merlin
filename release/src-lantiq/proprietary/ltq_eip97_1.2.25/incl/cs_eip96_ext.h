/* cs_eip96_ext.h
 *
 * Top-level EIP-96 Driver Library configuration extensions
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

#ifndef CS_EIP96_EXT_H_
#define CS_EIP96_EXT_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Read/Write register constants

/*****************************************************************************
 * Byte offsets of the EIP-96 Packet Engine registers
 *****************************************************************************/

// Processing Packet Engine n (n - number of the DSE thread)
#define EIP96_CONF_BASE                    0x11000

// EIP-96 PRNG
#define EIP96_PRNG_BASE                    0x11040

// EIP-96 Options and Version
#define EIP96_VER_BASE                     0x113F8


#endif /* CS_EIP96_EXT_H_ */


/* end of file cs_eip96_ext.h */
