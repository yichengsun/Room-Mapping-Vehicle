/*******************************************************************************
* File Name: DIR_ISR.c  
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
#include <DIR_ISR.h>

#if !defined(DIR_ISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START DIR_ISR_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: DIR_ISR_Start
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
void DIR_ISR_Start(void) 
{
    /* For all we know the interrupt is active. */
    DIR_ISR_Disable();

    /* Set the ISR to point to the DIR_ISR Interrupt. */
    DIR_ISR_SetVector(&DIR_ISR_Interrupt);

    /* Set the priority. */
    DIR_ISR_SetPriority((uint8)DIR_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    DIR_ISR_Enable();
}


/*******************************************************************************
* Function Name: DIR_ISR_StartEx
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
void DIR_ISR_StartEx(cyisraddress address) 
{
    /* For all we know the interrupt is active. */
    DIR_ISR_Disable();

    /* Set the ISR to point to the DIR_ISR Interrupt. */
    DIR_ISR_SetVector(address);

    /* Set the priority. */
    DIR_ISR_SetPriority((uint8)DIR_ISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    DIR_ISR_Enable();
}


/*******************************************************************************
* Function Name: DIR_ISR_Stop
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
void DIR_ISR_Stop(void) 
{
    /* Disable this interrupt. */
    DIR_ISR_Disable();
}


/*******************************************************************************
* Function Name: DIR_ISR_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for DIR_ISR.
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
CY_ISR(DIR_ISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START DIR_ISR_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (DIR_ISR__ES2_PATCH ))      
            DIR_ISR_ISR_PATCH();
        #endif /* CYDEV_CHIP_REVISION_USED */
    #endif /* (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */
}


/*******************************************************************************
* Function Name: DIR_ISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling DIR_ISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use DIR_ISR_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void DIR_ISR_SetVector(cyisraddress address) 
{
    CY_SET_REG16(DIR_ISR_INTC_VECTOR, (uint16) address);
}


/*******************************************************************************
* Function Name: DIR_ISR_GetVector
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
cyisraddress DIR_ISR_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(DIR_ISR_INTC_VECTOR);
}


/*******************************************************************************
* Function Name: DIR_ISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling DIR_ISR_Start
*   or DIR_ISR_StartEx will override any effect this method would 
*   have had. This method should only be called after DIR_ISR_Start or 
*   DIR_ISR_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void DIR_ISR_SetPriority(uint8 priority) 
{
    *DIR_ISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: DIR_ISR_GetPriority
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
uint8 DIR_ISR_GetPriority(void) 
{
    uint8 priority;


    priority = *DIR_ISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: DIR_ISR_Enable
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
void DIR_ISR_Enable(void) 
{
    /* Enable the general interrupt. */
    *DIR_ISR_INTC_SET_EN = DIR_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: DIR_ISR_GetState
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
uint8 DIR_ISR_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return ((*DIR_ISR_INTC_SET_EN & (uint8)DIR_ISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: DIR_ISR_Disable
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
void DIR_ISR_Disable(void) 
{
    /* Disable the general interrupt. */
    *DIR_ISR_INTC_CLR_EN = DIR_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: DIR_ISR_SetPending
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
void DIR_ISR_SetPending(void) 
{
    *DIR_ISR_INTC_SET_PD = DIR_ISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: DIR_ISR_ClearPending
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
void DIR_ISR_ClearPending(void) 
{
    *DIR_ISR_INTC_CLR_PD = DIR_ISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
