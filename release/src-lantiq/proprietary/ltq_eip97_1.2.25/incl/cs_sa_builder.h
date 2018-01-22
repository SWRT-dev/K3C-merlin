/* cs_sa_builder.h
 *
 * Product-specific configuration file for the SA Builder.
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
* In case you do not have an account for
* this system, please send an e-mail to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

/* Specify a specific version of the EIP-96, specify exactly one */
//#define SAB_EIP96_VERSION_I
//#define SAB_EIP96_VERSION_IE
//#define SAB_EIP96_VERSION_IS
#define SAB_EIP96_VERSION_IES


/* Which protcol families are enabled? */
#define SAB_ENABLE_PROTO_BASIC
#define SAB_ENABLE_PROTO_IPSEC
#define SAB_ENABLE_PROTO_SSLTLS
//#define SAB_ENABLE_PROTO_MACSEC
//#define SAB_ENABLE_PROTO_SRTP

/* Which protcol-specific options are enabled? */
#define SAB_ENABLE_IPSEC_ESP
//#define SAB_ENABLE_IPSEC_AH

/* Enable this if you desire to include the ARC4 state in the SA
   record. This requires the hardware to be configured for relative
   ARC4 state offsets */
#define SAB_ARC4_STATE_IN_SA

/* Strict checking of function arguments if enabled */
#define SAB_STRICT_ARGS_CHECK

/* log level for the token builder.
   choose from LOG_SEVERITY_INFO, LOG_SEVERITY_WARN, LOG_SEVERITY_CRIT */
#define LOG_SEVERITY_MAX LOG_SEVERITY_CRIT

/* end of file cs_sa_builder.h */
