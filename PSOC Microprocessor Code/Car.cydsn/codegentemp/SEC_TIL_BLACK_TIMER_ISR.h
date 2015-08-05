/*******************************************************************************
* File Name: SEC_TIL_BLACK_TIMER_ISR.h
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

#if !defined(CY_ISR_SEC_TIL_BLACK_TIMER_ISR_H)
#define CY_ISR_SEC_TIL_BLACK_TIMER_ISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SEC_TIL_BLACK_TIMER_ISR_Start(void) ;
void SEC_TIL_BLACK_TIMER_ISR_StartEx(cyisraddress address) ;
void SEC_TIL_BLACK_TIMER_ISR_Stop(void) ;

CY_ISR_PROTO(SEC_TIL_BLACK_TIMER_ISR_Interrupt);

void SEC_TIL_BLACK_TIMER_ISR_SetVector(cyisraddress address) ;
cyisraddress SEC_TIL_BLACK_TIMER_ISR_GetVector(void) ;

void SEC_TIL_BLACK_TIMER_ISR_SetPriority(uint8 priority) ;
uint8 SEC_TIL_BLACK_TIMER_ISR_GetPriority(void) ;

void SEC_TIL_BLACK_TIMER_ISR_Enable(void) ;
uint8 SEC_TIL_BLACK_TIMER_ISR_GetState(void) ;
void SEC_TIL_BLACK_TIMER_ISR_Disable(void) ;

void SEC_TIL_BLACK_TIMER_ISR_SetPending(void) ;
void SEC_TIL_BLACK_TIMER_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SEC_TIL_BLACK_TIMER_ISR ISR. */
#define SEC_TIL_BLACK_TIMER_ISR_INTC_VECTOR            ((reg16 *) SEC_TIL_BLACK_TIMER_ISR__INTC_VECT)

/* Address of the SEC_TIL_BLACK_TIMER_ISR ISR priority. */
#define SEC_TIL_BLACK_TIMER_ISR_INTC_PRIOR             ((reg8 *) SEC_TIL_BLACK_TIMER_ISR__INTC_PRIOR_REG)

/* Priority of the SEC_TIL_BLACK_TIMER_ISR interrupt. */
#define SEC_TIL_BLACK_TIMER_ISR_INTC_PRIOR_NUMBER      SEC_TIL_BLACK_TIMER_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SEC_TIL_BLACK_TIMER_ISR interrupt. */
#define SEC_TIL_BLACK_TIMER_ISR_INTC_SET_EN            ((reg8 *) SEC_TIL_BLACK_TIMER_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SEC_TIL_BLACK_TIMER_ISR interrupt. */
#define SEC_TIL_BLACK_TIMER_ISR_INTC_CLR_EN            ((reg8 *) SEC_TIL_BLACK_TIMER_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SEC_TIL_BLACK_TIMER_ISR interrupt state to pending. */
#define SEC_TIL_BLACK_TIMER_ISR_INTC_SET_PD            ((reg8 *) SEC_TIL_BLACK_TIMER_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SEC_TIL_BLACK_TIMER_ISR interrupt. */
#define SEC_TIL_BLACK_TIMER_ISR_INTC_CLR_PD            ((reg8 *) SEC_TIL_BLACK_TIMER_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_SEC_TIL_BLACK_TIMER_ISR_H */


/* [] END OF FILE */
