/* c_sa_builder.h
 *
 * Default configuration file for the SA Builder
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
#include "cs_sa_builder.h"

/* Specify a specific version of the EIP-96, specify exactly one */
//#define SAB_EIP96_VERSION_I
//#define SAB_EIP96_VERSION_IE
//#define SAB_EIP96_VERSION_IS
//#define SAB_EIP96_VERSION_IES

/* Which protcol families are enabled? Enable the desired protocols, for the
   I and IE version, the SSLTLS protocol is automatically disabled.*/
//#define SAB_ENABLE_PROTO_BASIC
//#define SAB_ENABLE_PROTO_IPSEC
//#define SAB_ENABLE_PROTO_SSLTLS
//#define SAB_ENABLE_PROTO_MACSEC
//#define SAB_ENABLE_PROTO_SRTP

/* Which protcol-specific options are enabled? */
//#define SAB_ENABLE_IPSEC_ESP
//#define SAB_ENABLE_IPSEC_AH

/* Enable if the SA Builder must support extended use case for IPsec
   processing */
//#define SAB_ENABLE_IPSEC_EXTENDED

/* Enable if the SA Builder must support extended use case for DTLS
   processing */
//#define SAB_ENABLE_DTLS_EXTENDED

/* Enable if the SA Builder must support an engine with fixed SA records
   (e.g. for a record cache) */
//#define SAB_ENABLE_FIXED_RECORD_SIZE

#ifdef SAB_ENABLE_IPSEC_EXTENDED
// In the extended use case, always use a fixed record size, but do
// not provide a value of that size here.
#define SAB_ENABLE_FIXED_RECORD_SIZE

// Set this if tunnel header fields are to be copied into the transform.
// for extended use case.
//#define SAB_ENABLE_EXTENDED_TUNNEL_HEADER

#else
// Look-aside use case.
#ifdef SAB_ENABLE_FIXED_RECORD_SIZE
#ifndef SAB_RECORD_WORD_COUNT
// Specify the number of words of an SA record when the record size is fixed.
#define SAB_RECORD_WORD_COUNT 64
#endif
#endif
#endif

// Set this if there are two fixed record sizes:
// SAB_RECORD_WORD_COUNT and SAB_RECORD_WORD_COUNT_LARGE,
// select the large one if the context size exceeds
// SAB_LARGE_RECORD_TRHESHOLD_WORD_COUNT.
//#define SAB_ENABLE_TWO_FIXED_RECORD_SIZES


/* Enable specific crypto and authentication algorithms. The correct ones
   are already set by the VERSION define.*/
//#define SAB_ENABLE_CRYPTO_AES
//#define SAB_ENABLE_CRYPTO_GCM
//#define SAB_ENABLE_CRYPTO_3DES
//#define SAB_ENABLE_CRYPTO_ARCFOUR
//#define SAB_ENABLE_AUTH_MD5
//#define SAB_ENABLE_AUTH_SHA1
//#define SAB_ENABLE_AUTH_SHA2_256
//#define SAB_ENABLE_AUTH_SHA2_512

#ifdef SAB_EIP96_VERSION_I
#undef SAB_ENABLE_PROTO_SSLTLS
#define SAB_ENABLE_CRYPTO_AES
#define SAB_ENABLE_CRYPTO_GCM
#define SAB_ENABLE_CRYPTO_3DES
#undef SAB_ENABLE_CRYPTO_ARCFOUR
#define SAB_ENABLE_AUTH_MD5
#define SAB_ENABLE_AUTH_SHA1
#define SAB_ENABLE_AUTH_SHA2_256
#undef SAB_ENABLE_AUTH_SHA2_512
#endif

#ifdef SAB_EIP96_VERSION_IE
#undef SAB_ENABLE_PROTO_SSLTLS
#define SAB_ENABLE_CRYPTO_AES
#define SAB_ENABLE_CRYPTO_GCM
#define SAB_ENABLE_CRYPTO_3DES
#undef SAB_ENABLE_CRYPTO_ARCFOUR
#define SAB_ENABLE_AUTH_MD5
#define SAB_ENABLE_AUTH_SHA1
#define SAB_ENABLE_AUTH_SHA2_256
#define SAB_ENABLE_AUTH_SHA2_512
#endif

#ifdef SAB_EIP96_VERSION_IS
#define SAB_ENABLE_CRYPTO_AES
#define SAB_ENABLE_CRYPTO_GCM
#define SAB_ENABLE_CRYPTO_3DES
#define SAB_ENABLE_CRYPTO_ARCFOUR
#define SAB_ENABLE_AUTH_MD5
#define SAB_ENABLE_AUTH_SHA1
#define SAB_ENABLE_AUTH_SHA2_256
#undef SAB_ENABLE_AUTH_SHA2_512
#endif

#ifdef SAB_EIP96_VERSION_IES
#define SAB_ENABLE_CRYPTO_AES
#define SAB_ENABLE_CRYPTO_GCM
#define SAB_ENABLE_CRYPTO_3DES
#define SAB_ENABLE_CRYPTO_ARCFOUR
#define SAB_ENABLE_AUTH_MD5
#define SAB_ENABLE_AUTH_SHA1
#define SAB_ENABLE_AUTH_SHA2_256
#define SAB_ENABLE_AUTH_SHA2_512
#endif


/* Enable specific crypto and authentication algorithms.  */
//#define SAB_ENABLE_CRYPTO_AES
//#define SAB_ENABLE_CRYPTO_GCM
//#define SAB_ENABLE_CRYPTO_3DES
//#define SAB_ENABLE_CRYPTO_ARCFOUR
//#define SAB_ENABLE_AUTH_MD5
//#define SAB_ENABLE_AUTH_SHA1
//#define SAB_ENABLE_AUTH_SHA2_256
//#define SAB_ENABLE_AUTH_SHA2_512

/* Enable this if you desire to include the ARC4 state in the SA
   record. This requires the hardware to be configured for relative
   ARC4 state offsets */
//#define SAB_ARC4_STATE_IN_SA


/* Enable single-pass inbound SSL/TLS, only for HW2.2 */
//#define SAB_ENABLE_SINGLE_PASS_SSLTLS

/* Strict checking of function arguments if enabled */
//#define SAB_STRICT_ARGS_CHECK


/* log level for the SA builder.
   choose from LOG_SEVERITY_INFO, LOG_SEVERITY_WARN, LOG_SEVERITY_CRIT */
#ifndef LOG_SEVERITY_MAX
#define LOG_SEVERITY_MAX LOG_SEVERITY_INFO
#endif


/* end of file c_sa_builder.h */
