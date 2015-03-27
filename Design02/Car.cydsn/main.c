#include <project.h>
#include <stdio.h>

#define INCH_PER_MAGNET 1.58
#define SEC_PER_PERIOD 357.914
#define EXPECTED_SPEED 3.5
#define THREE_FT_DUTY 900
#define CENTER_DUTY 4560 

#define Kp 5250
#define Ki 400
#define Kd 0

#define Kp_steer 100
#define Ki_steer 50
#define Kd_steer 0

double gprev_HE_count = 0;
int gfirst_HE_read = 1;
int gspeedMeasurements = 0;
double gcurSpeed = 0;
double speedCounts[5];
double gki_speederror = 0;
double gki_steererror = 0;
int glinepos = 0;

int gnum_line_reads = 0;
double gblack_pos_first_diff = 0;
double gblack_pos_second_diff = 0;
double gblack_totalpos_diff = 0;
int gCounterNReads = 0;
int gblackcount = 0;
uint32 gfirstpos;
uint32 gsecondpos;

//Averages out speed for the last wheel rotation to even out magnet spacing
double getSpeedAvg(double speeds[]){
    double counter = 0;
    uint32 i = 0;
    uint32 size = 5;
    if (gspeedMeasurements < 5) {
        size = gspeedMeasurements;
    }
    for (i = 0; i < size; i++){
        counter = counter + speeds[i];   
    }
    return counter/(double)size;
}

//Grab current speed via unit conversions
double getCurSpeed(){
    double current_Speed = 0;
    //average clock tix b/w two magnets in one rotation
    current_Speed = getSpeedAvg(speedCounts);
    //average sec elapsed b/w two magnets
    current_Speed = (double)current_Speed/HE_TIMER_ReadPeriod() * SEC_PER_PERIOD;
    //average speed b/w two magnets
    current_Speed = (double)INCH_PER_MAGNET/current_Speed/12;
    // return (double)current_Speed;
    return current_Speed;
}

//CY_ISR(COUNTER_N_inter) {
//    LINE_COUNTER_ReadStatusRegister();
//    
//    if (gCounterNReads == 2){
//        LINE_COUNTER_Stop();   
//    }
//    else if (gCounterNReads == 0) {
//        int multiples = 20+80;
//        LINE_COUNTER_WriteCompare(multiples);
//    } 
//    gCounterNReads += 1;
//}

CY_ISR(SEC_TIL_BLACK_TIMER_inter) {
    char buffer[15];

    
    gfirstpos = SEC_TIL_BLACK_TIMER_ReadCapture();
    gsecondpos = SEC_TIL_BLACK_TIMER_ReadCapture();
    gsecondpos = SEC_TIL_BLACK_TIMER_ReadCapture();
    SEC_TIL_BLACK_TIMER_ClearFIFO();
    
    gblack_totalpos_diff = (double)(gfirstpos - gsecondpos);
//    if (gnum_line_reads == 0) {
//        gnum_line_reads = 1;
//        gblack_pos_first_diff = (double)(firstpos - secondpos);
//    } else {
//        gnum_line_reads = 0;
//        gblack_pos_second_diff = (double)(firstpos - secondpos);
//        gblack_totalpos_diff = gblack_pos_first_diff - gblack_pos_second_diff;
//    }
        SEC_TIL_BLACK_TIMER_ReadStatusRegister();

    }

//Interrupt on each hall effect sensor passing by to update speed and PWM duty cycle
CY_ISR(HE_inter) {
//    double curr_HE_count = 0;
//    double time_diff = 0;
//    double time_diff_s = 0;
//    double error = 0;
//    double PID_speed = 0;
//    char buffer[15];
//    double duty_cycle_buffer = 0;
//    uint16 duty_cycle = 0;
//    
//    //Special first time read   
//    if (gfirst_HE_read == 1) {
//        gprev_HE_count = HE_TIMER_ReadCounter();
//        gfirst_HE_read = 0;
//    } 
//    else {
//        curr_HE_count = HE_TIMER_ReadCounter();
//        if (gprev_HE_count < curr_HE_count) {
//            gprev_HE_count = gprev_HE_count + HE_TIMER_ReadPeriod();
//        }
//
//        //Calculate the time difference between each magnet passing by
//        time_diff = gprev_HE_count - curr_HE_count;
//        time_diff_s = time_diff/HE_TIMER_ReadPeriod() * SEC_PER_PERIOD;
//        
//        speedCounts[gspeedMeasurements%5] = time_diff;
//        gspeedMeasurements++;
//        gcurSpeed = getCurSpeed();
//        gprev_HE_count = curr_HE_count;
//        //Calculate the error for feedback 
//        error = EXPECTED_SPEED - gcurSpeed;
//        //Accumulate past errors for Ki
//        gki_speederror = gki_speederror+error*time_diff_s;
//        // Discard saved error from acceleration as it becomes less relevant after starting
//        if (gspeedMeasurements == 28) gki_speederror = 0;
//        //Calculate the duty cycle based upon Kp, Ki, and Kd
//        duty_cycle_buffer = THREE_FT_DUTY + Kp*error + Ki*gki_speederror + Kd*error/time_diff_s;
//        
//        //LCD output for debugging
//        LCD_ClearDisplay();
//        LCD_Position(0,0);
//        sprintf(buffer, "%f", error);        
//        LCD_PrintString(buffer);
//        LCD_PrintString("//");
//        sprintf(buffer, "%f", Kd*error/time_diff_s);
//        LCD_PrintString(buffer);
//        
//        //Have in place error checking to ensure duty cycle goes to 1 if negative and caps at a 
//        //certain duty cycle to prevent sporadic  behavior
//        if (duty_cycle_buffer > 4000){
//            duty_cycle_buffer = 1350;   
//        }
//        if (duty_cycle_buffer <= 0) duty_cycle_buffer = 1;
//        duty_cycle = duty_cycle_buffer;
//        
//        //more LCD debugging code
//        LCD_Position(1, 0);
//        //sprintf(buffer, "%f", duty_cycle);
//        LCD_PrintNumber(duty_cycle);
//        MOTOR_PWM_WriteCompare(duty_cycle);
//    }
    double error;   
    double duty_cycle_buffer;
    uint16 duty_cycle;
    char buffer[10];
    
   // UPDATE_STEERING_TIMER_ReadStatusRegister();
    
    //Calculate the error for feedback 
    error = gblack_totalpos_diff - 780;
        //Accumulate past errors for Ki
    // left max 3600; center 4560; right max 5800
    gki_steererror = gki_steererror+error*.000011;
    duty_cycle_buffer = CENTER_DUTY - Kp_steer*error; //+ Ki_steer*gki_steererror;

    //Have in place error checking to prevent sporadic  behavior
    if (duty_cycle_buffer > 5600){
        duty_cycle_buffer = 5600;   
    }
    if (duty_cycle_buffer <= 3600) {
        duty_cycle_buffer = 3600;
    }
    duty_cycle = duty_cycle_buffer;

    LCD_ClearDisplay();
    LCD_Position(0,0);
    sprintf(buffer, "%f", error);
    LCD_PrintString(buffer);
    LCD_Position(1, 0);
    sprintf(buffer, "%f", gblack_totalpos_diff);
    LCD_PrintString(buffer);
    
        //LCD output for debugging
//    LCD_ClearDisplay();
//    LCD_Position(0,0);
//    sprintf(buffer, "%f", error);        
//    LCD_PrintString(buffer);
    
//     //more LCD debugging code
//    LCD_Position(1, 0);
//     //sprintf(buffer, "%f", duty_cycle);
//    LCD_PrintNumber(duty_cycle);

    STEERING_PWM_WriteCompare(duty_cycle);
}

/*CY_ISR(UPDATE_STEERING_inter) {
    double error;   
    double duty_cycle_buffer;
    uint16 duty_cycle;
    char buffer[10];
    
    //UPDATE_STEERING_TIMER_ReadStatusRegister();
    
    //Calculate the error for feedback 
    error = gblack_totalpos_diff;
        //Accumulate past errors for Ki
    // left max 3600; center 4560; right max 5800
    gki_steererror = gki_steererror+error*.000011;
    duty_cycle_buffer = CENTER_DUTY + Kp_steer*error; //+ Ki_steer*gki_steererror;

    //Have in place error checking to prevent sporadic  behavior
    if (duty_cycle_buffer > 5600){
        duty_cycle_buffer = 5600;   
    }
    if (duty_cycle_buffer <= 3600) {
        duty_cycle_buffer = 3600;
    }
    duty_cycle = duty_cycle_buffer;

        //LCD output for debugging
//    LCD_ClearDisplay();
//    LCD_Position(0,0);
//    sprintf(buffer, "%f", error);        
//    LCD_PrintString(buffer);
    
//     //more LCD debugging code
//    LCD_Position(1, 0);
//     //sprintf(buffer, "%f", duty_cycle);
//    LCD_PrintNumber(duty_cycle);

    STEERING_PWM_WriteCompare(duty_cycle);
}
*/

int main()
{
    //initialize all modules
    CYGlobalIntEnable;  
    HE_TIMER_Start();
    HE_ISR_Start();
    HE_ISR_SetVector(HE_inter);
    MOTOR_PWM_Start();
    MOTOR_PWM_CLK_Start();
    
    LINE_COUNTER_Start();
    //COUNTER_N_ISR_Start();
    //COUNTER_N_ISR_SetVector(COUNTER_N_inter);   
    SEC_TIL_BLACK_TIMER_Start();
    SEC_TIL_BLACK_TIMER_ISR_Start();
    SEC_TIL_BLACK_TIMER_ISR_SetVector(SEC_TIL_BLACK_TIMER_inter);
    
    //UPDATE_STEERING_TIMER_Start();
    //UPDATE_STEERING_ISR_Start();
    //UPDATE_STEERING_ISR_SetVector(UPDATE_STEERING_inter);
    
    STEERING_PWM_Start();
    STEERING_PWM_CLK_Start();
    
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("ELE302 Carlab");
    
    for(;;)
    {
    }
}
/* [] END OF FILE */