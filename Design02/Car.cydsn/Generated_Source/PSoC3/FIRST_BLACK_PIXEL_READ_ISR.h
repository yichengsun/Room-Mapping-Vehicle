/*******************************************************************************
* File Name: FIRST_BLACK_PIXEL_READ_ISR.h
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

#if !defined(CY_ISR_FIRST_BLACK_PIXEL_READ_ISR_H)
#define CY_ISR_FIRST_BLACK_PIXEL_READ_ISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void FIRST_BLACK_PIXEL_READ_ISR_Start(void) ;
void FIRST_BLACK_PIXEL_READ_ISR_StartEx(cyisraddress address) ;
void FIRST_BLACK_PIXEL_READ_ISR_Stop(void) ;

CY_ISR_PROTO(FIRST_BLACK_PIXEL_READ_ISR_Interrupt);

void FIRST_BLACK_PIXEL_READ_ISR_SetVector(cyisraddress address) ;
cyisraddress FIRST_BLACK_PIXEL_READ_ISR_GetVector(void) ;

void FIRST_BLACK_PIXEL_READ_ISR_SetPriority(uint8 priority) ;
uint8 FIRST_BLACK_PIXEL_READ_ISR_GetPriority(void) ;

void FIRST_BLACK_PIXEL_READ_ISR_Enable(void) ;
uint8 FIRST_BLACK_PIXEL_READ_ISR_GetState(void) ;
void FIRST_BLACK_PIXEL_READ_ISR_Disable(void) ;

void FIRST_BLACK_PIXEL_READ_ISR_SetPending(void) ;
void FIRST_BLACK_PIXEL_READ_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the FIRST_BLACK_PIXEL_READ_ISR ISR. */
#define FIRST_BLACK_PIXEL_READ_ISR_INTC_VECTOR            ((reg16 *) FIRST_BLACK_PIXEL_READ_ISR__INTC_VECT)

/* Address of the FIRST_BLACK_PIXEL_READ_ISR ISR priority. */
#define FIRST_BLACK_PIXEL_READ_ISR_INTC_PRIOR             ((reg8 *) FIRST_BLACK_PIXEL_READ_ISR__INTC_PRIOR_REG)

/* Priority of the FIRST_BLACK_PIXEL_READ_ISR interrupt. */
#define FIRST_BLACK_PIXEL_READ_ISR_INTC_PRIOR_NUMBER      FIRST_BLACK_PIXEL_READ_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable FIRST_BLACK_PIXEL_READ_ISR interrupt. */
#define FIRST_BLACK_PIXEL_READ_ISR_INTC_SET_EN            ((reg8 *) FIRST_BLACK_PIXEL_READ_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the FIRST_BLACK_PIXEL_READ_ISR interrupt. */
#define FIRST_BLACK_PIXEL_READ_ISR_INTC_CLR_EN            ((reg8 *) FIRST_BLACK_PIXEL_READ_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the FIRST_BLACK_PIXEL_READ_ISR interrupt state to pending. */
#define FIRST_BLACK_PIXEL_READ_ISR_INTC_SET_PD            ((reg8 *) FIRST_BLACK_PIXEL_READ_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the FIRST_BLACK_PIXEL_READ_ISR interrupt. */
#define FIRST_BLACK_PIXEL_READ_ISR_INTC_CLR_PD            ((reg8 *) FIRST_BLACK_PIXEL_READ_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_FIRST_BLACK_PIXEL_READ_ISR_H */


/* [] END OF FILE */
