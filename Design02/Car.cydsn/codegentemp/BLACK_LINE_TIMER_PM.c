/*******************************************************************************
* File Name: BLACK_LINE_TIMER_PM.c
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

#include "BLACK_LINE_TIMER.h"

static BLACK_LINE_TIMER_backupStruct BLACK_LINE_TIMER_backup;


/*******************************************************************************
* Function Name: BLACK_LINE_TIMER_SaveConfig
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
*  BLACK_LINE_TIMER_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void BLACK_LINE_TIMER_SaveConfig(void) 
{
    #if (!BLACK_LINE_TIMER_UsingFixedFunction)
        BLACK_LINE_TIMER_backup.TimerUdb = BLACK_LINE_TIMER_ReadCounter();
        BLACK_LINE_TIMER_backup.InterruptMaskValue = BLACK_LINE_TIMER_STATUS_MASK;
        #if (BLACK_LINE_TIMER_UsingHWCaptureCounter)
            BLACK_LINE_TIMER_backup.TimerCaptureCounter = BLACK_LINE_TIMER_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!BLACK_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
            BLACK_LINE_TIMER_backup.TimerControlRegister = BLACK_LINE_TIMER_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: BLACK_LINE_TIMER_RestoreConfig
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
*  BLACK_LINE_TIMER_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void BLACK_LINE_TIMER_RestoreConfig(void) 
{   
    #if (!BLACK_LINE_TIMER_UsingFixedFunction)

        BLACK_LINE_TIMER_WriteCounter(BLACK_LINE_TIMER_backup.TimerUdb);
        BLACK_LINE_TIMER_STATUS_MASK =BLACK_LINE_TIMER_backup.InterruptMaskValue;
        #if (BLACK_LINE_TIMER_UsingHWCaptureCounter)
            BLACK_LINE_TIMER_SetCaptureCount(BLACK_LINE_TIMER_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!BLACK_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
            BLACK_LINE_TIMER_WriteControlRegister(BLACK_LINE_TIMER_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: BLACK_LINE_TIMER_Sleep
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
*  BLACK_LINE_TIMER_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void BLACK_LINE_TIMER_Sleep(void) 
{
    #if(!BLACK_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(BLACK_LINE_TIMER_CTRL_ENABLE == (BLACK_LINE_TIMER_CONTROL & BLACK_LINE_TIMER_CTRL_ENABLE))
        {
            /* Timer is enabled */
            BLACK_LINE_TIMER_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            BLACK_LINE_TIMER_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    BLACK_LINE_TIMER_Stop();
    BLACK_LINE_TIMER_SaveConfig();
}


/*******************************************************************************
* Function Name: BLACK_LINE_TIMER_Wakeup
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
*  BLACK_LINE_TIMER_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void BLACK_LINE_TIMER_Wakeup(void) 
{
    BLACK_LINE_TIMER_RestoreConfig();
    #if(!BLACK_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
        if(BLACK_LINE_TIMER_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                BLACK_LINE_TIMER_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
