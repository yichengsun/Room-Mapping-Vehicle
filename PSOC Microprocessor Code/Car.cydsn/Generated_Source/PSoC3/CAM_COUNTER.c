/*******************************************************************************
* File Name: CAM_COUNTER.c  
* Version 2.40
*
*  Description:
*     The Counter component consists of a 8, 16, 24 or 32-bit counter with
*     a selectable period between 2 and 2^Width - 1.  
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "CAM_COUNTER.h"

uint8 CAM_COUNTER_initVar = 0u;


/*******************************************************************************
* Function Name: CAM_COUNTER_Init
********************************************************************************
* Summary:
*     Initialize to the schematic state
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void CAM_COUNTER_Init(void) 
{
        #if (!CAM_COUNTER_UsingFixedFunction && !CAM_COUNTER_ControlRegRemoved)
            uint8 ctrl;
        #endif /* (!CAM_COUNTER_UsingFixedFunction && !CAM_COUNTER_ControlRegRemoved) */
        
        #if(!CAM_COUNTER_UsingFixedFunction) 
            /* Interrupt State Backup for Critical Region*/
            uint8 CAM_COUNTER_interruptState;
        #endif /* (!CAM_COUNTER_UsingFixedFunction) */
        
        #if (CAM_COUNTER_UsingFixedFunction)
            /* Clear all bits but the enable bit (if it's already set for Timer operation */
            CAM_COUNTER_CONTROL &= CAM_COUNTER_CTRL_ENABLE;
            
            /* Clear the mode bits for continuous run mode */
            #if (CY_PSOC5A)
                CAM_COUNTER_CONTROL2 &= ((uint8)(~CAM_COUNTER_CTRL_MODE_MASK));
            #endif /* (CY_PSOC5A) */
            #if (CY_PSOC3 || CY_PSOC5LP)
                CAM_COUNTER_CONTROL3 &= ((uint8)(~CAM_COUNTER_CTRL_MODE_MASK));                
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            /* Check if One Shot mode is enabled i.e. RunMode !=0*/
            #if (CAM_COUNTER_RunModeUsed != 0x0u)
                /* Set 3rd bit of Control register to enable one shot mode */
                CAM_COUNTER_CONTROL |= CAM_COUNTER_ONESHOT;
            #endif /* (CAM_COUNTER_RunModeUsed != 0x0u) */
            
            /* Set the IRQ to use the status register interrupts */
            CAM_COUNTER_CONTROL2 |= CAM_COUNTER_CTRL2_IRQ_SEL;
            
            /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
            CAM_COUNTER_RT1 &= ((uint8)(~CAM_COUNTER_RT1_MASK));
            CAM_COUNTER_RT1 |= CAM_COUNTER_SYNC;     
                    
            /*Enable DSI Sync all all inputs of the Timer*/
            CAM_COUNTER_RT1 &= ((uint8)(~CAM_COUNTER_SYNCDSI_MASK));
            CAM_COUNTER_RT1 |= CAM_COUNTER_SYNCDSI_EN;

        #else
            #if(!CAM_COUNTER_ControlRegRemoved)
            /* Set the default compare mode defined in the parameter */
            ctrl = CAM_COUNTER_CONTROL & ((uint8)(~CAM_COUNTER_CTRL_CMPMODE_MASK));
            CAM_COUNTER_CONTROL = ctrl | CAM_COUNTER_DEFAULT_COMPARE_MODE;
            
            /* Set the default capture mode defined in the parameter */
            ctrl = CAM_COUNTER_CONTROL & ((uint8)(~CAM_COUNTER_CTRL_CAPMODE_MASK));
            
            #if( 0 != CAM_COUNTER_CAPTURE_MODE_CONF)
                CAM_COUNTER_CONTROL = ctrl | CAM_COUNTER_DEFAULT_CAPTURE_MODE;
            #else
                CAM_COUNTER_CONTROL = ctrl;
            #endif /* 0 != CAM_COUNTER_CAPTURE_MODE */ 
            
            #endif /* (!CAM_COUNTER_ControlRegRemoved) */
        #endif /* (CAM_COUNTER_UsingFixedFunction) */
        
        /* Clear all data in the FIFO's */
        #if (!CAM_COUNTER_UsingFixedFunction)
            CAM_COUNTER_ClearFIFO();
        #endif /* (!CAM_COUNTER_UsingFixedFunction) */
        
        /* Set Initial values from Configuration */
        CAM_COUNTER_WritePeriod(CAM_COUNTER_INIT_PERIOD_VALUE);
        #if (!(CAM_COUNTER_UsingFixedFunction && (CY_PSOC5A)))
            CAM_COUNTER_WriteCounter(CAM_COUNTER_INIT_COUNTER_VALUE);
        #endif /* (!(CAM_COUNTER_UsingFixedFunction && (CY_PSOC5A))) */
        CAM_COUNTER_SetInterruptMode(CAM_COUNTER_INIT_INTERRUPTS_MASK);
        
        #if (!CAM_COUNTER_UsingFixedFunction)
            /* Read the status register to clear the unwanted interrupts */
            (void)CAM_COUNTER_ReadStatusRegister();
            /* Set the compare value (only available to non-fixed function implementation */
            CAM_COUNTER_WriteCompare(CAM_COUNTER_INIT_COMPARE_VALUE);
            /* Use the interrupt output of the status register for IRQ output */
            
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            CAM_COUNTER_interruptState = CyEnterCriticalSection();
            
            CAM_COUNTER_STATUS_AUX_CTRL |= CAM_COUNTER_STATUS_ACTL_INT_EN_MASK;
            
            /* Exit Critical Region*/
            CyExitCriticalSection(CAM_COUNTER_interruptState);
            
        #endif /* (!CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_Enable
********************************************************************************
* Summary:
*     Enable the Counter
* 
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: 
*   If the Enable mode is set to Hardware only then this function has no effect 
*   on the operation of the counter.
*
*******************************************************************************/
void CAM_COUNTER_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (CAM_COUNTER_UsingFixedFunction)
        CAM_COUNTER_GLOBAL_ENABLE |= CAM_COUNTER_BLOCK_EN_MASK;
        CAM_COUNTER_GLOBAL_STBY_ENABLE |= CAM_COUNTER_BLOCK_STBY_EN_MASK;
    #endif /* (CAM_COUNTER_UsingFixedFunction) */  
        
    /* Enable the counter from the control register  */
    /* If Fixed Function then make sure Mode is set correctly */
    /* else make sure reset is clear */
    #if(!CAM_COUNTER_ControlRegRemoved || CAM_COUNTER_UsingFixedFunction)
        CAM_COUNTER_CONTROL |= CAM_COUNTER_CTRL_ENABLE;                
    #endif /* (!CAM_COUNTER_ControlRegRemoved || CAM_COUNTER_UsingFixedFunction) */
    
}


/*******************************************************************************
* Function Name: CAM_COUNTER_Start
********************************************************************************
* Summary:
*  Enables the counter for operation 
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Global variables:
*  CAM_COUNTER_initVar: Is modified when this function is called for the  
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void CAM_COUNTER_Start(void) 
{
    if(CAM_COUNTER_initVar == 0u)
    {
        CAM_COUNTER_Init();
        
        CAM_COUNTER_initVar = 1u; /* Clear this bit for Initialization */        
    }
    
    /* Enable the Counter */
    CAM_COUNTER_Enable();        
}


/*******************************************************************************
* Function Name: CAM_COUNTER_Stop
********************************************************************************
* Summary:
* Halts the counter, but does not change any modes or disable interrupts.
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
* Side Effects: If the Enable mode is set to Hardware only then this function
*               has no effect on the operation of the counter.
*
*******************************************************************************/
void CAM_COUNTER_Stop(void) 
{
    /* Disable Counter */
    #if(!CAM_COUNTER_ControlRegRemoved || CAM_COUNTER_UsingFixedFunction)
        CAM_COUNTER_CONTROL &= ((uint8)(~CAM_COUNTER_CTRL_ENABLE));        
    #endif /* (!CAM_COUNTER_ControlRegRemoved || CAM_COUNTER_UsingFixedFunction) */
    
    /* Globally disable the Fixed Function Block chosen */
    #if (CAM_COUNTER_UsingFixedFunction)
        CAM_COUNTER_GLOBAL_ENABLE &= ((uint8)(~CAM_COUNTER_BLOCK_EN_MASK));
        CAM_COUNTER_GLOBAL_STBY_ENABLE &= ((uint8)(~CAM_COUNTER_BLOCK_STBY_EN_MASK));
    #endif /* (CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_SetInterruptMode
********************************************************************************
* Summary:
* Configures which interrupt sources are enabled to generate the final interrupt
*
* Parameters:  
*  InterruptsMask: This parameter is an or'd collection of the status bits
*                   which will be allowed to generate the counters interrupt.   
*
* Return: 
*  void
*
*******************************************************************************/
void CAM_COUNTER_SetInterruptMode(uint8 interruptsMask) 
{
    CAM_COUNTER_STATUS_MASK = interruptsMask;
}


/*******************************************************************************
* Function Name: CAM_COUNTER_ReadStatusRegister
********************************************************************************
* Summary:
*   Reads the status register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the status register
*
* Side Effects:
*   Status register bits may be clear on read. 
*
*******************************************************************************/
uint8   CAM_COUNTER_ReadStatusRegister(void) 
{
    return CAM_COUNTER_STATUS;
}


#if(!CAM_COUNTER_ControlRegRemoved)
/*******************************************************************************
* Function Name: CAM_COUNTER_ReadControlRegister
********************************************************************************
* Summary:
*   Reads the control register and returns it's state. This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
uint8   CAM_COUNTER_ReadControlRegister(void) 
{
    return CAM_COUNTER_CONTROL;
}


/*******************************************************************************
* Function Name: CAM_COUNTER_WriteControlRegister
********************************************************************************
* Summary:
*   Sets the bit-field of the control register.  This function should use
*       defined types for the bit-field information as the bits in this
*       register may be permuteable.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) The contents of the control register
*
*******************************************************************************/
void    CAM_COUNTER_WriteControlRegister(uint8 control) 
{
    CAM_COUNTER_CONTROL = control;
}

#endif  /* (!CAM_COUNTER_ControlRegRemoved) */


#if (!(CAM_COUNTER_UsingFixedFunction && (CY_PSOC5A)))
/*******************************************************************************
* Function Name: CAM_COUNTER_WriteCounter
********************************************************************************
* Summary:
*   This funtion is used to set the counter to a specific value
*
* Parameters:  
*  counter:  New counter value. 
*
* Return: 
*  void 
*
*******************************************************************************/
void CAM_COUNTER_WriteCounter(uint8 counter) \
                                   
{
    #if(CAM_COUNTER_UsingFixedFunction)
        /* assert if block is already enabled */
        CYASSERT (0u == (CAM_COUNTER_GLOBAL_ENABLE & CAM_COUNTER_BLOCK_EN_MASK));
        /* If block is disabled, enable it and then write the counter */
        CAM_COUNTER_GLOBAL_ENABLE |= CAM_COUNTER_BLOCK_EN_MASK;
        CY_SET_REG16(CAM_COUNTER_COUNTER_LSB_PTR, (uint16)counter);
        CAM_COUNTER_GLOBAL_ENABLE &= ((uint8)(~CAM_COUNTER_BLOCK_EN_MASK));
    #else
        CY_SET_REG8(CAM_COUNTER_COUNTER_LSB_PTR, counter);
    #endif /* (CAM_COUNTER_UsingFixedFunction) */
}
#endif /* (!(CAM_COUNTER_UsingFixedFunction && (CY_PSOC5A))) */


/*******************************************************************************
* Function Name: CAM_COUNTER_ReadCounter
********************************************************************************
* Summary:
* Returns the current value of the counter.  It doesn't matter
* if the counter is enabled or running.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) The present value of the counter.
*
*******************************************************************************/
uint8 CAM_COUNTER_ReadCounter(void) 
{
    /* Force capture by reading Accumulator */
    /* Must first do a software capture to be able to read the counter */
    /* It is up to the user code to make sure there isn't already captured data in the FIFO */
    #if(CAM_COUNTER_UsingFixedFunction)
		(void)CY_GET_REG16(CAM_COUNTER_COUNTER_LSB_PTR);
	#else
		(void)CY_GET_REG8(CAM_COUNTER_COUNTER_LSB_PTR_8BIT);
	#endif/* (CAM_COUNTER_UsingFixedFunction) */
    
    /* Read the data from the FIFO (or capture register for Fixed Function)*/
    #if(CAM_COUNTER_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(CAM_COUNTER_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(CAM_COUNTER_STATICCOUNT_LSB_PTR));
    #endif /* (CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_ReadCapture
********************************************************************************
* Summary:
*   This function returns the last value captured.
*
* Parameters:  
*  void
*
* Return: 
*  (uint8) Present Capture value.
*
*******************************************************************************/
uint8 CAM_COUNTER_ReadCapture(void) 
{
    #if(CAM_COUNTER_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(CAM_COUNTER_STATICCOUNT_LSB_PTR));
    #else
        return (CY_GET_REG8(CAM_COUNTER_STATICCOUNT_LSB_PTR));
    #endif /* (CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_WritePeriod
********************************************************************************
* Summary:
* Changes the period of the counter.  The new period 
* will be loaded the next time terminal count is detected.
*
* Parameters:  
*  period: (uint8) A value of 0 will result in
*         the counter remaining at zero.  
*
* Return: 
*  void
*
*******************************************************************************/
void CAM_COUNTER_WritePeriod(uint8 period) 
{
    #if(CAM_COUNTER_UsingFixedFunction)
        CY_SET_REG16(CAM_COUNTER_PERIOD_LSB_PTR,(uint16)period);
    #else
        CY_SET_REG8(CAM_COUNTER_PERIOD_LSB_PTR, period);
    #endif /* (CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_ReadPeriod
********************************************************************************
* Summary:
* Reads the current period value without affecting counter operation.
*
* Parameters:  
*  void:  
*
* Return: 
*  (uint8) Present period value.
*
*******************************************************************************/
uint8 CAM_COUNTER_ReadPeriod(void) 
{
    #if(CAM_COUNTER_UsingFixedFunction)
        return ((uint8)CY_GET_REG16(CAM_COUNTER_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG8(CAM_COUNTER_PERIOD_LSB_PTR));
    #endif /* (CAM_COUNTER_UsingFixedFunction) */
}


#if (!CAM_COUNTER_UsingFixedFunction)
/*******************************************************************************
* Function Name: CAM_COUNTER_WriteCompare
********************************************************************************
* Summary:
* Changes the compare value.  The compare output will 
* reflect the new value on the next UDB clock.  The compare output will be 
* driven high when the present counter value compares true based on the 
* configured compare mode setting. 
*
* Parameters:  
*  Compare:  New compare value. 
*
* Return: 
*  void
*
*******************************************************************************/
void CAM_COUNTER_WriteCompare(uint8 compare) \
                                   
{
    #if(CAM_COUNTER_UsingFixedFunction)
        CY_SET_REG16(CAM_COUNTER_COMPARE_LSB_PTR, (uint16)compare);
    #else
        CY_SET_REG8(CAM_COUNTER_COMPARE_LSB_PTR, compare);
    #endif /* (CAM_COUNTER_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: CAM_COUNTER_ReadCompare
********************************************************************************
* Summary:
* Returns the compare value.
*
* Parameters:  
*  void:
*
* Return: 
*  (uint8) Present compare value.
*
*******************************************************************************/
uint8 CAM_COUNTER_ReadCompare(void) 
{
    return (CY_GET_REG8(CAM_COUNTER_COMPARE_LSB_PTR));
}


#if (CAM_COUNTER_COMPARE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: CAM_COUNTER_SetCompareMode
********************************************************************************
* Summary:
*  Sets the software controlled Compare Mode.
*
* Parameters:
*  compareMode:  Compare Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void CAM_COUNTER_SetCompareMode(uint8 compareMode) 
{
    /* Clear the compare mode bits in the control register */
    CAM_COUNTER_CONTROL &= ((uint8)(~CAM_COUNTER_CTRL_CMPMODE_MASK));
    
    /* Write the new setting */
    CAM_COUNTER_CONTROL |= compareMode;
}
#endif  /* (CAM_COUNTER_COMPARE_MODE_SOFTWARE) */


#if (CAM_COUNTER_CAPTURE_MODE_SOFTWARE)
/*******************************************************************************
* Function Name: CAM_COUNTER_SetCaptureMode
********************************************************************************
* Summary:
*  Sets the software controlled Capture Mode.
*
* Parameters:
*  captureMode:  Capture Mode Enumerated Type.
*
* Return:
*  void
*
*******************************************************************************/
void CAM_COUNTER_SetCaptureMode(uint8 captureMode) 
{
    /* Clear the capture mode bits in the control register */
    CAM_COUNTER_CONTROL &= ((uint8)(~CAM_COUNTER_CTRL_CAPMODE_MASK));
    
    /* Write the new setting */
    CAM_COUNTER_CONTROL |= ((uint8)((uint8)captureMode << CAM_COUNTER_CTRL_CAPMODE0_SHIFT));
}
#endif  /* (CAM_COUNTER_CAPTURE_MODE_SOFTWARE) */


/*******************************************************************************
* Function Name: CAM_COUNTER_ClearFIFO
********************************************************************************
* Summary:
*   This function clears all capture data from the capture FIFO
*
* Parameters:  
*  void:
*
* Return: 
*  None
*
*******************************************************************************/
void CAM_COUNTER_ClearFIFO(void) 
{

    while(0u != (CAM_COUNTER_ReadStatusRegister() & CAM_COUNTER_STATUS_FIFONEMP))
    {
        (void)CAM_COUNTER_ReadCapture();
    }

}
#endif  /* (!CAM_COUNTER_UsingFixedFunction) */


/* [] END OF FILE */

