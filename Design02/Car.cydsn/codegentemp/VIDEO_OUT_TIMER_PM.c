/*******************************************************************************
* File Name: VIDEO_OUT_TIMER_PM.c
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

#include "VIDEO_OUT_TIMER.h"

static VIDEO_OUT_TIMER_backupStruct VIDEO_OUT_TIMER_backup;


/*******************************************************************************
* Function Name: VIDEO_OUT_TIMER_SaveConfig
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
*  VIDEO_OUT_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void VIDEO_OUT_TIMER_SaveConfig(void) 
{
    #if (!VIDEO_OUT_TIMER_UsingFixedFunction)
        VIDEO_OUT_TIMER_backup.TimerUdb = VIDEO_OUT_TIMER_ReadCounter();
        VIDEO_OUT_TIMER_backup.InterruptMaskValue = VIDEO_OUT_TIMER_STATUS_MASK;
        #if (VIDEO_OUT_TIMER_UsingHWCaptureCounter)
            VIDEO_OUT_TIMER_backup.TimerCaptureCounter = VIDEO_OUT_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!VIDEO_OUT_TIMER_UDB_CONTROL_REG_REMOVED)
            VIDEO_OUT_TIMER_backup.TimerControlRegister = VIDEO_OUT_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: VIDEO_OUT_TIMER_RestoreConfig
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
*  VIDEO_OUT_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void VIDEO_OUT_TIMER_RestoreConfig(void) 
{   
    #if (!VIDEO_OUT_TIMER_UsingFixedFunction)

        VIDEO_OUT_TIMER_WriteCounter(VIDEO_OUT_TIMER_backup.TimerUdb);
        VIDEO_OUT_TIMER_STATUS_MASK =VIDEO_OUT_TIMER_backup.InterruptMaskValue;
        #if (VIDEO_OUT_TIMER_UsingHWCaptureCounter)
            VIDEO_OUT_TIMER_SetCaptureCount(VIDEO_OUT_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!VIDEO_OUT_TIMER_UDB_CONTROL_REG_REMOVED)
            VIDEO_OUT_TIMER_WriteControlRegister(VIDEO_OUT_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: VIDEO_OUT_TIMER_Sleep
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
*  VIDEO_OUT_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void VIDEO_OUT_TIMER_Sleep(void) 
{
    #if(!VIDEO_OUT_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(VIDEO_OUT_TIMER_CTRL_ENABLE == (VIDEO_OUT_TIMER_CONTROL & VIDEO_OUT_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            VIDEO_OUT_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            VIDEO_OUT_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    VIDEO_OUT_TIMER_Stop();
    VIDEO_OUT_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: VIDEO_OUT_TIMER_Wakeup
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
*  VIDEO_OUT_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VIDEO_OUT_TIMER_Wakeup(void) 
{
    VIDEO_OUT_TIMER_RestoreConfig();
    #if(!VIDEO_OUT_TIMER_UDB_CONTROL_REG_REMOVED)
        if(VIDEO_OUT_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                VIDEO_OUT_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
