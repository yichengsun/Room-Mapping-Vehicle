/*******************************************************************************
* File Name: HE_TIMER_PM.c
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

#include "HE_TIMER.h"

static HE_TIMER_backupStruct HE_TIMER_backup;


/*******************************************************************************
* Function Name: HE_TIMER_SaveConfig
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
*  HE_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void HE_TIMER_SaveConfig(void) 
{
    #if (!HE_TIMER_UsingFixedFunction)
        HE_TIMER_backup.TimerUdb = HE_TIMER_ReadCounter();
        HE_TIMER_backup.InterruptMaskValue = HE_TIMER_STATUS_MASK;
        #if (HE_TIMER_UsingHWCaptureCounter)
            HE_TIMER_backup.TimerCaptureCounter = HE_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!HE_TIMER_UDB_CONTROL_REG_REMOVED)
            HE_TIMER_backup.TimerControlRegister = HE_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: HE_TIMER_RestoreConfig
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
*  HE_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void HE_TIMER_RestoreConfig(void) 
{   
    #if (!HE_TIMER_UsingFixedFunction)

        HE_TIMER_WriteCounter(HE_TIMER_backup.TimerUdb);
        HE_TIMER_STATUS_MASK =HE_TIMER_backup.InterruptMaskValue;
        #if (HE_TIMER_UsingHWCaptureCounter)
            HE_TIMER_SetCaptureCount(HE_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!HE_TIMER_UDB_CONTROL_REG_REMOVED)
            HE_TIMER_WriteControlRegister(HE_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: HE_TIMER_Sleep
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
*  HE_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void HE_TIMER_Sleep(void) 
{
    #if(!HE_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(HE_TIMER_CTRL_ENABLE == (HE_TIMER_CONTROL & HE_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            HE_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            HE_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    HE_TIMER_Stop();
    HE_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: HE_TIMER_Wakeup
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
*  HE_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void HE_TIMER_Wakeup(void) 
{
    HE_TIMER_RestoreConfig();
    #if(!HE_TIMER_UDB_CONTROL_REG_REMOVED)
        if(HE_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                HE_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
