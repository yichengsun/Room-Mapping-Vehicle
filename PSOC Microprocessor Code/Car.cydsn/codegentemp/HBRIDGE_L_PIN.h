/*******************************************************************************
* File Name: HBRIDGE_L_PIN.h  
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

#if !defined(CY_PINS_HBRIDGE_L_PIN_H) /* Pins HBRIDGE_L_PIN_H */
#define CY_PINS_HBRIDGE_L_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HBRIDGE_L_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    HBRIDGE_L_PIN_Write(uint8 value) ;
void    HBRIDGE_L_PIN_SetDriveMode(uint8 mode) ;
uint8   HBRIDGE_L_PIN_ReadDataReg(void) ;
uint8   HBRIDGE_L_PIN_Read(void) ;
uint8   HBRIDGE_L_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HBRIDGE_L_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HBRIDGE_L_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HBRIDGE_L_PIN_DM_RES_UP          PIN_DM_RES_UP
#define HBRIDGE_L_PIN_DM_RES_DWN         PIN_DM_RES_DWN
#define HBRIDGE_L_PIN_DM_OD_LO           PIN_DM_OD_LO
#define HBRIDGE_L_PIN_DM_OD_HI           PIN_DM_OD_HI
#define HBRIDGE_L_PIN_DM_STRONG          PIN_DM_STRONG
#define HBRIDGE_L_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HBRIDGE_L_PIN_MASK               HBRIDGE_L_PIN__MASK
#define HBRIDGE_L_PIN_SHIFT              HBRIDGE_L_PIN__SHIFT
#define HBRIDGE_L_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HBRIDGE_L_PIN_PS                     (* (reg8 *) HBRIDGE_L_PIN__PS)
/* Data Register */
#define HBRIDGE_L_PIN_DR                     (* (reg8 *) HBRIDGE_L_PIN__DR)
/* Port Number */
#define HBRIDGE_L_PIN_PRT_NUM                (* (reg8 *) HBRIDGE_L_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define HBRIDGE_L_PIN_AG                     (* (reg8 *) HBRIDGE_L_PIN__AG)                       
/* Analog MUX bux enable */
#define HBRIDGE_L_PIN_AMUX                   (* (reg8 *) HBRIDGE_L_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define HBRIDGE_L_PIN_BIE                    (* (reg8 *) HBRIDGE_L_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define HBRIDGE_L_PIN_BIT_MASK               (* (reg8 *) HBRIDGE_L_PIN__BIT_MASK)
/* Bypass Enable */
#define HBRIDGE_L_PIN_BYP                    (* (reg8 *) HBRIDGE_L_PIN__BYP)
/* Port wide control signals */                                                   
#define HBRIDGE_L_PIN_CTL                    (* (reg8 *) HBRIDGE_L_PIN__CTL)
/* Drive Modes */
#define HBRIDGE_L_PIN_DM0                    (* (reg8 *) HBRIDGE_L_PIN__DM0) 
#define HBRIDGE_L_PIN_DM1                    (* (reg8 *) HBRIDGE_L_PIN__DM1)
#define HBRIDGE_L_PIN_DM2                    (* (reg8 *) HBRIDGE_L_PIN__DM2) 
/* Input Buffer Disable Override */
#define HBRIDGE_L_PIN_INP_DIS                (* (reg8 *) HBRIDGE_L_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define HBRIDGE_L_PIN_LCD_COM_SEG            (* (reg8 *) HBRIDGE_L_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define HBRIDGE_L_PIN_LCD_EN                 (* (reg8 *) HBRIDGE_L_PIN__LCD_EN)
/* Slew Rate Control */
#define HBRIDGE_L_PIN_SLW                    (* (reg8 *) HBRIDGE_L_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HBRIDGE_L_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) HBRIDGE_L_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HBRIDGE_L_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HBRIDGE_L_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HBRIDGE_L_PIN_PRTDSI__OE_SEL0        (* (reg8 *) HBRIDGE_L_PIN__PRTDSI__OE_SEL0) 
#define HBRIDGE_L_PIN_PRTDSI__OE_SEL1        (* (reg8 *) HBRIDGE_L_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HBRIDGE_L_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) HBRIDGE_L_PIN__PRTDSI__OUT_SEL0) 
#define HBRIDGE_L_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) HBRIDGE_L_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HBRIDGE_L_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) HBRIDGE_L_PIN__PRTDSI__SYNC_OUT) 


#if defined(HBRIDGE_L_PIN__INTSTAT)  /* Interrupt Registers */

    #define HBRIDGE_L_PIN_INTSTAT                (* (reg8 *) HBRIDGE_L_PIN__INTSTAT)
    #define HBRIDGE_L_PIN_SNAP                   (* (reg8 *) HBRIDGE_L_PIN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins HBRIDGE_L_PIN_H */


/* [] END OF FILE */
