/* c_token_builder.h
 *
 * Default configuration file for the Token Builder
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


/*----------------------------------------------------------------------------
 * Import the product specific configuration.
 */
#include "cs_token_builder.h"


/* Uncomment this option if the EIP-96 does not use an input packet pointer.
   This is the case when it is used in a system in which packet data is fetched
   outside the control of the EIP-96. Whether this setting is needed depends
   on the hardware environment in which the EIP-96 is integrated.
 */
//#define TKB_NO_INPUT_PACKET_POINTER

/* Uncomment this option if context reuse must be auto-detected. This
   is only supported in EIP-96 HW2.1 and higher.
 */
//#define TKB_AUTODETECT_CONTEXT_REUSE

/* Define this to a nonzero value if the generated token must contain a header
   that includes the Token Header Word. Any other fields are filled with zero.
   This parameter specifies the header size in words.
 */
#ifndef TKB_TOKEN_HEADER_WORD_COUNT
#define TKB_TOKEN_HEADER_WORD_COUNT 0
#endif


/* Specify a specific version of the EIP-96, specify exactly one */
//#define TKB_EIP96_VERSION_I
//#define TKB_EIP96_VERSION_IE
//#define TKB_EIP96_VERSION_IS
//#define TKB_EIP96_VERSION_IES


/* Which protcol families are enabled? */
//#define TKB_ENABLE_PROTO_BASIC
#define TKB_ENABLE_PROTO_IPSEC
//#define TKB_ENABLE_PROTO_SSLTLS
//#define TKB_ENABLE_PROTO_MACSEC
//#define TKB_ENABLE_PROTO_SRTP

/* Which protcol-specific options are enabled? */
//#define TKB_ENABLE_IPSEC_ESP
//#define TKB_ENABLE_IPSEC_AH


#if defined(TKB_EIP96_VERSION_I) || defined(TKB_EIP96_VERSION_IE)
#undef TKB_ENABLE_PROTO_SSLTLS
#endif

#ifdef TKB_ENABLE_SINGLE_PASS_SSLTLS
#define TKB_SINGLE_PASS_SSLTLS 1
#else
#define TKB_SINGLE_PASS_SSLTLS 0
#endif

#ifdef TKB_ENABLE_PROTO_BASIC
#define TKB_HAVE_PROTO_BASIC 1
#else
#define TKB_HAVE_PROTO_BASIC 0
#endif

#ifdef TKB_ENABLE_PROTO_IPSEC
#define TKB_HAVE_PROTO_IPSEC 1
#else
#define TKB_HAVE_PROTO_IPSEC 0
#endif

#ifdef TKB_ENABLE_PROTO_SSLTLS
#define TKB_HAVE_PROTO_SSLTLS 1
#else
#define TKB_HAVE_PROTO_SSLTLS 0
#endif

#ifdef TKB_ENABLE_PROTO_SRTP
#define TKB_HAVE_PROTO_SRTP 1
#else
#define TKB_HAVE_PROTO_SRTP 0
#endif



/* Strict checking of function arguments if enabled */
//#define TKB_STRICT_ARGS_CHECK

/* log level for the token builder.
   choose from LOG_SEVERITY_INFO, LOG_SEVERITY_WARN, LOG_SEVERITY_CRIT */
#ifndef LOG_SEVERITY_MAX
#define LOG_SEVERITY_MAX LOG_SEVERITY_INFO
#endif


/* end of file c_sa_builder.h */
