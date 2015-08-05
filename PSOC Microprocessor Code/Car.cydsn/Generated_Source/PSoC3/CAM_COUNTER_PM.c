/*******************************************************************************
* File Name: CAM_COUNTER_PM.c  
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

#include "CAM_COUNTER.h"

static CAM_COUNTER_backupStruct CAM_COUNTER_backup;


/*******************************************************************************
* Function Name: CAM_COUNTER_SaveConfig
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
*  CAM_COUNTER_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void CAM_COUNTER_SaveConfig(void) 
{
    #if (!CAM_COUNTER_UsingFixedFunction)

        CAM_COUNTER_backup.CounterUdb = CAM_COUNTER_ReadCounter();

        #if (CY_UDB_V0)
            CAM_COUNTER_backup.CounterPeriod = CAM_COUNTER_ReadPeriod();
            CAM_COUNTER_backup.CompareValue = CAM_COUNTER_ReadCompare();
            CAM_COUNTER_backup.InterruptMaskValue = CAM_COUNTER_STATUS_MASK;
        #endif /* CY_UDB_V0 */

        #if(!CAM_COUNTER_ControlRegRemoved)
            CAM_COUNTER_backup.CounterControlRegister = CAM_COUNTER_ReadControlRegister();
        #endif /* (!CAM_COUNTER_ControlRegRemoved) */

    #endif /* (!CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_RestoreConfig
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
*  CAM_COUNTER_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void CAM_COUNTER_RestoreConfig(void) 
{      
    #if (!CAM_COUNTER_UsingFixedFunction)

        #if (CY_UDB_V0)
            uint8 CAM_COUNTER_interruptState;
        #endif  /* (CY_UDB_V0) */

       CAM_COUNTER_WriteCounter(CAM_COUNTER_backup.CounterUdb);

        #if (CY_UDB_V0)
            CAM_COUNTER_WritePeriod(CAM_COUNTER_backup.CounterPeriod);
            CAM_COUNTER_WriteCompare(CAM_COUNTER_backup.CompareValue);

            CAM_COUNTER_interruptState = CyEnterCriticalSection();
            CAM_COUNTER_STATUS_AUX_CTRL |= CAM_COUNTER_STATUS_ACTL_INT_EN_MASK;
            CyExitCriticalSection(CAM_COUNTER_interruptState);

            CAM_COUNTER_STATUS_MASK = CAM_COUNTER_backup.InterruptMaskValue;
        #endif  /* (CY_UDB_V0) */

        #if(!CAM_COUNTER_ControlRegRemoved)
            CAM_COUNTER_WriteControlRegister(CAM_COUNTER_backup.CounterControlRegister);
        #endif /* (!CAM_COUNTER_ControlRegRemoved) */

    #endif /* (!CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_Sleep
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
*  CAM_COUNTER_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void CAM_COUNTER_Sleep(void) 
{
    #if(!CAM_COUNTER_ControlRegRemoved)
        /* Save Counter's enable state */
        if(CAM_COUNTER_CTRL_ENABLE == (CAM_COUNTER_CONTROL & CAM_COUNTER_CTRL_ENABLE))
        {
            /* Counter is enabled */
            CAM_COUNTER_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            CAM_COUNTER_backup.CounterEnableState = 0u;
        }
    #else
        CAM_COUNTER_backup.CounterEnableState = 1u;
        if(CAM_COUNTER_backup.CounterEnableState != 0u)
        {
            CAM_COUNTER_backup.CounterEnableState = 0u;
        }
    #endif /* (!CAM_COUNTER_ControlRegRemoved) */
    
    CAM_COUNTER_Stop();
    CAM_COUNTER_SaveConfig();
}


/*******************************************************************************
* Function Name: CAM_COUNTER_Wakeup
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
*  CAM_COUNTER_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void CAM_COUNTER_Wakeup(void) 
{
    CAM_COUNTER_RestoreConfig();
    #if(!CAM_COUNTER_ControlRegRemoved)
        if(CAM_COUNTER_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            CAM_COUNTER_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!CAM_COUNTER_ControlRegRemoved) */
    
}


/* [] END OF FILE */
