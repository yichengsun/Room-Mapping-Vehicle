/*******************************************************************************
* File Name: VID_COMPARE.c
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

#include "VID_COMPARE.h"

static VID_COMPARE_backupStruct VID_COMPARE_backup;


/*******************************************************************************
* Function Name: VID_COMPARE_SaveConfig
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
void VID_COMPARE_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: VID_COMPARE_RestoreConfig
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
void VID_COMPARE_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: VID_COMPARE_Sleep
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
*  VID_COMPARE_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void VID_COMPARE_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(VID_COMPARE_ACT_PWR_EN == (VID_COMPARE_PWRMGR & VID_COMPARE_ACT_PWR_EN))
    {
        /* Comp is enabled */
        VID_COMPARE_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        VID_COMPARE_backup.enableState = 0u;
    }    
    
    VID_COMPARE_Stop();
    VID_COMPARE_SaveConfig();
}


/*******************************************************************************
* Function Name: VID_COMPARE_Wakeup
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
*  VID_COMPARE_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VID_COMPARE_Wakeup(void) 
{
    VID_COMPARE_RestoreConfig();
    
    if(VID_COMPARE_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        VID_COMPARE_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
