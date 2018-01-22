/* sa_builder_basic.h
 *
 * Basic Crypto/hash specific functions of the SA Builder.
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


#ifndef  SA_BUILDER_BASIC_H_
#define SA_BUILDER_BASIC_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

#include "sa_builder_params.h"
#include "sa_builder.h"
#include "sa_builder_params_basic.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"


/*----------------------------------------------------------------------------
 * SABuilder_Init_Basic
 *
 * This function initializes the SABuilder_Params_t data structure and
 * its SABuilder_Params_Basic_t extension with sensible defaults for
 * basic crypto and hash processing..
 *
 * SAParams_p (output)
 *   Pointer to SA parameter structure to be filled in.
 * SAParamsBasic_p (output)
 *   Pointer to Basic parameter extension to be filled in
 * direction (input)
 *   Must be one of SAB_DIRECTION_INBOUND or SAB_DIRECTION_OUTBOUND.
 *
 * Both the crypto and the authentication algorithm are initialized to
 * NULL. Either the cipher algorithm or the authentication algorithm
 * (but not both) must be set to one of the supported algorithms for
 * basic crypto or basic hash or HMAC. The crypto mode and IV source
 * can be specified as well.  Any required keys have to be specified
 * as well.
 *
 * Both the SAParams_p and SAParamsBasic_p input parameters must point
 * to valid storage where variables of the appropriate type can be
 * stored. This function initializes the link from SAParams_p to
 * SAParamsBasic_p.
 *
 * Return:
 * SAB_STATUS_OK on success
 * SAB_INVALID_PARAMETER when one of the pointer parameters is NULL
 *   or the remaining parameters have illegal values.
 */
SABuilder_Status_t
SABuilder_Init_Basic(
    SABuilder_Params_t * const SAParams_p,
    SABuilder_Params_Basic_t * const SAParamsBasic_p,
    const SABuilder_Direction_t direction);


#endif /* SA_BUILDER_BASIC_H_ */


/* end of file sa_builder_basic.h */
