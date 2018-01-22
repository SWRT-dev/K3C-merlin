/* eip202_rdr_dscr.h
 *
 * EIP-202 Ring Control Driver Library API Result Descriptor Internal interface
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

#ifndef EIP202_RDR_DSCR_H_
#define EIP202_RDR_DSCR_H_


/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */



/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


/*----------------------------------------------------------------------------
 * Local variables
 */


/*----------------------------------------------------------------------------
 * EIP202_RDR_WriteCB
 * A write callback for the Ring Helper
 */
int
EIP202_RDR_WriteCB(
        void * const CallbackParam1_p,
        const int CallbackParam2,
        const unsigned int WriteIndex,
        const unsigned int WriteCount,
        const unsigned int TotalWriteLimit,
        const void * Descriptors_p,
        const int DescriptorCount,
        const unsigned int DescriptorSkipCount);


/*----------------------------------------------------------------------------
 * EIP202_RDR_ReadCB
 * A read callback for the Ring Helper
 */
int
EIP202_RDR_ReadCB(
        void * const CallbackParam1_p,
        const int CallbackParam2,
        const unsigned int ReadIndex,
        const unsigned int ReadLimit,
        void * Descriptors_p,
        const unsigned int DescriptorSkipCount);


/*----------------------------------------------------------------------------
 * EIP202_RDR_StatusCB
 * A status callback for the Ring Helper
 */

int
EIP202_RDR_StatusCB(
        void * const CallbackParam1_p,
        const int CallbackParam2,
        int * const DeviceReadPos_p);


#endif /* EIP202_RDR_DSCR_H_ */


/* end of file eip202_rdr_dscr.h */
