/* log.c
 *
 * Log implementation for specific environment
 */

/*****************************************************************************
* Copyright (c) 2008-2013 INSIDE Secure B.V. All Rights Reserved.
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

//#define LOG_SEVERITY_MAX  LOG_SEVERITY_NO_OUTPUT
#define LOG_SEVERITY_MAX  LOG_SEVERITY_INFO
//#define LOG_SEVERITY_MAX  LOG_SEVERITY_CRIT

#include "log.h"            // the API to implement


/*----------------------------------------------------------------------------
 * Log_HexDump
 *
 * This function logs Hex Dump of a Buffer
 *
 * szPrefix
 *     Prefix to be printed on every row.
 *
 * PrintOffset
 *     Offset value that is printed at the start of every row. Can be used
 *     when the byte printed are located at some offset in another buffer.
 *
 * Buffer_p
 *     Pointer to the start of the array of bytes to hex dump.
 *
 * ByteCount
 *     Number of bytes to include in the hex dump from Buffer_p.
 *
 * Return Value
 *     None.
 */
void
Log_HexDump(
        const char * szPrefix_p,
        const unsigned int PrintOffset,
        const uint8_t * Buffer_p,
        const unsigned int ByteCount)
{
    unsigned int i;
    char Format[] = "%s %08d:";

    for(i = 0; i < ByteCount; i += 16)
    {
        unsigned int j, Limit;

        // if we do not have enough data for a full line
        if (i + 16 > ByteCount)
            Limit = ByteCount - i;
        else
            Limit = 16;

        Log_FormattedMessage(Format, szPrefix_p, PrintOffset + i);

        for (j = 0; j < Limit; j++)
            Log_FormattedMessage(" %02X", Buffer_p[i+j]);

        Log_FormattedMessage("\n");
    } // for
}


/* end of file log.c */
