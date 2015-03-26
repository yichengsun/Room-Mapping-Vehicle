/*******************************************************************************
* File Name: UPDATE_STEERING_TIMER_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "UPDATE_STEERING_TIMER.h"

static UPDATE_STEERING_TIMER_backupStruct UPDATE_STEERING_TIMER_backup;


/*******************************************************************************
* Function Name: UPDATE_STEERING_TIMER_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  UPDATE_STEERING_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void UPDATE_STEERING_TIMER_SaveConfig(void) 
{
    #if (!UPDATE_STEERING_TIMER_UsingFixedFunction)
        UPDATE_STEERING_TIMER_backup.TimerUdb = UPDATE_STEERING_TIMER_ReadCounter();
        UPDATE_STEERING_TIMER_backup.InterruptMaskValue = UPDATE_STEERING_TIMER_STATUS_MASK;
        #if (UPDATE_STEERING_TIMER_UsingHWCaptureCounter)
            UPDATE_STEERING_TIMER_backup.TimerCaptureCounter = UPDATE_STEERING_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED)
            UPDATE_STEERING_TIMER_backup.TimerControlRegister = UPDATE_STEERING_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: UPDATE_STEERING_TIMER_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  UPDATE_STEERING_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void UPDATE_STEERING_TIMER_RestoreConfig(void) 
{   
    #if (!UPDATE_STEERING_TIMER_UsingFixedFunction)

        UPDATE_STEERING_TIMER_WriteCounter(UPDATE_STEERING_TIMER_backup.TimerUdb);
        UPDATE_STEERING_TIMER_STATUS_MASK =UPDATE_STEERING_TIMER_backup.InterruptMaskValue;
        #if (UPDATE_STEERING_TIMER_UsingHWCaptureCounter)
            UPDATE_STEERING_TIMER_SetCaptureCount(UPDATE_STEERING_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED)
            UPDATE_STEERING_TIMER_WriteControlRegister(UPDATE_STEERING_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: UPDATE_STEERING_TIMER_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  UPDATE_STEERING_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void UPDATE_STEERING_TIMER_Sleep(void) 
{
    #if(!UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(UPDATE_STEERING_TIMER_CTRL_ENABLE == (UPDATE_STEERING_TIMER_CONTROL & UPDATE_STEERING_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            UPDATE_STEERING_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            UPDATE_STEERING_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    UPDATE_STEERING_TIMER_Stop();
    UPDATE_STEERING_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: UPDATE_STEERING_TIMER_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  UPDATE_STEERING_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void UPDATE_STEERING_TIMER_Wakeup(void) 
{
    UPDATE_STEERING_TIMER_RestoreConfig();
    #if(!UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED)
        if(UPDATE_STEERING_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                UPDATE_STEERING_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
