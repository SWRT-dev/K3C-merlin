/* cs_eip202_global_ext.h
 *
 * Top-level EIP-202 Driver Library Global Control configuration extensions
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

#ifndef CS_EIP202_GLOBAL_EXT_H_
#define CS_EIP202_GLOBAL_EXT_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Read/Write register constants

/*****************************************************************************
 * Byte offsets of the EIP-202 HIA registers
 *****************************************************************************/

// HIA DFE all threads
#define EIP202_DFE_BASE           0x0F000

// HIA DFE thread n (n - number of the DFE thread)
#define EIP202_DFE_TRD_BASE       0x0F200

// HIA DSE all threads
#define EIP202_DSE_BASE           0x0F400

// HIA DSE thread n (n - number of the DSE thread)
#define EIP202_DSE_TRD_BASE       0x0F600

// HIA Global
#define EIP202_G_BASE             0x0FFF4


#endif /* CS_EIP202_GLOBAL_EXT_H_ */


/* end of file cs_eip202_global_ext.h */
