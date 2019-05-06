/******************************************************************************
 * @Title: clock.c
 *
 * @author Brandon Lewien, Charles Van De Mark, Sam Zimmer
 * @date October 24, 2017
 * @version 1.0
 *
 * Compiled using CCSv7
 *
 * Description:
 * Configures the clock on the MSP432
 * ***************************************************************************/


#include "clock.h"

/*
 * Function: clock_config
 * ----------------------------
 *   Sets the clock to 12MHz
 *
 *   returns: void
 */
void clock_config() {
    CS->KEY  = 0x695A;
    CS->CTL0|= CS_CTL0_DCORSEL_3;
    CS->KEY  = 0;
}
