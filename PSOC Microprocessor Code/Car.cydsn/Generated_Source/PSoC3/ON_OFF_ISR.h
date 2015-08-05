/*******************************************************************************
* File Name: ON_OFF_ISR.h
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

#if !defined(CY_ISR_ON_OFF_ISR_H)
#define CY_ISR_ON_OFF_ISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ON_OFF_ISR_Start(void) ;
void ON_OFF_ISR_StartEx(cyisraddress address) ;
void ON_OFF_ISR_Stop(void) ;

CY_ISR_PROTO(ON_OFF_ISR_Interrupt);

void ON_OFF_ISR_SetVector(cyisraddress address) ;
cyisraddress ON_OFF_ISR_GetVector(void) ;

void ON_OFF_ISR_SetPriority(uint8 priority) ;
uint8 ON_OFF_ISR_GetPriority(void) ;

void ON_OFF_ISR_Enable(void) ;
uint8 ON_OFF_ISR_GetState(void) ;
void ON_OFF_ISR_Disable(void) ;

void ON_OFF_ISR_SetPending(void) ;
void ON_OFF_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ON_OFF_ISR ISR. */
#define ON_OFF_ISR_INTC_VECTOR            ((reg16 *) ON_OFF_ISR__INTC_VECT)

/* Address of the ON_OFF_ISR ISR priority. */
#define ON_OFF_ISR_INTC_PRIOR             ((reg8 *) ON_OFF_ISR__INTC_PRIOR_REG)

/* Priority of the ON_OFF_ISR interrupt. */
#define ON_OFF_ISR_INTC_PRIOR_NUMBER      ON_OFF_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ON_OFF_ISR interrupt. */
#define ON_OFF_ISR_INTC_SET_EN            ((reg8 *) ON_OFF_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ON_OFF_ISR interrupt. */
#define ON_OFF_ISR_INTC_CLR_EN            ((reg8 *) ON_OFF_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ON_OFF_ISR interrupt state to pending. */
#define ON_OFF_ISR_INTC_SET_PD            ((reg8 *) ON_OFF_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ON_OFF_ISR interrupt. */
#define ON_OFF_ISR_INTC_CLR_PD            ((reg8 *) ON_OFF_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_ON_OFF_ISR_H */


/* [] END OF FILE */
