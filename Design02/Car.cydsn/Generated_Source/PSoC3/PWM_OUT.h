/*******************************************************************************
* File Name: PWM_OUT.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_PWM_OUT_H) /* Pins PWM_OUT_H */
#define CY_PINS_PWM_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM_OUT_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM_OUT_Write(uint8 value) ;
void    PWM_OUT_SetDriveMode(uint8 mode) ;
uint8   PWM_OUT_ReadDataReg(void) ;
uint8   PWM_OUT_Read(void) ;
uint8   PWM_OUT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM_OUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWM_OUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWM_OUT_DM_RES_UP          PIN_DM_RES_UP
#define PWM_OUT_DM_RES_DWN         PIN_DM_RES_DWN
#define PWM_OUT_DM_OD_LO           PIN_DM_OD_LO
#define PWM_OUT_DM_OD_HI           PIN_DM_OD_HI
#define PWM_OUT_DM_STRONG          PIN_DM_STRONG
#define PWM_OUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWM_OUT_MASK               PWM_OUT__MASK
#define PWM_OUT_SHIFT              PWM_OUT__SHIFT
#define PWM_OUT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM_OUT_PS                     (* (reg8 *) PWM_OUT__PS)
/* Data Register */
#define PWM_OUT_DR                     (* (reg8 *) PWM_OUT__DR)
/* Port Number */
#define PWM_OUT_PRT_NUM                (* (reg8 *) PWM_OUT__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM_OUT_AG                     (* (reg8 *) PWM_OUT__AG)                       
/* Analog MUX bux enable */
#define PWM_OUT_AMUX                   (* (reg8 *) PWM_OUT__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM_OUT_BIE                    (* (reg8 *) PWM_OUT__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM_OUT_BIT_MASK               (* (reg8 *) PWM_OUT__BIT_MASK)
/* Bypass Enable */
#define PWM_OUT_BYP                    (* (reg8 *) PWM_OUT__BYP)
/* Port wide control signals */                                                   
#define PWM_OUT_CTL                    (* (reg8 *) PWM_OUT__CTL)
/* Drive Modes */
#define PWM_OUT_DM0                    (* (reg8 *) PWM_OUT__DM0) 
#define PWM_OUT_DM1                    (* (reg8 *) PWM_OUT__DM1)
#define PWM_OUT_DM2                    (* (reg8 *) PWM_OUT__DM2) 
/* Input Buffer Disable Override */
#define PWM_OUT_INP_DIS                (* (reg8 *) PWM_OUT__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM_OUT_LCD_COM_SEG            (* (reg8 *) PWM_OUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM_OUT_LCD_EN                 (* (reg8 *) PWM_OUT__LCD_EN)
/* Slew Rate Control */
#define PWM_OUT_SLW                    (* (reg8 *) PWM_OUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM_OUT_PRTDSI__CAPS_SEL       (* (reg8 *) PWM_OUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM_OUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM_OUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM_OUT_PRTDSI__OE_SEL0        (* (reg8 *) PWM_OUT__PRTDSI__OE_SEL0) 
#define PWM_OUT_PRTDSI__OE_SEL1        (* (reg8 *) PWM_OUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM_OUT_PRTDSI__OUT_SEL0       (* (reg8 *) PWM_OUT__PRTDSI__OUT_SEL0) 
#define PWM_OUT_PRTDSI__OUT_SEL1       (* (reg8 *) PWM_OUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM_OUT_PRTDSI__SYNC_OUT       (* (reg8 *) PWM_OUT__PRTDSI__SYNC_OUT) 


#if defined(PWM_OUT__INTSTAT)  /* Interrupt Registers */

    #define PWM_OUT_INTSTAT                (* (reg8 *) PWM_OUT__INTSTAT)
    #define PWM_OUT_SNAP                   (* (reg8 *) PWM_OUT__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins PWM_OUT_H */


/* [] END OF FILE */
