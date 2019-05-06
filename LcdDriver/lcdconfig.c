#include "msp.h"
#include "Crystalfontz128x128_ST7735.h"
#include "HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"
#include <stdio.h>
#include "string.h"


/* Graphic library context */
Graphics_Context g_sContext;

void lcdconfig(void)
{
/* Halting WDT and disabling master interrupts */
    MAP_Interrupt_disableMaster();

    /* Set the core voltage level to VCORE1
    MAP_PCM_setCoreVoltageLevel(PCM_VCORE1);

    Set 2 flash wait states for Flash bank 0 and 1
    MAP_FlashCtl_setWaitState(FLASH_BANK0, 2);
    MAP_FlashCtl_setWaitState(FLASH_BANK1, 2);
*/
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    GrContextFontSet(&g_sContext, &g_sFontFixed6x8);
    Graphics_clearDisplay(&g_sContext);
}
/**********************************************
 * The reason why 'sentence' is an array size of 20 is because 20 letters can only fit
 * within the screen. More than 20 letters are not needed.
 *
 * Let xpos always = 64 if you want words to be centered in the screen.
 *
 * ypos needs to have at least 10 number differences so that the sentences can
 * be spaced out accordingly.
 * Example in main:
 *  getwordsback("Type this sentence",64,64);
 *  getwordsback("Numba 1",64,74);
 *  getwordsback("Realist",64,84);
***********************************************/
void getwordsback(int8_t sentence[20],int xpos, int ypos)
{
    Graphics_drawStringCentered(&g_sContext, sentence, AUTO_STRING_LENGTH, xpos, ypos, OPAQUE_TEXT);
}
