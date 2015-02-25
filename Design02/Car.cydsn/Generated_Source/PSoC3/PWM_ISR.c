/*******************************************************************************
* File Name: PWM_ISR.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include <cydevice_trm.h>
#include <CyLib.h>
#include <PWM_ISR.h>

#if !defined(PWM_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START PWM_ISR_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: PWM_ISR_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_Start(void) 
{
    /* For all we know the interrupt is active. */
    PWM_ISR_Disable();

    /* Set the ISR to point to the PWM_ISR Interrupt. */
    PWM_ISR_SetVector(&PWM_ISR_Interrupt);

    /* Set the priority. */
    PWM_ISR_SetPriority((uint8)PWM_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    PWM_ISR_Enable();
}


/*******************************************************************************
* Function Name: PWM_ISR_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_StartEx(cyisraddress address) 
{
    /* For all we know the interrupt is active. */
    PWM_ISR_Disable();

    /* Set the ISR to point to the PWM_ISR Interrupt. */
    PWM_ISR_SetVector(address);

    /* Set the priority. */
    PWM_ISR_SetPriority((uint8)PWM_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    PWM_ISR_Enable();
}


/*******************************************************************************
* Function Name: PWM_ISR_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_Stop(void) 
{
    /* Disable this interrupt. */
    PWM_ISR_Disable();
}


/*******************************************************************************
* Function Name: PWM_ISR_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for PWM_ISR.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(PWM_ISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START PWM_ISR_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (PWM_ISR__ES2_PATCH ))      
            PWM_ISR_ISR_PATCH();
        #endif /* CYDEV_CHIP_REVISION_USED */
    #endif /* (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */
}


/*******************************************************************************
* Function Name: PWM_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling PWM_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use PWM_ISR_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_SetVector(cyisraddress address) 
{
    CY_SET_REG16(PWM_ISR_INTC_VECTOR, (uint16) address);
}


/*******************************************************************************
* Function Name: PWM_ISR_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress PWM_ISR_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(PWM_ISR_INTC_VECTOR);
}


/*******************************************************************************
* Function Name: PWM_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling PWM_ISR_Start
*   or PWM_ISR_StartEx will override any effect this method would 
*   have had. This method should only be called after PWM_ISR_Start or 
*   PWM_ISR_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_SetPriority(uint8 priority) 
{
    *PWM_ISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: PWM_ISR_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*******************************************************************************/
uint8 PWM_ISR_GetPriority(void) 
{
    uint8 priority;


    priority = *PWM_ISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: PWM_ISR_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_Enable(void) 
{
    /* Enable the general interrupt. */
    *PWM_ISR_INTC_SET_EN = PWM_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: PWM_ISR_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 PWM_ISR_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return ((*PWM_ISR_INTC_SET_EN & (uint8)PWM_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: PWM_ISR_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_Disable(void) 
{
    /* Disable the general interrupt. */
    *PWM_ISR_INTC_CLR_EN = PWM_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: PWM_ISR_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_SetPending(void) 
{
    *PWM_ISR_INTC_SET_PD = PWM_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: PWM_ISR_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void PWM_ISR_ClearPending(void) 
{
    *PWM_ISR_INTC_CLR_PD = PWM_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
