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
#include <project.h>
#include <stdio.h>
#define INCH_PER_MAGNET 1.554
#define SEC_PER_PERIOD 357.914

uint32 gprev_HE_count = 0;
int gfirst_HE_read = 1;
int gspeedMeasurements = 0;
double gcurSpeed = 0;
uint32 speedCounts[5];

double speedAvg(uint32 speeds[]){
    double counter = 0;
    uint32 i = 0;
    uint32 size = 5;
    if (gspeedMeasurements < 5) {
        size = gspeedMeasurements;
    }
    for (i = 0; i < size; i++){
        counter += speeds[i];   
    }
    return counter/(double)size;
}

double curSpeed(){
    double current_Speed = 0;
    //average clock tix b/w two magnets in one rotation
    current_Speed = speedAvg(speedCounts);
    //average sec elapsed b/w two magnets
    current_Speed = (double)current_Speed/HE_TIMER_ReadPeriod() * SEC_PER_PERIOD;
    //average speed b/w two magnets
    current_Speed = (double)INCH_PER_MAGNET/current_Speed;
    // return (double)current_Speed;
    return current_Speed;
}

CY_ISR(HE_inter) {
    uint32 curr_HE_count = 0;
    uint32 time_diff = 0;
    
    char buffer[15];
    
    if (PWM_ReadCompare() == 0) {
        PWM_WriteCompare(PWM_ReadPeriod());
        LCD_ClearDisplay();
        LCD_Position(0,0);
        //LCD_PrintString("Max PWM Period");
        LCD_PrintNumber(PWM_OUT_PIN_Read());
    } else {
        PWM_WriteCompare(0);
        LCD_ClearDisplay();
        LCD_Position(0,0);
        //LCD_PrintString("Min PWM Period");
        LCD_PrintNumber(PWM_OUT_PIN_Read());
    }
    
    if (gfirst_HE_read == 1) {
        gprev_HE_count = HE_TIMER_ReadCounter();
        gfirst_HE_read = 0;
    }
    else {
        curr_HE_count = HE_TIMER_ReadCounter();

        if (gprev_HE_count < curr_HE_count) {
            gprev_HE_count += HE_TIMER_ReadPeriod();
        }

        //LCD_ClearDisplay();
        LCD_Position(0,0);
        time_diff = gprev_HE_count - curr_HE_count;
        speedCounts[gspeedMeasurements%5] = time_diff;
        gspeedMeasurements++;
        gcurSpeed = curSpeed();
        gprev_HE_count = curr_HE_count;

        sprintf(buffer, "%f", gcurSpeed);        
        //LCD_PrintString(buffer);
    }
}
    
int main()
{
    CYGlobalIntEnable;  
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("ELE302 Carlab");
    
    HE_TIMER_Start();
    HE_ISR_Start();
    HE_ISR_SetVector(HE_inter);
    
    PWM_Start();
    PWM_CLK_Start();
    
    for(;;)
    {
    }
}

/* [] END OF FILE */
