/*******************************************************************************
* File Name: COMP_VREF.c  
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
#include "COMP_VREF.h"


/*******************************************************************************
* Function Name: COMP_VREF_Write
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
void COMP_VREF_Write(uint8 value) 
{
    uint8 staticBits = (COMP_VREF_DR & (uint8)(~COMP_VREF_MASK));
    COMP_VREF_DR = staticBits | ((uint8)(value << COMP_VREF_SHIFT) & COMP_VREF_MASK);
}


/*******************************************************************************
* Function Name: COMP_VREF_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  COMP_VREF_DM_STRONG     Strong Drive 
*  COMP_VREF_DM_OD_HI      Open Drain, Drives High 
*  COMP_VREF_DM_OD_LO      Open Drain, Drives Low 
*  COMP_VREF_DM_RES_UP     Resistive Pull Up 
*  COMP_VREF_DM_RES_DWN    Resistive Pull Down 
*  COMP_VREF_DM_RES_UPDWN  Resistive Pull Up/Down 
*  COMP_VREF_DM_DIG_HIZ    High Impedance Digital 
*  COMP_VREF_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void COMP_VREF_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(COMP_VREF_0, mode);
}


/*******************************************************************************
* Function Name: COMP_VREF_Read
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
*  Macro COMP_VREF_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 COMP_VREF_Read(void) 
{
    return (COMP_VREF_PS & COMP_VREF_MASK) >> COMP_VREF_SHIFT;
}


/*******************************************************************************
* Function Name: COMP_VREF_ReadDataReg
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
uint8 COMP_VREF_ReadDataReg(void) 
{
    return (COMP_VREF_DR & COMP_VREF_MASK) >> COMP_VREF_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(COMP_VREF_INTSTAT) 

    /*******************************************************************************
    * Function Name: COMP_VREF_ClearInterrupt
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
    uint8 COMP_VREF_ClearInterrupt(void) 
    {
        return (COMP_VREF_INTSTAT & COMP_VREF_MASK) >> COMP_VREF_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
