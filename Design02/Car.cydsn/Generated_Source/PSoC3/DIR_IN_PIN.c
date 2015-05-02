/*******************************************************************************
* File Name: DIR_IN_PIN.c  
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
#include "DIR_IN_PIN.h"


/*******************************************************************************
* Function Name: DIR_IN_PIN_Write
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
void DIR_IN_PIN_Write(uint8 value) 
{
    uint8 staticBits = (DIR_IN_PIN_DR & (uint8)(~DIR_IN_PIN_MASK));
    DIR_IN_PIN_DR = staticBits | ((uint8)(value << DIR_IN_PIN_SHIFT) & DIR_IN_PIN_MASK);
}


/*******************************************************************************
* Function Name: DIR_IN_PIN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  DIR_IN_PIN_DM_STRONG     Strong Drive 
*  DIR_IN_PIN_DM_OD_HI      Open Drain, Drives High 
*  DIR_IN_PIN_DM_OD_LO      Open Drain, Drives Low 
*  DIR_IN_PIN_DM_RES_UP     Resistive Pull Up 
*  DIR_IN_PIN_DM_RES_DWN    Resistive Pull Down 
*  DIR_IN_PIN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  DIR_IN_PIN_DM_DIG_HIZ    High Impedance Digital 
*  DIR_IN_PIN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void DIR_IN_PIN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DIR_IN_PIN_0, mode);
}


/*******************************************************************************
* Function Name: DIR_IN_PIN_Read
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
*  Macro DIR_IN_PIN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DIR_IN_PIN_Read(void) 
{
    return (DIR_IN_PIN_PS & DIR_IN_PIN_MASK) >> DIR_IN_PIN_SHIFT;
}


/*******************************************************************************
* Function Name: DIR_IN_PIN_ReadDataReg
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
uint8 DIR_IN_PIN_ReadDataReg(void) 
{
    return (DIR_IN_PIN_DR & DIR_IN_PIN_MASK) >> DIR_IN_PIN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DIR_IN_PIN_INTSTAT) 

    /*******************************************************************************
    * Function Name: DIR_IN_PIN_ClearInterrupt
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
    uint8 DIR_IN_PIN_ClearInterrupt(void) 
    {
        return (DIR_IN_PIN_INTSTAT & DIR_IN_PIN_MASK) >> DIR_IN_PIN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
