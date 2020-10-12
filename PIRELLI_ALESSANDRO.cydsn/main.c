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
#include "project.h"
#include "InterruptRoutines.h"
#include "GlobalVar.h"

int STATO=1;        //initializing the global variable which defines the state of the RGB LED

int main(void)
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
     
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Button_ISR_StartEx(Custom_Button_ISR);  
    PWM_Red_Start();
    PWM_Green_Start();
    
     
    for(;;)
    { 
        switch(STATO){
            case 1:                         /*2s period, stationary high output for both PWMs*/
                CyDelay(50);                /*small delay for stability added before every state change*/
                PWM_Red_WritePeriod(40000);
                PWM_Green_WritePeriod(40000);
                PWM_Red_SetCompareMode(4);
                PWM_Green_SetCompareMode(4);
                PWM_Red_WriteCompare(0);
                PWM_Green_WriteCompare(0);
                break;
            case 2:                         /*2s period, stationary high output for pwm R, alternating values (first high) for pwm G*/
                CyDelay(50);
                PWM_Red_WritePeriod(40000);
                PWM_Green_WritePeriod(40000); 
                PWM_Red_SetCompareMode(4);
                PWM_Green_SetCompareMode(4);
                PWM_Red_WriteCompare(0);
                PWM_Green_WriteCompare(20000);
                break;
            case 3:                         /*2s period, stationary high output for pwm G, alternating values (first low) for pwm R*/
                CyDelay(50);
                
                PWM_Red_WritePeriod(40000);
                PWM_Green_WritePeriod(40000);
                PWM_Red_SetCompareMode(2);
                PWM_Green_SetCompareMode(4);
                PWM_Red_WriteCompare(20000);
                PWM_Green_WriteCompare(0);
                break;
            case 4:                         /*1s period, alternating opposite outputs for both exits, pwm R starts high*/
                CyDelay(50);
                PWM_Red_WritePeriod(20000);
                PWM_Green_WritePeriod(20000);
                PWM_Red_SetCompareMode(4);
                PWM_Green_SetCompareMode(2);
                PWM_Red_WriteCompare(10000);
                PWM_Green_WriteCompare(10000);
                break;
            case 5:                         /*500ms period, alternating opposite outputs for both exits, pwm R starts low*/
                CyDelay(50);
                PWM_Red_WritePeriod(10000);
                PWM_Green_WritePeriod(10000);
                PWM_Red_SetCompareMode(2);
                PWM_Green_SetCompareMode(4);
                PWM_Red_WriteCompare(5000);
                PWM_Green_WriteCompare(5000);
                break;
            case 6:                         /*2s period, pwm R high for 3/4 of the period, pwm G alternates starting from high*/
                CyDelay(50);
                PWM_Red_WritePeriod(40000);
                PWM_Green_WritePeriod(40000);
                PWM_Red_SetCompareMode(4);
                PWM_Green_SetCompareMode(4);
                PWM_Red_WriteCompare(10000);
                PWM_Green_WriteCompare(20000);
                break;
            case 7:                         /*pwm R has 2s period, alternates output starting from low, pwm G has 1s period, alternates output starting from high*/
                CyDelay(50);
                PWM_Red_WritePeriod(40000);
                PWM_Green_WritePeriod(20000);
                PWM_Red_SetCompareMode(4);
                PWM_Green_SetCompareMode(4);
                PWM_Red_WriteCompare(20000);
                PWM_Green_WriteCompare(10000);
                break;
            default:
                break;
            
            }
        
        
        
        
    }
}

/* [] END OF FILE */
