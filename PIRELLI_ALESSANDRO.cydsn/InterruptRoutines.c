/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "InterruptRoutines.h"
#include "GlobalVar.h"

CY_ISR(Custom_Button_ISR)
{
    STATO++;    //everytime the button is pressed (long enough, due to the presence of the debouncer) the RGB LED switches to the next state
    if(STATO==8){
        STATO=1;       //only 7 states available, so when state 8 is reached it gets instead set to 1
    }
}
/* [] END OF FILE */
