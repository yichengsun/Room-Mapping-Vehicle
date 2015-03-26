/*******************************************************************************
* File Name: LINE_READ_ISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ISR_LINE_READ_ISR_H)
#define CY_ISR_LINE_READ_ISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void LINE_READ_ISR_Start(void) ;
void LINE_READ_ISR_StartEx(cyisraddress address) ;
void LINE_READ_ISR_Stop(void) ;

CY_ISR_PROTO(LINE_READ_ISR_Interrupt);

void LINE_READ_ISR_SetVector(cyisraddress address) ;
cyisraddress LINE_READ_ISR_GetVector(void) ;

void LINE_READ_ISR_SetPriority(uint8 priority) ;
uint8 LINE_READ_ISR_GetPriority(void) ;

void LINE_READ_ISR_Enable(void) ;
uint8 LINE_READ_ISR_GetState(void) ;
void LINE_READ_ISR_Disable(void) ;

void LINE_READ_ISR_SetPending(void) ;
void LINE_READ_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the LINE_READ_ISR ISR. */
#define LINE_READ_ISR_INTC_VECTOR            ((reg16 *) LINE_READ_ISR__INTC_VECT)

/* Address of the LINE_READ_ISR ISR priority. */
#define LINE_READ_ISR_INTC_PRIOR             ((reg8 *) LINE_READ_ISR__INTC_PRIOR_REG)

/* Priority of the LINE_READ_ISR interrupt. */
#define LINE_READ_ISR_INTC_PRIOR_NUMBER      LINE_READ_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable LINE_READ_ISR interrupt. */
#define LINE_READ_ISR_INTC_SET_EN            ((reg8 *) LINE_READ_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the LINE_READ_ISR interrupt. */
#define LINE_READ_ISR_INTC_CLR_EN            ((reg8 *) LINE_READ_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the LINE_READ_ISR interrupt state to pending. */
#define LINE_READ_ISR_INTC_SET_PD            ((reg8 *) LINE_READ_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the LINE_READ_ISR interrupt. */
#define LINE_READ_ISR_INTC_CLR_PD            ((reg8 *) LINE_READ_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_LINE_READ_ISR_H */


/* [] END OF FILE */
