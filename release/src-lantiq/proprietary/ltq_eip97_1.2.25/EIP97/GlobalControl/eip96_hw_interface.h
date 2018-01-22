/* eip96_hw_interface.h
 *
 * EIP-96 Packet Engine HW interface
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

#ifndef EIP96_HW_INTERFACE_H_
#define EIP96_HW_INTERFACE_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Default configuration
#include "c_eip96.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // BIT definitions


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Internal Packet Engine time-out – a fatal error requiring a complete reset.
#define EIP96_TIMEOUT_FATAL_ERROR_MASK     BIT_14

// Read/Write register constants

/*****************************************************************************
 * Byte offsets of the EIP-96 Packet Engine registers
 *****************************************************************************/
#define EIP96_REG_OFFS                     4
#define EIP96_REG_MAP_SIZE                 8096

// Processing Packet Engine n (n - number of the DSE thread)
#define EIP96_REG_TOKEN_CTRL_STAT(n)       ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_CONF_BASE) + \
                                             (0x00 * EIP96_REG_OFFS)))
#define EIP96_REG_FUNCTION_EN(n)           ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_CONF_BASE) + \
                                             (0x01 * EIP96_REG_OFFS)))
#define EIP96_REG_CONTEXT_CTRL(n)          ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_CONF_BASE) + \
                                             (0x02 * EIP96_REG_OFFS)))
#define EIP96_REG_CONTEXT_STAT(n)          ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_CONF_BASE) + \
                                             (0x03 * EIP96_REG_OFFS)))

#define EIP96_REG_INT_CTRL_STAT(n)         ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_CONF_BASE) + \
                                             (0x04 * EIP96_REG_OFFS)))

#define EIP96_REG_OUT_TRANS_CTRL_STAT(n)   ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_CONF_BASE) + \
                                             (0x06 * EIP96_REG_OFFS)))
#define EIP96_REG_OUT_BUF_CTRL(n)          ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_CONF_BASE) + \
                                             (0x07 * EIP96_REG_OFFS)))

// EIP-96 PRNG
#define EIP96_REG_PRNG_STAT(n)             ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x00 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_CTRL(n)             ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x01 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_SEED_L(n)           ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x02 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_SEED_H(n)           ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x03 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_KEY_0_L(n)          ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x04 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_KEY_0_H(n)          ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x05 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_KEY_1_L(n)          ((EIP96_REG_MAP_SIZE * n) + \
                                             ((EIP96_PRNG_BASE) + \
                                              (0x06 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_KEY_1_H(n)          ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x07 * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_LFSR_L(n)           ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x0c * EIP96_REG_OFFS)))
#define EIP96_REG_PRNG_LFSR_H(n)           ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_PRNG_BASE) + \
                                             (0x0d * EIP96_REG_OFFS)))

// EIP-96 Options and Version
// New registers to must still be added to the HW,
// do not use these registers yet
#define EIP96_REG_OPTIONS(n)               ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_VER_BASE) + \
                                             (0x00 * EIP96_REG_OFFS)))
#define EIP96_REG_VERSION(n)               ((EIP96_REG_MAP_SIZE * n) + \
                                            ((EIP96_VER_BASE) + \
                                             (0x01 * EIP96_REG_OFFS)))

// Default EIP96_REG_TOKEN_CTRL_STAT register value
#define EIP96_REG_TOKEN_CTRL_STAT_DEFAULT   0x00004004

// Default EIP96_REG_INT_CTRL_STAT register value
#define EIP96_REG_INT_CTRL_STAT_DEFAULT     0xC00F0000

// Default EIP96_REG_PRNG_CTRL register value
#define EIP96_REG_PRNG_CTRL_DEFAULT         0x00000000

// Default EIP96_REG_OUT_BUF_CTRL register value
#define EIP96_REG_OUT_BUF_CTRL_DEFAULT      0x00000000


#endif /* EIP96_HW_INTERFACE_H_ */


/* end of file eip96_hw_interface.h */
