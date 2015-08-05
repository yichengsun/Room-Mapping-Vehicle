/*******************************************************************************
* File Name: VERT_SYNC_OUT_IN.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "VERT_SYNC_OUT_IN.h"


/*******************************************************************************
* Function Name: VERT_SYNC_OUT_IN_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void VERT_SYNC_OUT_IN_Write(uint8 value) 
{
    uint8 staticBits = (VERT_SYNC_OUT_IN_DR & (uint8)(~VERT_SYNC_OUT_IN_MASK));
    VERT_SYNC_OUT_IN_DR = staticBits | ((uint8)(value << VERT_SYNC_OUT_IN_SHIFT) & VERT_SYNC_OUT_IN_MASK);
}


/*******************************************************************************
* Function Name: VERT_SYNC_OUT_IN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  VERT_SYNC_OUT_IN_DM_STRONG     Strong Drive 
*  VERT_SYNC_OUT_IN_DM_OD_HI      Open Drain, Drives High 
*  VERT_SYNC_OUT_IN_DM_OD_LO      Open Drain, Drives Low 
*  VERT_SYNC_OUT_IN_DM_RES_UP     Resistive Pull Up 
*  VERT_SYNC_OUT_IN_DM_RES_DWN    Resistive Pull Down 
*  VERT_SYNC_OUT_IN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  VERT_SYNC_OUT_IN_DM_DIG_HIZ    High Impedance Digital 
*  VERT_SYNC_OUT_IN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void VERT_SYNC_OUT_IN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VERT_SYNC_OUT_IN_0, mode);
}


/*******************************************************************************
* Function Name: VERT_SYNC_OUT_IN_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro VERT_SYNC_OUT_IN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VERT_SYNC_OUT_IN_Read(void) 
{
    return (VERT_SYNC_OUT_IN_PS & VERT_SYNC_OUT_IN_MASK) >> VERT_SYNC_OUT_IN_SHIFT;
}


/*******************************************************************************
* Function Name: VERT_SYNC_OUT_IN_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 VERT_SYNC_OUT_IN_ReadDataReg(void) 
{
    return (VERT_SYNC_OUT_IN_DR & VERT_SYNC_OUT_IN_MASK) >> VERT_SYNC_OUT_IN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VERT_SYNC_OUT_IN_INTSTAT) 

    /*******************************************************************************
    * Function Name: VERT_SYNC_OUT_IN_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 VERT_SYNC_OUT_IN_ClearInterrupt(void) 
    {
        return (VERT_SYNC_OUT_IN_INTSTAT & VERT_SYNC_OUT_IN_MASK) >> VERT_SYNC_OUT_IN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
