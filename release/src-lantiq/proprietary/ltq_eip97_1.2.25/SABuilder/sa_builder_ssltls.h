/* sa_builder_ssltls.h
 *
 * SSL/TLS/DTLS specific functions of the SA Builder.
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


#ifndef  SA_BUILDER_SSLTLS_H_
#define SA_BUILDER_SSLTLS_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

#include "sa_builder_params.h"
#include "sa_builder.h"
#include "sa_builder_params_ssltls.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"


/*----------------------------------------------------------------------------
 * SABuilder_Init_SSLTLS
 *
 * This function initializes the SABuilder_Params_t data structure and its
 * SABuilder_Params_SSLTLS_t extension with sensible defaults for SSL, TLS
 * and DTLS processing.
 *
 * SAParams_p (output)
 *   Pointer to SA parameter structure to be filled in.
 * SAParamsSSLTLS_p (output)
 *   Pointer to SSLTLS parameter extension to be filled in
 * version (input)
 *   Version code for the desired protcol (choose one of the SAB_*_VERSION_*
 *   constants from sa_builder_params_ssltls.h).
 * direction (input)
 *   Must be one of SAB_DIRECTION_INBOUND or SAB_DIRECTION_OUTBOUND.
 *
 * Both the crypto and the authentication algorithm are initialized to
 * NULL. The crypto algorithm (which may remain NULL) must be set to
 * one of the algorithms supported by the protocol. The authentication
 * algorithm must also be set to one of the algorithms supported by
 * the protocol..Any required keys have to be specified as well.
 *
 * Both the SAParams_p and SAParamsSSLTLS_p input parameters must point
 * to valid storage where variables of the appropriate type can be
 * stored. This function initializes the link from SAParams_p to
 * SAParamsSSSLTLS_p.
 *
 * Return:
 * SAB_STATUS_OK on success
 * SAB_INVALID_PARAMETER when one of the pointer parameters is NULL
 *   or the remaining parameters have illegal values.
 */
SABuilder_Status_t
SABuilder_Init_SSLTLS(
    SABuilder_Params_t * const SAParams_p,
    SABuilder_Params_SSLTLS_t * const SAParamsSSLTLS_p,
    const uint16_t version,
    const SABuilder_Direction_t direction);


#endif /* SA_BUILDER_SSLTLS_H_ */


/* end of file sa_builder_ssltls.h */
