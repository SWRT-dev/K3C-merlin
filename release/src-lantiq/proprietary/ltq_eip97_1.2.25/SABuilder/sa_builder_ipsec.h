/* sa_builder_ipsec.h
 *
 * IPsec specific functions of the SA Builder.
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


#ifndef  SA_BUILDER_IPSEC_H_
#define SA_BUILDER_IPSEC_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

#include "sa_builder_params.h"
#include "sa_builder.h"
#include "sa_builder_params_ipsec.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"


/*----------------------------------------------------------------------------
 * SABuilder_Init_ESP
 *
 * This function initializes the SABuilder_Params_t data structure and its
 * SABuilder_Params_IPsec_t extension with sensible defaults for ESP
 * processing.
 *
 * SAParams_p (output)
 *   Pointer to SA parameter structure to be filled in.
 * SAParamsIPsec_p (output)
 *   Pointer to IPsec parameter extension to be filled in
 * spi (input)
 *   SPI of the newly created parameter structure (must not be zero).
 * TunnelTransport (input)
 *   Must be one of SAB_IPSEC_TUNNEL or SAB_IPSEC_TRANSPORT.
 * IPMode (input)
 *   Must be one of SAB_IPSEC_IPV4 or SAB_IPSEC_IPV6.
 * direction (input)
 *   Must be one of SAB_DIRECTION_INBOUND or SAB_DIRECTION_OUTBOUND.
 *
 * Both the crypto and the authentication algorithm are initialized to
 * NULL, which is illegal. At least one of the crypto algorithm or the
 * authentication algorithm and associated keys must be modified after
 * calling this function to obtain a valid parameter structure.
 *
 * Both the SAParams_p and SAParamsIPsec_p input parameters must point
 * to valid storage where variables of the appropriate type can be
 * stored. This function initializes the link from SAParams_p to
 * SAParamsIPsec_p.
 *
 * Return:
 * SAB_STATUS_OK on success
 * SAB_INVALID_PARAMETER when one of the pointer parameters is NULL
 *   or the remaining parameters have illegal values.
 */
SABuilder_Status_t
SABuilder_Init_ESP(
    SABuilder_Params_t * const SAParams_p,
    SABuilder_Params_IPsec_t * const SAParamsIPsec_p,
    const uint32_t spi,
    const uint32_t TunnelTransport,
    const uint32_t IPMode,
    const SABuilder_Direction_t direction);


#endif /* SA_BUILDER_IPSEC_H_ */


/* end of file sa_builder_ipsec.h */
