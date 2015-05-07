#include <project.h>
#include <stdio.h>

#define INCH_PER_MAGNET 1.58
#define SEC_PER_PERIOD 357.914

#define THREE_FT_DUTY 900
#define CENTER_DUTY 4560 
#define CENTER_LINE 780

#define Kp 1250
#define Ki 120
#define Kd 0

#define Kp_steer 2.25
#define Ki_steer 0
#define Kd_steer 30000

double gExpectedSpeed = 3.5;
double gTotalTraveled = 0;

double gprev_HE_count = 0;
int gfirst_HE_read = 1;
int gspeedMeasurements = 0;
double gcurSpeed = 0;
double speedCounts[5];
double gki_speederror = 0;
double gki_steererror = 0;
int glinepos = 0;
double gsteer_dutycycle = 0;

int gnum_line_reads = 0;
double gblack_pos_first_diff = 0;
double gblack_pos_second_diff = 0;
double gblack_totalpos_diff = 0;
int gCounterNReads = 0;
int gblackcount = 0;
uint32 gfirstpos = 0;
uint32 gsecondpos = 0;
uint32 gthirdpos = 0;
uint32 gfourthpos = 0;
uint32 gcaptures = 0;
int count = 0;
int gsteer_error_prev = 0;

uint8 direction = 0;

int gONOFF = 0;
int gcurr_dir = 0;


CY_ISR(DIR_inter) {
    if (gcurr_dir == 0) {
        LCD_ClearDisplay();
        LCD_PrintString("forwards!");
        gcurr_dir = 1;
        DIR_REG_Write(gcurr_dir);
    } 
    else if (gcurr_dir == 1) {
        LCD_ClearDisplay();
        LCD_PrintString("backwards!");
        gcurr_dir = 0;
        DIR_REG_Write(gcurr_dir);
    }
}

CY_ISR(ON_OFF_inter) {
    if (gONOFF == 0) {
        MOTOR_PWM_WriteCompare(2000);
        LCD_ClearDisplay();
        LCD_PrintString("motor on!");
        gONOFF = 1;
    }
    else if (gONOFF == 1) {
        MOTOR_PWM_WriteCompare(0);
        LCD_ClearDisplay();
        LCD_PrintString("motor off!");
        gONOFF = 0;
    }
}

int main()
{
    //initialize all modules
    CYGlobalIntEnable;  
    
    DIR_ISR_Start();
    DIR_ISR_SetVector(DIR_inter);
    
    ON_OFF_ISR_Start();
    ON_OFF_ISR_SetVector(ON_OFF_inter);
    
    LCD_Start();
    LCD_Position(0,0);
    LCD_PrintString("ELE302 Carlab ");
    
    MOTOR_PWM_Start();
    MOTOR_PWM_CLK_Start();
    
    //start off driving forward
    DIR_REG_Write(1);
   
    for(;;)
    {
    }
}