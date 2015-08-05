/*******************************************************************************
* File Name: FRAME_ISR.h
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

#if !defined(CY_ISR_FRAME_ISR_H)
#define CY_ISR_FRAME_ISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void FRAME_ISR_Start(void) ;
void FRAME_ISR_StartEx(cyisraddress address) ;
void FRAME_ISR_Stop(void) ;

CY_ISR_PROTO(FRAME_ISR_Interrupt);

void FRAME_ISR_SetVector(cyisraddress address) ;
cyisraddress FRAME_ISR_GetVector(void) ;

void FRAME_ISR_SetPriority(uint8 priority) ;
uint8 FRAME_ISR_GetPriority(void) ;

void FRAME_ISR_Enable(void) ;
uint8 FRAME_ISR_GetState(void) ;
void FRAME_ISR_Disable(void) ;

void FRAME_ISR_SetPending(void) ;
void FRAME_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the FRAME_ISR ISR. */
#define FRAME_ISR_INTC_VECTOR            ((reg16 *) FRAME_ISR__INTC_VECT)

/* Address of the FRAME_ISR ISR priority. */
#define FRAME_ISR_INTC_PRIOR             ((reg8 *) FRAME_ISR__INTC_PRIOR_REG)

/* Priority of the FRAME_ISR interrupt. */
#define FRAME_ISR_INTC_PRIOR_NUMBER      FRAME_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable FRAME_ISR interrupt. */
#define FRAME_ISR_INTC_SET_EN            ((reg8 *) FRAME_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the FRAME_ISR interrupt. */
#define FRAME_ISR_INTC_CLR_EN            ((reg8 *) FRAME_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the FRAME_ISR interrupt state to pending. */
#define FRAME_ISR_INTC_SET_PD            ((reg8 *) FRAME_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the FRAME_ISR interrupt. */
#define FRAME_ISR_INTC_CLR_PD            ((reg8 *) FRAME_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_FRAME_ISR_H */


/* [] END OF FILE */
