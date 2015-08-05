/*******************************************************************************
* File Name: PWM_OUT.c  
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
#include "PWM_OUT.h"


/*******************************************************************************
* Function Name: PWM_OUT_Write
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
void PWM_OUT_Write(uint8 value) 
{
    uint8 staticBits = (PWM_OUT_DR & (uint8)(~PWM_OUT_MASK));
    PWM_OUT_DR = staticBits | ((uint8)(value << PWM_OUT_SHIFT) & PWM_OUT_MASK);
}


/*******************************************************************************
* Function Name: PWM_OUT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWM_OUT_DM_STRONG     Strong Drive 
*  PWM_OUT_DM_OD_HI      Open Drain, Drives High 
*  PWM_OUT_DM_OD_LO      Open Drain, Drives Low 
*  PWM_OUT_DM_RES_UP     Resistive Pull Up 
*  PWM_OUT_DM_RES_DWN    Resistive Pull Down 
*  PWM_OUT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWM_OUT_DM_DIG_HIZ    High Impedance Digital 
*  PWM_OUT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWM_OUT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PWM_OUT_0, mode);
}


/*******************************************************************************
* Function Name: PWM_OUT_Read
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
*  Macro PWM_OUT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWM_OUT_Read(void) 
{
    return (PWM_OUT_PS & PWM_OUT_MASK) >> PWM_OUT_SHIFT;
}


/*******************************************************************************
* Function Name: PWM_OUT_ReadDataReg
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
uint8 PWM_OUT_ReadDataReg(void) 
{
    return (PWM_OUT_DR & PWM_OUT_MASK) >> PWM_OUT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWM_OUT_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWM_OUT_ClearInterrupt
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
    uint8 PWM_OUT_ClearInterrupt(void) 
    {
        return (PWM_OUT_INTSTAT & PWM_OUT_MASK) >> PWM_OUT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
