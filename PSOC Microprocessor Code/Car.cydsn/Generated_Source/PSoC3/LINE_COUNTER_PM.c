/*******************************************************************************
* File Name: LINE_COUNTER_PM.c  
* Version 2.40
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "LINE_COUNTER.h"

static LINE_COUNTER_backupStruct LINE_COUNTER_backup;


/*******************************************************************************
* Function Name: LINE_COUNTER_SaveConfig
********************************************************************************
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
*  LINE_COUNTER_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void LINE_COUNTER_SaveConfig(void) 
{
    #if (!LINE_COUNTER_UsingFixedFunction)

        LINE_COUNTER_backup.CounterUdb = LINE_COUNTER_ReadCounter();

        #if (CY_UDB_V0)
            LINE_COUNTER_backup.CounterPeriod = LINE_COUNTER_ReadPeriod();
            LINE_COUNTER_backup.CompareValue = LINE_COUNTER_ReadCompare();
            LINE_COUNTER_backup.InterruptMaskValue = LINE_COUNTER_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!LINE_COUNTER_ControlRegRemoved)
            LINE_COUNTER_backup.CounterControlRegister = LINE_COUNTER_ReadControlRegister();
        #endif /* (!LINE_COUNTER_ControlRegRemoved) */

    #endif /* (!LINE_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LINE_COUNTER_RestoreConfig
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
*  LINE_COUNTER_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void LINE_COUNTER_RestoreConfig(void) 
{      
    #if (!LINE_COUNTER_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 LINE_COUNTER_interruptState;
        #endif  /* (CY_UDB_V0) */

       LINE_COUNTER_WriteCounter(LINE_COUNTER_backup.CounterUdb);

        #if (CY_UDB_V0)
            LINE_COUNTER_WritePeriod(LINE_COUNTER_backup.CounterPeriod);
            LINE_COUNTER_WriteCompare(LINE_COUNTER_backup.CompareValue);

            LINE_COUNTER_interruptState = CyEnterCriticalSection();
            LINE_COUNTER_STATUS_AUX_CTRL |= LINE_COUNTER_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(LINE_COUNTER_interruptState);

            LINE_COUNTER_STATUS_MASK = LINE_COUNTER_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!LINE_COUNTER_ControlRegRemoved)
            LINE_COUNTER_WriteControlRegister(LINE_COUNTER_backup.CounterControlRegister);
        #endif /* (!LINE_COUNTER_ControlRegRemoved) */

    #endif /* (!LINE_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: LINE_COUNTER_Sleep
********************************************************************************
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
*  LINE_COUNTER_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void LINE_COUNTER_Sleep(void) 
{
    #if(!LINE_COUNTER_ControlRegRemoved)
        /* Save Counter's enable state */
        if(LINE_COUNTER_CTRL_ENABLE == (LINE_COUNTER_CONTROL & LINE_COUNTER_CTRL_ENABLE))
        {
            /* Counter is enabled */
            LINE_COUNTER_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            LINE_COUNTER_backup.CounterEnableState = 0u;
        }
    #else
        LINE_COUNTER_backup.CounterEnableState = 1u;
        if(LINE_COUNTER_backup.CounterEnableState != 0u)
        {
            LINE_COUNTER_backup.CounterEnableState = 0u;
        }
    #endif /* (!LINE_COUNTER_ControlRegRemoved) */
    
    LINE_COUNTER_Stop();
    LINE_COUNTER_SaveConfig();
}


/*******************************************************************************
* Function Name: LINE_COUNTER_Wakeup
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
*  LINE_COUNTER_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void LINE_COUNTER_Wakeup(void) 
{
    LINE_COUNTER_RestoreConfig();
    #if(!LINE_COUNTER_ControlRegRemoved)
        if(LINE_COUNTER_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            LINE_COUNTER_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!LINE_COUNTER_ControlRegRemoved) */
    
}


/* [] END OF FILE */
