/* adapter_global_control_init.c
 *
 * Adapter module responsible for adapter global control initialization tasks.
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
* In case you do not have an account for
* this system, please send an e-mail to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
*/

#include "adapter_global_control_init.h"


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Top-level Adapter configuration
#include "c_adapter_global.h"

//#include "adapter_pciconfig.h"  // PCICONFIG_*

// Logging API
#include "log.h"            // LOG_*

// Driver Framework Device API
#include "device_mgmt.h"    // Device_Initialize, Device_UnInitialize
#include "device_rw.h"      // Device_Read32, Device_Write32

// Driver Framework Basic Definitions API
#include "basic_defs.h"     // bool, true, false


/*----------------------------------------------------------------------------
 * Local variables
 */

static bool Adapter_IsInitialized = false;


/*----------------------------------------------------------------------------
 * Adapter_Global_Control_Init
 *
 * Return Value
 *     true   Success
 *     false  Failure (fatal!)
 */
bool
Adapter_Global_Control_Init(void)
{
    int nIRQ = -1;

    if (Adapter_IsInitialized != false)
    {
        LOG_WARN("Adapter_Init: Already initialized\n");
        return true;
    }

    // trigger first-time initialization of the adapter
    if (Device_Initialize(&nIRQ) < 0)
        return false;

    Adapter_IsInitialized = true;

    return true;    // success
}


/*----------------------------------------------------------------------------
 * Adapter_Global_Control_UnInit
 */
void
Adapter_Global_Control_UnInit(void)
{
    if (!Adapter_IsInitialized)
    {
        LOG_WARN("Adapter_Global_Control_UnInit: Adapter is uninitialized\n");
        return;
    }

    Adapter_IsInitialized = false;

    Device_UnInitialize();
}


/*----------------------------------------------------------------------------
 * Adapter_Global_Control_Report_Build_Params
 */
void
Adapter_Global_Control_Report_Build_Params(void)
{
#ifdef LOG_INFO_ENABLED
    int dummy;

    // This function is dependent on config file cs_adapter.h.
    // Please update this when Config file for Adapter is changed.
    Log_FormattedMessage("Adapter Global Control build configuration:\n");

#define REPORT_SET(_X) \
    Log_FormattedMessage("\t" #_X "\n")

#define REPORT_STR(_X) \
    Log_FormattedMessage("\t" #_X ": %s\n", _X)

#define REPORT_INT(_X) \
    dummy = _X; Log_FormattedMessage("\t" #_X ": %d\n", _X)

#define REPORT_HEX32(_X) \
    dummy = _X; Log_FormattedMessage("\t" #_X ": 0x%08X\n", _X)

#define REPORT_EQ(_X, _Y) \
    dummy = (_X + _Y); Log_FormattedMessage("\t" #_X " == " #_Y "\n")

#define REPORT_EXPL(_X, _Y) \
    Log_FormattedMessage("\t" #_X _Y "\n")

#ifdef ADAPTER_64BIT_HOST
    REPORT_EXPL(ADAPTER_64BIT_HOST,
                " is SET => addresses are 64-bit");
#else
    REPORT_EXPL(ADAPTER_64BIT_HOST,
                " is NOT set => addresses are 32-bit");
#endif

    // Global interrupts
#ifdef ADAPTER_GLOBAL_INTERRUPTS_TRACEFILTER
    REPORT_INT(ADAPTER_GLOBAL_INTERRUPTS_TRACEFILTER);
#endif

    // Log
    Log_FormattedMessage("Logging:\n");

#if (LOG_SEVERITY_MAX == LOG_SEVERITY_INFO)
    REPORT_EQ(LOG_SEVERITY_MAX, LOG_SEVERITY_INFO);
#elif (LOG_SEVERITY_MAX == LOG_SEVERITY_WARNING)
    REPORT_EQ(LOG_SEVERITY_MAX, LOG_SEVERITY_WARNING);
#elif (LOG_SEVERITY_MAX == LOG_SEVERITY_CRITICAL)
    REPORT_EQ(LOG_SEVERITY_MAX, LOG_SEVERITY_CRITICAL);
#else
    REPORT_EXPL(LOG_SEVERITY_MAX, " - Unknown (not info/warn/crit)");
#endif


    IDENTIFIER_NOT_USED(dummy);

    // Adapter other
    Log_FormattedMessage("Other:\n");

#endif //LOG_INFO_ENABLED
}


/* end of file adapter_global_control_init.c */
