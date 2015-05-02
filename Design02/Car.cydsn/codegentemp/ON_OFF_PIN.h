/*******************************************************************************
* File Name: ON_OFF_PIN.h  
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

#if !defined(CY_PINS_ON_OFF_PIN_H) /* Pins ON_OFF_PIN_H */
#define CY_PINS_ON_OFF_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ON_OFF_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ON_OFF_PIN_Write(uint8 value) ;
void    ON_OFF_PIN_SetDriveMode(uint8 mode) ;
uint8   ON_OFF_PIN_ReadDataReg(void) ;
uint8   ON_OFF_PIN_Read(void) ;
uint8   ON_OFF_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ON_OFF_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ON_OFF_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ON_OFF_PIN_DM_RES_UP          PIN_DM_RES_UP
#define ON_OFF_PIN_DM_RES_DWN         PIN_DM_RES_DWN
#define ON_OFF_PIN_DM_OD_LO           PIN_DM_OD_LO
#define ON_OFF_PIN_DM_OD_HI           PIN_DM_OD_HI
#define ON_OFF_PIN_DM_STRONG          PIN_DM_STRONG
#define ON_OFF_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ON_OFF_PIN_MASK               ON_OFF_PIN__MASK
#define ON_OFF_PIN_SHIFT              ON_OFF_PIN__SHIFT
#define ON_OFF_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ON_OFF_PIN_PS                     (* (reg8 *) ON_OFF_PIN__PS)
/* Data Register */
#define ON_OFF_PIN_DR                     (* (reg8 *) ON_OFF_PIN__DR)
/* Port Number */
#define ON_OFF_PIN_PRT_NUM                (* (reg8 *) ON_OFF_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define ON_OFF_PIN_AG                     (* (reg8 *) ON_OFF_PIN__AG)                       
/* Analog MUX bux enable */
#define ON_OFF_PIN_AMUX                   (* (reg8 *) ON_OFF_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define ON_OFF_PIN_BIE                    (* (reg8 *) ON_OFF_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define ON_OFF_PIN_BIT_MASK               (* (reg8 *) ON_OFF_PIN__BIT_MASK)
/* Bypass Enable */
#define ON_OFF_PIN_BYP                    (* (reg8 *) ON_OFF_PIN__BYP)
/* Port wide control signals */                                                   
#define ON_OFF_PIN_CTL                    (* (reg8 *) ON_OFF_PIN__CTL)
/* Drive Modes */
#define ON_OFF_PIN_DM0                    (* (reg8 *) ON_OFF_PIN__DM0) 
#define ON_OFF_PIN_DM1                    (* (reg8 *) ON_OFF_PIN__DM1)
#define ON_OFF_PIN_DM2                    (* (reg8 *) ON_OFF_PIN__DM2) 
/* Input Buffer Disable Override */
#define ON_OFF_PIN_INP_DIS                (* (reg8 *) ON_OFF_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define ON_OFF_PIN_LCD_COM_SEG            (* (reg8 *) ON_OFF_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define ON_OFF_PIN_LCD_EN                 (* (reg8 *) ON_OFF_PIN__LCD_EN)
/* Slew Rate Control */
#define ON_OFF_PIN_SLW                    (* (reg8 *) ON_OFF_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ON_OFF_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) ON_OFF_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ON_OFF_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ON_OFF_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ON_OFF_PIN_PRTDSI__OE_SEL0        (* (reg8 *) ON_OFF_PIN__PRTDSI__OE_SEL0) 
#define ON_OFF_PIN_PRTDSI__OE_SEL1        (* (reg8 *) ON_OFF_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ON_OFF_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) ON_OFF_PIN__PRTDSI__OUT_SEL0) 
#define ON_OFF_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) ON_OFF_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ON_OFF_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) ON_OFF_PIN__PRTDSI__SYNC_OUT) 


#if defined(ON_OFF_PIN__INTSTAT)  /* Interrupt Registers */

    #define ON_OFF_PIN_INTSTAT                (* (reg8 *) ON_OFF_PIN__INTSTAT)
    #define ON_OFF_PIN_SNAP                   (* (reg8 *) ON_OFF_PIN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins ON_OFF_PIN_H */


/* [] END OF FILE */
