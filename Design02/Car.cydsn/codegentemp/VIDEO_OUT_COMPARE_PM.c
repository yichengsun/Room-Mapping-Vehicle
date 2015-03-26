/*******************************************************************************
* File Name: VIDEO_OUT_COMPARE.c
* Version 2.0
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "VIDEO_OUT_COMPARE.h"

static VIDEO_OUT_COMPARE_backupStruct VIDEO_OUT_COMPARE_backup;


/*******************************************************************************
* Function Name: VIDEO_OUT_COMPARE_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void VIDEO_OUT_COMPARE_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: VIDEO_OUT_COMPARE_RestoreConfig
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
********************************************************************************/
void VIDEO_OUT_COMPARE_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: VIDEO_OUT_COMPARE_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  VIDEO_OUT_COMPARE_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void VIDEO_OUT_COMPARE_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(VIDEO_OUT_COMPARE_ACT_PWR_EN == (VIDEO_OUT_COMPARE_PWRMGR & VIDEO_OUT_COMPARE_ACT_PWR_EN))
    {
        /* Comp is enabled */
        VIDEO_OUT_COMPARE_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        VIDEO_OUT_COMPARE_backup.enableState = 0u;
    }    
    
    VIDEO_OUT_COMPARE_Stop();
    VIDEO_OUT_COMPARE_SaveConfig();
}


/*******************************************************************************
* Function Name: VIDEO_OUT_COMPARE_Wakeup
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
*  VIDEO_OUT_COMPARE_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VIDEO_OUT_COMPARE_Wakeup(void) 
{
    VIDEO_OUT_COMPARE_RestoreConfig();
    
    if(VIDEO_OUT_COMPARE_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        VIDEO_OUT_COMPARE_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
