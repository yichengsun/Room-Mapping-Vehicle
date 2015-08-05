/*******************************************************************************
* File Name: HE_DATA.c  
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
#include "HE_DATA.h"


/*******************************************************************************
* Function Name: HE_DATA_Write
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
void HE_DATA_Write(uint8 value) 
{
    uint8 staticBits = (HE_DATA_DR & (uint8)(~HE_DATA_MASK));
    HE_DATA_DR = staticBits | ((uint8)(value << HE_DATA_SHIFT) & HE_DATA_MASK);
}


/*******************************************************************************
* Function Name: HE_DATA_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  HE_DATA_DM_STRONG     Strong Drive 
*  HE_DATA_DM_OD_HI      Open Drain, Drives High 
*  HE_DATA_DM_OD_LO      Open Drain, Drives Low 
*  HE_DATA_DM_RES_UP     Resistive Pull Up 
*  HE_DATA_DM_RES_DWN    Resistive Pull Down 
*  HE_DATA_DM_RES_UPDWN  Resistive Pull Up/Down 
*  HE_DATA_DM_DIG_HIZ    High Impedance Digital 
*  HE_DATA_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void HE_DATA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(HE_DATA_0, mode);
}


/*******************************************************************************
* Function Name: HE_DATA_Read
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
*  Macro HE_DATA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 HE_DATA_Read(void) 
{
    return (HE_DATA_PS & HE_DATA_MASK) >> HE_DATA_SHIFT;
}


/*******************************************************************************
* Function Name: HE_DATA_ReadDataReg
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
uint8 HE_DATA_ReadDataReg(void) 
{
    return (HE_DATA_DR & HE_DATA_MASK) >> HE_DATA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(HE_DATA_INTSTAT) 

    /*******************************************************************************
    * Function Name: HE_DATA_ClearInterrupt
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
    uint8 HE_DATA_ClearInterrupt(void) 
    {
        return (HE_DATA_INTSTAT & HE_DATA_MASK) >> HE_DATA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
