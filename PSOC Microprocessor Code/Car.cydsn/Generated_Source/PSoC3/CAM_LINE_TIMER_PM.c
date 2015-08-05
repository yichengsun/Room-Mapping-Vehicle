/*******************************************************************************
* File Name: CAM_LINE_TIMER_PM.c
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

#include "CAM_LINE_TIMER.h"

static CAM_LINE_TIMER_backupStruct CAM_LINE_TIMER_backup;


/*******************************************************************************
* Function Name: CAM_LINE_TIMER_SaveConfig
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
*  CAM_LINE_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void CAM_LINE_TIMER_SaveConfig(void) 
{
    #if (!CAM_LINE_TIMER_UsingFixedFunction)
        CAM_LINE_TIMER_backup.TimerUdb = CAM_LINE_TIMER_ReadCounter();
        CAM_LINE_TIMER_backup.InterruptMaskValue = CAM_LINE_TIMER_STATUS_MASK;
        #if (CAM_LINE_TIMER_UsingHWCaptureCounter)
            CAM_LINE_TIMER_backup.TimerCaptureCounter = CAM_LINE_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
            CAM_LINE_TIMER_backup.TimerControlRegister = CAM_LINE_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: CAM_LINE_TIMER_RestoreConfig
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
*  CAM_LINE_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CAM_LINE_TIMER_RestoreConfig(void) 
{   
    #if (!CAM_LINE_TIMER_UsingFixedFunction)

        CAM_LINE_TIMER_WriteCounter(CAM_LINE_TIMER_backup.TimerUdb);
        CAM_LINE_TIMER_STATUS_MASK =CAM_LINE_TIMER_backup.InterruptMaskValue;
        #if (CAM_LINE_TIMER_UsingHWCaptureCounter)
            CAM_LINE_TIMER_SetCaptureCount(CAM_LINE_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
            CAM_LINE_TIMER_WriteControlRegister(CAM_LINE_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: CAM_LINE_TIMER_Sleep
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
*  CAM_LINE_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void CAM_LINE_TIMER_Sleep(void) 
{
    #if(!CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(CAM_LINE_TIMER_CTRL_ENABLE == (CAM_LINE_TIMER_CONTROL & CAM_LINE_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            CAM_LINE_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            CAM_LINE_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    CAM_LINE_TIMER_Stop();
    CAM_LINE_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: CAM_LINE_TIMER_Wakeup
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
*  CAM_LINE_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CAM_LINE_TIMER_Wakeup(void) 
{
    CAM_LINE_TIMER_RestoreConfig();
    #if(!CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
        if(CAM_LINE_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                CAM_LINE_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
