/*******************************************************************************
* File Name: COMP_VREF.h  
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

#if !defined(CY_PINS_COMP_VREF_H) /* Pins COMP_VREF_H */
#define CY_PINS_COMP_VREF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "COMP_VREF_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    COMP_VREF_Write(uint8 value) ;
void    COMP_VREF_SetDriveMode(uint8 mode) ;
uint8   COMP_VREF_ReadDataReg(void) ;
uint8   COMP_VREF_Read(void) ;
uint8   COMP_VREF_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define COMP_VREF_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define COMP_VREF_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define COMP_VREF_DM_RES_UP          PIN_DM_RES_UP
#define COMP_VREF_DM_RES_DWN         PIN_DM_RES_DWN
#define COMP_VREF_DM_OD_LO           PIN_DM_OD_LO
#define COMP_VREF_DM_OD_HI           PIN_DM_OD_HI
#define COMP_VREF_DM_STRONG          PIN_DM_STRONG
#define COMP_VREF_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define COMP_VREF_MASK               COMP_VREF__MASK
#define COMP_VREF_SHIFT              COMP_VREF__SHIFT
#define COMP_VREF_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define COMP_VREF_PS                     (* (reg8 *) COMP_VREF__PS)
/* Data Register */
#define COMP_VREF_DR                     (* (reg8 *) COMP_VREF__DR)
/* Port Number */
#define COMP_VREF_PRT_NUM                (* (reg8 *) COMP_VREF__PRT) 
/* Connect to Analog Globals */                                                  
#define COMP_VREF_AG                     (* (reg8 *) COMP_VREF__AG)                       
/* Analog MUX bux enable */
#define COMP_VREF_AMUX                   (* (reg8 *) COMP_VREF__AMUX) 
/* Bidirectional Enable */                                                        
#define COMP_VREF_BIE                    (* (reg8 *) COMP_VREF__BIE)
/* Bit-mask for Aliased Register Access */
#define COMP_VREF_BIT_MASK               (* (reg8 *) COMP_VREF__BIT_MASK)
/* Bypass Enable */
#define COMP_VREF_BYP                    (* (reg8 *) COMP_VREF__BYP)
/* Port wide control signals */                                                   
#define COMP_VREF_CTL                    (* (reg8 *) COMP_VREF__CTL)
/* Drive Modes */
#define COMP_VREF_DM0                    (* (reg8 *) COMP_VREF__DM0) 
#define COMP_VREF_DM1                    (* (reg8 *) COMP_VREF__DM1)
#define COMP_VREF_DM2                    (* (reg8 *) COMP_VREF__DM2) 
/* Input Buffer Disable Override */
#define COMP_VREF_INP_DIS                (* (reg8 *) COMP_VREF__INP_DIS)
/* LCD Common or Segment Drive */
#define COMP_VREF_LCD_COM_SEG            (* (reg8 *) COMP_VREF__LCD_COM_SEG)
/* Enable Segment LCD */
#define COMP_VREF_LCD_EN                 (* (reg8 *) COMP_VREF__LCD_EN)
/* Slew Rate Control */
#define COMP_VREF_SLW                    (* (reg8 *) COMP_VREF__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define COMP_VREF_PRTDSI__CAPS_SEL       (* (reg8 *) COMP_VREF__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define COMP_VREF_PRTDSI__DBL_SYNC_IN    (* (reg8 *) COMP_VREF__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define COMP_VREF_PRTDSI__OE_SEL0        (* (reg8 *) COMP_VREF__PRTDSI__OE_SEL0) 
#define COMP_VREF_PRTDSI__OE_SEL1        (* (reg8 *) COMP_VREF__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define COMP_VREF_PRTDSI__OUT_SEL0       (* (reg8 *) COMP_VREF__PRTDSI__OUT_SEL0) 
#define COMP_VREF_PRTDSI__OUT_SEL1       (* (reg8 *) COMP_VREF__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define COMP_VREF_PRTDSI__SYNC_OUT       (* (reg8 *) COMP_VREF__PRTDSI__SYNC_OUT) 


#if defined(COMP_VREF__INTSTAT)  /* Interrupt Registers */

    #define COMP_VREF_INTSTAT                (* (reg8 *) COMP_VREF__INTSTAT)
    #define COMP_VREF_SNAP                   (* (reg8 *) COMP_VREF__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins COMP_VREF_H */


/* [] END OF FILE */
