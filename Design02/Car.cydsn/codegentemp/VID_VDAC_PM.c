/*******************************************************************************
* File Name: VID_VDAC_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
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

#include "VID_VDAC.h"

static VID_VDAC_backupStruct VID_VDAC_backup;


/*******************************************************************************
* Function Name: VID_VDAC_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void VID_VDAC_SaveConfig(void) 
{
    if (!((VID_VDAC_CR1 & VID_VDAC_SRC_MASK) == VID_VDAC_SRC_UDB))
    {
        VID_VDAC_backup.data_value = VID_VDAC_Data;
    }
}


/*******************************************************************************
* Function Name: VID_VDAC_RestoreConfig
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
*******************************************************************************/
void VID_VDAC_RestoreConfig(void) 
{
    if (!((VID_VDAC_CR1 & VID_VDAC_SRC_MASK) == VID_VDAC_SRC_UDB))
    {
        if((VID_VDAC_Strobe & VID_VDAC_STRB_MASK) == VID_VDAC_STRB_EN)
        {
            VID_VDAC_Strobe &= (uint8)(~VID_VDAC_STRB_MASK);
            VID_VDAC_Data = VID_VDAC_backup.data_value;
            VID_VDAC_Strobe |= VID_VDAC_STRB_EN;
        }
        else
        {
            VID_VDAC_Data = VID_VDAC_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VID_VDAC_Sleep
********************************************************************************
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
*  VID_VDAC_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VID_VDAC_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VID_VDAC_ACT_PWR_EN == (VID_VDAC_PWRMGR & VID_VDAC_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VID_VDAC_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VID_VDAC_backup.enableState = 0u;
    }
    
    VID_VDAC_Stop();
    VID_VDAC_SaveConfig();
}


/*******************************************************************************
* Function Name: VID_VDAC_Wakeup
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
*  VID_VDAC_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VID_VDAC_Wakeup(void) 
{
    VID_VDAC_RestoreConfig();
    
    if(VID_VDAC_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VID_VDAC_Enable();

        /* Restore the data register */
        VID_VDAC_SetValue(VID_VDAC_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
