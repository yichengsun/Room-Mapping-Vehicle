/*******************************************************************************
* File Name: SEC_TIL_BLACK_TIMER_PM.c
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

#include "SEC_TIL_BLACK_TIMER.h"

static SEC_TIL_BLACK_TIMER_backupStruct SEC_TIL_BLACK_TIMER_backup;


/*******************************************************************************
* Function Name: SEC_TIL_BLACK_TIMER_SaveConfig
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
*  SEC_TIL_BLACK_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SEC_TIL_BLACK_TIMER_SaveConfig(void) 
{
    #if (!SEC_TIL_BLACK_TIMER_UsingFixedFunction)
        SEC_TIL_BLACK_TIMER_backup.TimerUdb = SEC_TIL_BLACK_TIMER_ReadCounter();
        SEC_TIL_BLACK_TIMER_backup.InterruptMaskValue = SEC_TIL_BLACK_TIMER_STATUS_MASK;
        #if (SEC_TIL_BLACK_TIMER_UsingHWCaptureCounter)
            SEC_TIL_BLACK_TIMER_backup.TimerCaptureCounter = SEC_TIL_BLACK_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!SEC_TIL_BLACK_TIMER_UDB_CONTROL_REG_REMOVED)
            SEC_TIL_BLACK_TIMER_backup.TimerControlRegister = SEC_TIL_BLACK_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: SEC_TIL_BLACK_TIMER_RestoreConfig
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
*  SEC_TIL_BLACK_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SEC_TIL_BLACK_TIMER_RestoreConfig(void) 
{   
    #if (!SEC_TIL_BLACK_TIMER_UsingFixedFunction)

        SEC_TIL_BLACK_TIMER_WriteCounter(SEC_TIL_BLACK_TIMER_backup.TimerUdb);
        SEC_TIL_BLACK_TIMER_STATUS_MASK =SEC_TIL_BLACK_TIMER_backup.InterruptMaskValue;
        #if (SEC_TIL_BLACK_TIMER_UsingHWCaptureCounter)
            SEC_TIL_BLACK_TIMER_SetCaptureCount(SEC_TIL_BLACK_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!SEC_TIL_BLACK_TIMER_UDB_CONTROL_REG_REMOVED)
            SEC_TIL_BLACK_TIMER_WriteControlRegister(SEC_TIL_BLACK_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: SEC_TIL_BLACK_TIMER_Sleep
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
*  SEC_TIL_BLACK_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void SEC_TIL_BLACK_TIMER_Sleep(void) 
{
    #if(!SEC_TIL_BLACK_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(SEC_TIL_BLACK_TIMER_CTRL_ENABLE == (SEC_TIL_BLACK_TIMER_CONTROL & SEC_TIL_BLACK_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            SEC_TIL_BLACK_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            SEC_TIL_BLACK_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    SEC_TIL_BLACK_TIMER_Stop();
    SEC_TIL_BLACK_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: SEC_TIL_BLACK_TIMER_Wakeup
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
*  SEC_TIL_BLACK_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SEC_TIL_BLACK_TIMER_Wakeup(void) 
{
    SEC_TIL_BLACK_TIMER_RestoreConfig();
    #if(!SEC_TIL_BLACK_TIMER_UDB_CONTROL_REG_REMOVED)
        if(SEC_TIL_BLACK_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                SEC_TIL_BLACK_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
