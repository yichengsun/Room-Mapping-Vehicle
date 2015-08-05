/*******************************************************************************
* File Name: HE_IN_PIN.h  
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

#if !defined(CY_PINS_HE_IN_PIN_H) /* Pins HE_IN_PIN_H */
#define CY_PINS_HE_IN_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HE_IN_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    HE_IN_PIN_Write(uint8 value) ;
void    HE_IN_PIN_SetDriveMode(uint8 mode) ;
uint8   HE_IN_PIN_ReadDataReg(void) ;
uint8   HE_IN_PIN_Read(void) ;
uint8   HE_IN_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HE_IN_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HE_IN_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HE_IN_PIN_DM_RES_UP          PIN_DM_RES_UP
#define HE_IN_PIN_DM_RES_DWN         PIN_DM_RES_DWN
#define HE_IN_PIN_DM_OD_LO           PIN_DM_OD_LO
#define HE_IN_PIN_DM_OD_HI           PIN_DM_OD_HI
#define HE_IN_PIN_DM_STRONG          PIN_DM_STRONG
#define HE_IN_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HE_IN_PIN_MASK               HE_IN_PIN__MASK
#define HE_IN_PIN_SHIFT              HE_IN_PIN__SHIFT
#define HE_IN_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HE_IN_PIN_PS                     (* (reg8 *) HE_IN_PIN__PS)
/* Data Register */
#define HE_IN_PIN_DR                     (* (reg8 *) HE_IN_PIN__DR)
/* Port Number */
#define HE_IN_PIN_PRT_NUM                (* (reg8 *) HE_IN_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define HE_IN_PIN_AG                     (* (reg8 *) HE_IN_PIN__AG)                       
/* Analog MUX bux enable */
#define HE_IN_PIN_AMUX                   (* (reg8 *) HE_IN_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define HE_IN_PIN_BIE                    (* (reg8 *) HE_IN_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define HE_IN_PIN_BIT_MASK               (* (reg8 *) HE_IN_PIN__BIT_MASK)
/* Bypass Enable */
#define HE_IN_PIN_BYP                    (* (reg8 *) HE_IN_PIN__BYP)
/* Port wide control signals */                                                   
#define HE_IN_PIN_CTL                    (* (reg8 *) HE_IN_PIN__CTL)
/* Drive Modes */
#define HE_IN_PIN_DM0                    (* (reg8 *) HE_IN_PIN__DM0) 
#define HE_IN_PIN_DM1                    (* (reg8 *) HE_IN_PIN__DM1)
#define HE_IN_PIN_DM2                    (* (reg8 *) HE_IN_PIN__DM2) 
/* Input Buffer Disable Override */
#define HE_IN_PIN_INP_DIS                (* (reg8 *) HE_IN_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define HE_IN_PIN_LCD_COM_SEG            (* (reg8 *) HE_IN_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define HE_IN_PIN_LCD_EN                 (* (reg8 *) HE_IN_PIN__LCD_EN)
/* Slew Rate Control */
#define HE_IN_PIN_SLW                    (* (reg8 *) HE_IN_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HE_IN_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) HE_IN_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HE_IN_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HE_IN_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HE_IN_PIN_PRTDSI__OE_SEL0        (* (reg8 *) HE_IN_PIN__PRTDSI__OE_SEL0) 
#define HE_IN_PIN_PRTDSI__OE_SEL1        (* (reg8 *) HE_IN_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HE_IN_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) HE_IN_PIN__PRTDSI__OUT_SEL0) 
#define HE_IN_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) HE_IN_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HE_IN_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) HE_IN_PIN__PRTDSI__SYNC_OUT) 


#if defined(HE_IN_PIN__INTSTAT)  /* Interrupt Registers */

    #define HE_IN_PIN_INTSTAT                (* (reg8 *) HE_IN_PIN__INTSTAT)
    #define HE_IN_PIN_SNAP                   (* (reg8 *) HE_IN_PIN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins HE_IN_PIN_H */


/* [] END OF FILE */
