/*******************************************************************************
* File Name: MOTOR_PWM_PM.c
* Version 3.10
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "MOTOR_PWM.h"

static MOTOR_PWM_backupStruct MOTOR_PWM_backup;


/*******************************************************************************
* Function Name: MOTOR_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void MOTOR_PWM_SaveConfig(void) 
{

    #if(!MOTOR_PWM_UsingFixedFunction)
        #if(!MOTOR_PWM_PWMModeIsCenterAligned)
            MOTOR_PWM_backup.PWMPeriod = MOTOR_PWM_ReadPeriod();
        #endif /* (!MOTOR_PWM_PWMModeIsCenterAligned) */
        MOTOR_PWM_backup.PWMUdb = MOTOR_PWM_ReadCounter();
        #if (MOTOR_PWM_UseStatus)
            MOTOR_PWM_backup.InterruptMaskValue = MOTOR_PWM_STATUS_MASK;
        #endif /* (MOTOR_PWM_UseStatus) */

        #if(MOTOR_PWM_DeadBandMode == MOTOR_PWM__B_PWM__DBM_256_CLOCKS || \
            MOTOR_PWM_DeadBandMode == MOTOR_PWM__B_PWM__DBM_2_4_CLOCKS)
            MOTOR_PWM_backup.PWMdeadBandValue = MOTOR_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(MOTOR_PWM_KillModeMinTime)
             MOTOR_PWM_backup.PWMKillCounterPeriod = MOTOR_PWM_ReadKillTime();
        #endif /* (MOTOR_PWM_KillModeMinTime) */

        #if(MOTOR_PWM_UseControl)
            MOTOR_PWM_backup.PWMControlRegister = MOTOR_PWM_ReadControlRegister();
        #endif /* (MOTOR_PWM_UseControl) */
    #endif  /* (!MOTOR_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: MOTOR_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void MOTOR_PWM_RestoreConfig(void) 
{
        #if(!MOTOR_PWM_UsingFixedFunction)
            #if(!MOTOR_PWM_PWMModeIsCenterAligned)
                MOTOR_PWM_WritePeriod(MOTOR_PWM_backup.PWMPeriod);
            #endif /* (!MOTOR_PWM_PWMModeIsCenterAligned) */

            MOTOR_PWM_WriteCounter(MOTOR_PWM_backup.PWMUdb);

            #if (MOTOR_PWM_UseStatus)
                MOTOR_PWM_STATUS_MASK = MOTOR_PWM_backup.InterruptMaskValue;
            #endif /* (MOTOR_PWM_UseStatus) */

            #if(MOTOR_PWM_DeadBandMode == MOTOR_PWM__B_PWM__DBM_256_CLOCKS || \
                MOTOR_PWM_DeadBandMode == MOTOR_PWM__B_PWM__DBM_2_4_CLOCKS)
                MOTOR_PWM_WriteDeadTime(MOTOR_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(MOTOR_PWM_KillModeMinTime)
                MOTOR_PWM_WriteKillTime(MOTOR_PWM_backup.PWMKillCounterPeriod);
            #endif /* (MOTOR_PWM_KillModeMinTime) */

            #if(MOTOR_PWM_UseControl)
                MOTOR_PWM_WriteControlRegister(MOTOR_PWM_backup.PWMControlRegister);
            #endif /* (MOTOR_PWM_UseControl) */
        #endif  /* (!MOTOR_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: MOTOR_PWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void MOTOR_PWM_Sleep(void) 
{
    #if(MOTOR_PWM_UseControl)
        if(MOTOR_PWM_CTRL_ENABLE == (MOTOR_PWM_CONTROL & MOTOR_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            MOTOR_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            MOTOR_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (MOTOR_PWM_UseControl) */

    /* Stop component */
    MOTOR_PWM_Stop();

    /* Save registers configuration */
    MOTOR_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: MOTOR_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  MOTOR_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void MOTOR_PWM_Wakeup(void) 
{
     /* Restore registers values */
    MOTOR_PWM_RestoreConfig();

    if(MOTOR_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        MOTOR_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
