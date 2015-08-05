/*******************************************************************************
* File Name: STEERING_PWM_PM.c
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

#include "STEERING_PWM.h"

static STEERING_PWM_backupStruct STEERING_PWM_backup;


/*******************************************************************************
* Function Name: STEERING_PWM_SaveConfig
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
*  STEERING_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void STEERING_PWM_SaveConfig(void) 
{

    #if(!STEERING_PWM_UsingFixedFunction)
        #if(!STEERING_PWM_PWMModeIsCenterAligned)
            STEERING_PWM_backup.PWMPeriod = STEERING_PWM_ReadPeriod();
        #endif /* (!STEERING_PWM_PWMModeIsCenterAligned) */
        STEERING_PWM_backup.PWMUdb = STEERING_PWM_ReadCounter();
        #if (STEERING_PWM_UseStatus)
            STEERING_PWM_backup.InterruptMaskValue = STEERING_PWM_STATUS_MASK;
        #endif /* (STEERING_PWM_UseStatus) */

        #if(STEERING_PWM_DeadBandMode == STEERING_PWM__B_PWM__DBM_256_CLOCKS || \
            STEERING_PWM_DeadBandMode == STEERING_PWM__B_PWM__DBM_2_4_CLOCKS)
            STEERING_PWM_backup.PWMdeadBandValue = STEERING_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(STEERING_PWM_KillModeMinTime)
             STEERING_PWM_backup.PWMKillCounterPeriod = STEERING_PWM_ReadKillTime();
        #endif /* (STEERING_PWM_KillModeMinTime) */

        #if(STEERING_PWM_UseControl)
            STEERING_PWM_backup.PWMControlRegister = STEERING_PWM_ReadControlRegister();
        #endif /* (STEERING_PWM_UseControl) */
    #endif  /* (!STEERING_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: STEERING_PWM_RestoreConfig
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
*  STEERING_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void STEERING_PWM_RestoreConfig(void) 
{
        #if(!STEERING_PWM_UsingFixedFunction)
            #if(!STEERING_PWM_PWMModeIsCenterAligned)
                STEERING_PWM_WritePeriod(STEERING_PWM_backup.PWMPeriod);
            #endif /* (!STEERING_PWM_PWMModeIsCenterAligned) */

            STEERING_PWM_WriteCounter(STEERING_PWM_backup.PWMUdb);

            #if (STEERING_PWM_UseStatus)
                STEERING_PWM_STATUS_MASK = STEERING_PWM_backup.InterruptMaskValue;
            #endif /* (STEERING_PWM_UseStatus) */

            #if(STEERING_PWM_DeadBandMode == STEERING_PWM__B_PWM__DBM_256_CLOCKS || \
                STEERING_PWM_DeadBandMode == STEERING_PWM__B_PWM__DBM_2_4_CLOCKS)
                STEERING_PWM_WriteDeadTime(STEERING_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(STEERING_PWM_KillModeMinTime)
                STEERING_PWM_WriteKillTime(STEERING_PWM_backup.PWMKillCounterPeriod);
            #endif /* (STEERING_PWM_KillModeMinTime) */

            #if(STEERING_PWM_UseControl)
                STEERING_PWM_WriteControlRegister(STEERING_PWM_backup.PWMControlRegister);
            #endif /* (STEERING_PWM_UseControl) */
        #endif  /* (!STEERING_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: STEERING_PWM_Sleep
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
*  STEERING_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void STEERING_PWM_Sleep(void) 
{
    #if(STEERING_PWM_UseControl)
        if(STEERING_PWM_CTRL_ENABLE == (STEERING_PWM_CONTROL & STEERING_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            STEERING_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            STEERING_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (STEERING_PWM_UseControl) */

    /* Stop component */
    STEERING_PWM_Stop();

    /* Save registers configuration */
    STEERING_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: STEERING_PWM_Wakeup
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
*  STEERING_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void STEERING_PWM_Wakeup(void) 
{
     /* Restore registers values */
    STEERING_PWM_RestoreConfig();

    if(STEERING_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        STEERING_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
