/*******************************************************************************
* File Name: COMPARATOR_OUT.c  
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
#include "COMPARATOR_OUT.h"


/*******************************************************************************
* Function Name: COMPARATOR_OUT_Write
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
void COMPARATOR_OUT_Write(uint8 value) 
{
    uint8 staticBits = (COMPARATOR_OUT_DR & (uint8)(~COMPARATOR_OUT_MASK));
    COMPARATOR_OUT_DR = staticBits | ((uint8)(value << COMPARATOR_OUT_SHIFT) & COMPARATOR_OUT_MASK);
}


/*******************************************************************************
* Function Name: COMPARATOR_OUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  COMPARATOR_OUT_DM_STRONG     Strong Drive 
*  COMPARATOR_OUT_DM_OD_HI      Open Drain, Drives High 
*  COMPARATOR_OUT_DM_OD_LO      Open Drain, Drives Low 
*  COMPARATOR_OUT_DM_RES_UP     Resistive Pull Up 
*  COMPARATOR_OUT_DM_RES_DWN    Resistive Pull Down 
*  COMPARATOR_OUT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  COMPARATOR_OUT_DM_DIG_HIZ    High Impedance Digital 
*  COMPARATOR_OUT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void COMPARATOR_OUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(COMPARATOR_OUT_0, mode);
}


/*******************************************************************************
* Function Name: COMPARATOR_OUT_Read
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
*  Macro COMPARATOR_OUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 COMPARATOR_OUT_Read(void) 
{
    return (COMPARATOR_OUT_PS & COMPARATOR_OUT_MASK) >> COMPARATOR_OUT_SHIFT;
}


/*******************************************************************************
* Function Name: COMPARATOR_OUT_ReadDataReg
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
uint8 COMPARATOR_OUT_ReadDataReg(void) 
{
    return (COMPARATOR_OUT_DR & COMPARATOR_OUT_MASK) >> COMPARATOR_OUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(COMPARATOR_OUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: COMPARATOR_OUT_ClearInterrupt
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
    uint8 COMPARATOR_OUT_ClearInterrupt(void) 
    {
        return (COMPARATOR_OUT_INTSTAT & COMPARATOR_OUT_MASK) >> COMPARATOR_OUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
