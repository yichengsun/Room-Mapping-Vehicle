/*******************************************************************************
* File Name: CAM_TIIMER_PM.c
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

#include "CAM_TIIMER.h"

static CAM_TIIMER_backupStruct CAM_TIIMER_backup;


/*******************************************************************************
* Function Name: CAM_TIIMER_SaveConfig
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
*  CAM_TIIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void CAM_TIIMER_SaveConfig(void) 
{
    #if (!CAM_TIIMER_UsingFixedFunction)
        CAM_TIIMER_backup.TimerUdb = CAM_TIIMER_ReadCounter();
        CAM_TIIMER_backup.InterruptMaskValue = CAM_TIIMER_STATUS_MASK;
        #if (CAM_TIIMER_UsingHWCaptureCounter)
            CAM_TIIMER_backup.TimerCaptureCounter = CAM_TIIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!CAM_TIIMER_UDB_CONTROL_REG_REMOVED)
            CAM_TIIMER_backup.TimerControlRegister = CAM_TIIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: CAM_TIIMER_RestoreConfig
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
*  CAM_TIIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CAM_TIIMER_RestoreConfig(void) 
{   
    #if (!CAM_TIIMER_UsingFixedFunction)

        CAM_TIIMER_WriteCounter(CAM_TIIMER_backup.TimerUdb);
        CAM_TIIMER_STATUS_MASK =CAM_TIIMER_backup.InterruptMaskValue;
        #if (CAM_TIIMER_UsingHWCaptureCounter)
            CAM_TIIMER_SetCaptureCount(CAM_TIIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!CAM_TIIMER_UDB_CONTROL_REG_REMOVED)
            CAM_TIIMER_WriteControlRegister(CAM_TIIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: CAM_TIIMER_Sleep
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
*  CAM_TIIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void CAM_TIIMER_Sleep(void) 
{
    #if(!CAM_TIIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(CAM_TIIMER_CTRL_ENABLE == (CAM_TIIMER_CONTROL & CAM_TIIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            CAM_TIIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            CAM_TIIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    CAM_TIIMER_Stop();
    CAM_TIIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: CAM_TIIMER_Wakeup
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
*  CAM_TIIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CAM_TIIMER_Wakeup(void) 
{
    CAM_TIIMER_RestoreConfig();
    #if(!CAM_TIIMER_UDB_CONTROL_REG_REMOVED)
        if(CAM_TIIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                CAM_TIIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
