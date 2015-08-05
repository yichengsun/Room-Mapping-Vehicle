/*******************************************************************************
* File Name: CAM_READ_ISR.h
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

#if !defined(CY_ISR_CAM_READ_ISR_H)
#define CY_ISR_CAM_READ_ISR_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void CAM_READ_ISR_Start(void) ;
void CAM_READ_ISR_StartEx(cyisraddress address) ;
void CAM_READ_ISR_Stop(void) ;

CY_ISR_PROTO(CAM_READ_ISR_Interrupt);

void CAM_READ_ISR_SetVector(cyisraddress address) ;
cyisraddress CAM_READ_ISR_GetVector(void) ;

void CAM_READ_ISR_SetPriority(uint8 priority) ;
uint8 CAM_READ_ISR_GetPriority(void) ;

void CAM_READ_ISR_Enable(void) ;
uint8 CAM_READ_ISR_GetState(void) ;
void CAM_READ_ISR_Disable(void) ;

void CAM_READ_ISR_SetPending(void) ;
void CAM_READ_ISR_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the CAM_READ_ISR ISR. */
#define CAM_READ_ISR_INTC_VECTOR            ((reg16 *) CAM_READ_ISR__INTC_VECT)

/* Address of the CAM_READ_ISR ISR priority. */
#define CAM_READ_ISR_INTC_PRIOR             ((reg8 *) CAM_READ_ISR__INTC_PRIOR_REG)

/* Priority of the CAM_READ_ISR interrupt. */
#define CAM_READ_ISR_INTC_PRIOR_NUMBER      CAM_READ_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable CAM_READ_ISR interrupt. */
#define CAM_READ_ISR_INTC_SET_EN            ((reg8 *) CAM_READ_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the CAM_READ_ISR interrupt. */
#define CAM_READ_ISR_INTC_CLR_EN            ((reg8 *) CAM_READ_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the CAM_READ_ISR interrupt state to pending. */
#define CAM_READ_ISR_INTC_SET_PD            ((reg8 *) CAM_READ_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the CAM_READ_ISR interrupt. */
#define CAM_READ_ISR_INTC_CLR_PD            ((reg8 *) CAM_READ_ISR__INTC_CLR_PD_REG)



#endif /* CY_ISR_CAM_READ_ISR_H */


/* [] END OF FILE */
