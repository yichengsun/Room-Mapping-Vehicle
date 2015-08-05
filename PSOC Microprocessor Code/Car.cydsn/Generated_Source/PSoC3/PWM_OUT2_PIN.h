/*******************************************************************************
* File Name: PWM_OUT2_PIN.h  
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

#if !defined(CY_PINS_PWM_OUT2_PIN_H) /* Pins PWM_OUT2_PIN_H */
#define CY_PINS_PWM_OUT2_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM_OUT2_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM_OUT2_PIN_Write(uint8 value) ;
void    PWM_OUT2_PIN_SetDriveMode(uint8 mode) ;
uint8   PWM_OUT2_PIN_ReadDataReg(void) ;
uint8   PWM_OUT2_PIN_Read(void) ;
uint8   PWM_OUT2_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM_OUT2_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWM_OUT2_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWM_OUT2_PIN_DM_RES_UP          PIN_DM_RES_UP
#define PWM_OUT2_PIN_DM_RES_DWN         PIN_DM_RES_DWN
#define PWM_OUT2_PIN_DM_OD_LO           PIN_DM_OD_LO
#define PWM_OUT2_PIN_DM_OD_HI           PIN_DM_OD_HI
#define PWM_OUT2_PIN_DM_STRONG          PIN_DM_STRONG
#define PWM_OUT2_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWM_OUT2_PIN_MASK               PWM_OUT2_PIN__MASK
#define PWM_OUT2_PIN_SHIFT              PWM_OUT2_PIN__SHIFT
#define PWM_OUT2_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM_OUT2_PIN_PS                     (* (reg8 *) PWM_OUT2_PIN__PS)
/* Data Register */
#define PWM_OUT2_PIN_DR                     (* (reg8 *) PWM_OUT2_PIN__DR)
/* Port Number */
#define PWM_OUT2_PIN_PRT_NUM                (* (reg8 *) PWM_OUT2_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM_OUT2_PIN_AG                     (* (reg8 *) PWM_OUT2_PIN__AG)                       
/* Analog MUX bux enable */
#define PWM_OUT2_PIN_AMUX                   (* (reg8 *) PWM_OUT2_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM_OUT2_PIN_BIE                    (* (reg8 *) PWM_OUT2_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM_OUT2_PIN_BIT_MASK               (* (reg8 *) PWM_OUT2_PIN__BIT_MASK)
/* Bypass Enable */
#define PWM_OUT2_PIN_BYP                    (* (reg8 *) PWM_OUT2_PIN__BYP)
/* Port wide control signals */                                                   
#define PWM_OUT2_PIN_CTL                    (* (reg8 *) PWM_OUT2_PIN__CTL)
/* Drive Modes */
#define PWM_OUT2_PIN_DM0                    (* (reg8 *) PWM_OUT2_PIN__DM0) 
#define PWM_OUT2_PIN_DM1                    (* (reg8 *) PWM_OUT2_PIN__DM1)
#define PWM_OUT2_PIN_DM2                    (* (reg8 *) PWM_OUT2_PIN__DM2) 
/* Input Buffer Disable Override */
#define PWM_OUT2_PIN_INP_DIS                (* (reg8 *) PWM_OUT2_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM_OUT2_PIN_LCD_COM_SEG            (* (reg8 *) PWM_OUT2_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM_OUT2_PIN_LCD_EN                 (* (reg8 *) PWM_OUT2_PIN__LCD_EN)
/* Slew Rate Control */
#define PWM_OUT2_PIN_SLW                    (* (reg8 *) PWM_OUT2_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM_OUT2_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) PWM_OUT2_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM_OUT2_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM_OUT2_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM_OUT2_PIN_PRTDSI__OE_SEL0        (* (reg8 *) PWM_OUT2_PIN__PRTDSI__OE_SEL0) 
#define PWM_OUT2_PIN_PRTDSI__OE_SEL1        (* (reg8 *) PWM_OUT2_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM_OUT2_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) PWM_OUT2_PIN__PRTDSI__OUT_SEL0) 
#define PWM_OUT2_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) PWM_OUT2_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM_OUT2_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) PWM_OUT2_PIN__PRTDSI__SYNC_OUT) 


#if defined(PWM_OUT2_PIN__INTSTAT)  /* Interrupt Registers */

    #define PWM_OUT2_PIN_INTSTAT                (* (reg8 *) PWM_OUT2_PIN__INTSTAT)
    #define PWM_OUT2_PIN_SNAP                   (* (reg8 *) PWM_OUT2_PIN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins PWM_OUT2_PIN_H */


/* [] END OF FILE */
