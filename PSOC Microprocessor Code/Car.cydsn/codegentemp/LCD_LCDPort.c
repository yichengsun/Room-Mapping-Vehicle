/*******************************************************************************
* File Name: LCD_LCDPort.c  
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
#include "LCD_LCDPort.h"


/*******************************************************************************
* Function Name: LCD_LCDPort_Write
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
void LCD_LCDPort_Write(uint8 value) 
{
    uint8 staticBits = (LCD_LCDPort_DR & (uint8)(~LCD_LCDPort_MASK));
    LCD_LCDPort_DR = staticBits | ((uint8)(value << LCD_LCDPort_SHIFT) & LCD_LCDPort_MASK);
}


/*******************************************************************************
* Function Name: LCD_LCDPort_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LCD_LCDPort_DM_STRONG     Strong Drive 
*  LCD_LCDPort_DM_OD_HI      Open Drain, Drives High 
*  LCD_LCDPort_DM_OD_LO      Open Drain, Drives Low 
*  LCD_LCDPort_DM_RES_UP     Resistive Pull Up 
*  LCD_LCDPort_DM_RES_DWN    Resistive Pull Down 
*  LCD_LCDPort_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LCD_LCDPort_DM_DIG_HIZ    High Impedance Digital 
*  LCD_LCDPort_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LCD_LCDPort_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LCD_LCDPort_0, mode);
	CyPins_SetPinDriveMode(LCD_LCDPort_1, mode);
	CyPins_SetPinDriveMode(LCD_LCDPort_2, mode);
	CyPins_SetPinDriveMode(LCD_LCDPort_3, mode);
	CyPins_SetPinDriveMode(LCD_LCDPort_4, mode);
	CyPins_SetPinDriveMode(LCD_LCDPort_5, mode);
	CyPins_SetPinDriveMode(LCD_LCDPort_6, mode);
}


/*******************************************************************************
* Function Name: LCD_LCDPort_Read
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
*  Macro LCD_LCDPort_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LCD_LCDPort_Read(void) 
{
    return (LCD_LCDPort_PS & LCD_LCDPort_MASK) >> LCD_LCDPort_SHIFT;
}


/*******************************************************************************
* Function Name: LCD_LCDPort_ReadDataReg
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
uint8 LCD_LCDPort_ReadDataReg(void) 
{
    return (LCD_LCDPort_DR & LCD_LCDPort_MASK) >> LCD_LCDPort_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LCD_LCDPort_INTSTAT) 

    /*******************************************************************************
    * Function Name: LCD_LCDPort_ClearInterrupt
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
    uint8 LCD_LCDPort_ClearInterrupt(void) 
    {
        return (LCD_LCDPort_INTSTAT & LCD_LCDPort_MASK) >> LCD_LCDPort_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
