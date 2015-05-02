/*******************************************************************************
* File Name: DIR_ISR.h
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

#if !defined(CY_ISR_DIR_ISR_H)
#define CY_ISR_DIR_ISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DIR_ISR_Start(void) ;
void DIR_ISR_StartEx(cyisraddress address) ;
void DIR_ISR_Stop(void) ;

CY_ISR_PROTO(DIR_ISR_Interrupt);

void DIR_ISR_SetVector(cyisraddress address) ;
cyisraddress DIR_ISR_GetVector(void) ;

void DIR_ISR_SetPriority(uint8 priority) ;
uint8 DIR_ISR_GetPriority(void) ;

void DIR_ISR_Enable(void) ;
uint8 DIR_ISR_GetState(void) ;
void DIR_ISR_Disable(void) ;

void DIR_ISR_SetPending(void) ;
void DIR_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DIR_ISR ISR. */
#define DIR_ISR_INTC_VECTOR            ((reg16 *) DIR_ISR__INTC_VECT)

/* Address of the DIR_ISR ISR priority. */
#define DIR_ISR_INTC_PRIOR             ((reg8 *) DIR_ISR__INTC_PRIOR_REG)

/* Priority of the DIR_ISR interrupt. */
#define DIR_ISR_INTC_PRIOR_NUMBER      DIR_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DIR_ISR interrupt. */
#define DIR_ISR_INTC_SET_EN            ((reg8 *) DIR_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DIR_ISR interrupt. */
#define DIR_ISR_INTC_CLR_EN            ((reg8 *) DIR_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DIR_ISR interrupt state to pending. */
#define DIR_ISR_INTC_SET_PD            ((reg8 *) DIR_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DIR_ISR interrupt. */
#define DIR_ISR_INTC_CLR_PD            ((reg8 *) DIR_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_DIR_ISR_H */


/* [] END OF FILE */
