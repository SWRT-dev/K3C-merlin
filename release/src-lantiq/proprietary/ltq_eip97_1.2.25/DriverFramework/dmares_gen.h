/* dmares_gen.h
 *
 * Declare functions exported by "dmares_gen.c" that implements large parts
 * of the DMAResource API. The exported functions are to be used by module(s)
 * that implement the remaining parts of the DMAResource API.
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
* In case you do not have an account for this system, please send an e-mail
* to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef DMARES_GEN_H_
#define DMARES_GEN_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework DMAResource Types API
#include "dmares_types.h"


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


/*----------------------------------------------------------------------------
 * DMAResourceLib_IsSaneInput
 */
bool
DMAResourceLib_IsSaneInput(
        const DMAResource_AddrPair_t * AddrPair_p,
        const DMAResource_Properties_t * Props_p);

/*----------------------------------------------------------------------------
 * DMAResourceLib_AlignForSize
 */
unsigned int
DMAResourceLib_AlignForSize(
        const unsigned int ByteCount,
        const unsigned int AlignTo);

/*----------------------------------------------------------------------------
 * DMAResourceLib_AlignForAddress
 */
unsigned int
DMAResourceLib_AlignForAddress(
        const unsigned int ByteCount,
        const unsigned int AlignTo);

/*----------------------------------------------------------------------------
 * DMAResourceLib_LookupDomain
 */
DMAResource_AddrPair_t *
DMAResourceLib_LookupDomain(
        const DMAResource_Record_t * Rec_p,
        const DMAResource_AddrDomain_t Domain);

#endif // DMARES_GEN_H_


/* end of file dmares_gen.h */
