/*******************************************************************************
* File Name: DIRECTION_PIN.h  
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

#if !defined(CY_PINS_DIRECTION_PIN_H) /* Pins DIRECTION_PIN_H */
#define CY_PINS_DIRECTION_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIRECTION_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    DIRECTION_PIN_Write(uint8 value) ;
void    DIRECTION_PIN_SetDriveMode(uint8 mode) ;
uint8   DIRECTION_PIN_ReadDataReg(void) ;
uint8   DIRECTION_PIN_Read(void) ;
uint8   DIRECTION_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DIRECTION_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DIRECTION_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DIRECTION_PIN_DM_RES_UP          PIN_DM_RES_UP
#define DIRECTION_PIN_DM_RES_DWN         PIN_DM_RES_DWN
#define DIRECTION_PIN_DM_OD_LO           PIN_DM_OD_LO
#define DIRECTION_PIN_DM_OD_HI           PIN_DM_OD_HI
#define DIRECTION_PIN_DM_STRONG          PIN_DM_STRONG
#define DIRECTION_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DIRECTION_PIN_MASK               DIRECTION_PIN__MASK
#define DIRECTION_PIN_SHIFT              DIRECTION_PIN__SHIFT
#define DIRECTION_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIRECTION_PIN_PS                     (* (reg8 *) DIRECTION_PIN__PS)
/* Data Register */
#define DIRECTION_PIN_DR                     (* (reg8 *) DIRECTION_PIN__DR)
/* Port Number */
#define DIRECTION_PIN_PRT_NUM                (* (reg8 *) DIRECTION_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define DIRECTION_PIN_AG                     (* (reg8 *) DIRECTION_PIN__AG)                       
/* Analog MUX bux enable */
#define DIRECTION_PIN_AMUX                   (* (reg8 *) DIRECTION_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define DIRECTION_PIN_BIE                    (* (reg8 *) DIRECTION_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define DIRECTION_PIN_BIT_MASK               (* (reg8 *) DIRECTION_PIN__BIT_MASK)
/* Bypass Enable */
#define DIRECTION_PIN_BYP                    (* (reg8 *) DIRECTION_PIN__BYP)
/* Port wide control signals */                                                   
#define DIRECTION_PIN_CTL                    (* (reg8 *) DIRECTION_PIN__CTL)
/* Drive Modes */
#define DIRECTION_PIN_DM0                    (* (reg8 *) DIRECTION_PIN__DM0) 
#define DIRECTION_PIN_DM1                    (* (reg8 *) DIRECTION_PIN__DM1)
#define DIRECTION_PIN_DM2                    (* (reg8 *) DIRECTION_PIN__DM2) 
/* Input Buffer Disable Override */
#define DIRECTION_PIN_INP_DIS                (* (reg8 *) DIRECTION_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define DIRECTION_PIN_LCD_COM_SEG            (* (reg8 *) DIRECTION_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIRECTION_PIN_LCD_EN                 (* (reg8 *) DIRECTION_PIN__LCD_EN)
/* Slew Rate Control */
#define DIRECTION_PIN_SLW                    (* (reg8 *) DIRECTION_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIRECTION_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) DIRECTION_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIRECTION_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIRECTION_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIRECTION_PIN_PRTDSI__OE_SEL0        (* (reg8 *) DIRECTION_PIN__PRTDSI__OE_SEL0) 
#define DIRECTION_PIN_PRTDSI__OE_SEL1        (* (reg8 *) DIRECTION_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIRECTION_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) DIRECTION_PIN__PRTDSI__OUT_SEL0) 
#define DIRECTION_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) DIRECTION_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIRECTION_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) DIRECTION_PIN__PRTDSI__SYNC_OUT) 


#if defined(DIRECTION_PIN__INTSTAT)  /* Interrupt Registers */

    #define DIRECTION_PIN_INTSTAT                (* (reg8 *) DIRECTION_PIN__INTSTAT)
    #define DIRECTION_PIN_SNAP                   (* (reg8 *) DIRECTION_PIN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins DIRECTION_PIN_H */


/* [] END OF FILE */
