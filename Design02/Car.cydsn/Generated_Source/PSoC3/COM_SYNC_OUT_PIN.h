/*******************************************************************************
* File Name: COM_SYNC_OUT_PIN.h  
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

#if !defined(CY_PINS_COM_SYNC_OUT_PIN_H) /* Pins COM_SYNC_OUT_PIN_H */
#define CY_PINS_COM_SYNC_OUT_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "COM_SYNC_OUT_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    COM_SYNC_OUT_PIN_Write(uint8 value) ;
void    COM_SYNC_OUT_PIN_SetDriveMode(uint8 mode) ;
uint8   COM_SYNC_OUT_PIN_ReadDataReg(void) ;
uint8   COM_SYNC_OUT_PIN_Read(void) ;
uint8   COM_SYNC_OUT_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define COM_SYNC_OUT_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define COM_SYNC_OUT_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define COM_SYNC_OUT_PIN_DM_RES_UP          PIN_DM_RES_UP
#define COM_SYNC_OUT_PIN_DM_RES_DWN         PIN_DM_RES_DWN
#define COM_SYNC_OUT_PIN_DM_OD_LO           PIN_DM_OD_LO
#define COM_SYNC_OUT_PIN_DM_OD_HI           PIN_DM_OD_HI
#define COM_SYNC_OUT_PIN_DM_STRONG          PIN_DM_STRONG
#define COM_SYNC_OUT_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define COM_SYNC_OUT_PIN_MASK               COM_SYNC_OUT_PIN__MASK
#define COM_SYNC_OUT_PIN_SHIFT              COM_SYNC_OUT_PIN__SHIFT
#define COM_SYNC_OUT_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define COM_SYNC_OUT_PIN_PS                     (* (reg8 *) COM_SYNC_OUT_PIN__PS)
/* Data Register */
#define COM_SYNC_OUT_PIN_DR                     (* (reg8 *) COM_SYNC_OUT_PIN__DR)
/* Port Number */
#define COM_SYNC_OUT_PIN_PRT_NUM                (* (reg8 *) COM_SYNC_OUT_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define COM_SYNC_OUT_PIN_AG                     (* (reg8 *) COM_SYNC_OUT_PIN__AG)                       
/* Analog MUX bux enable */
#define COM_SYNC_OUT_PIN_AMUX                   (* (reg8 *) COM_SYNC_OUT_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define COM_SYNC_OUT_PIN_BIE                    (* (reg8 *) COM_SYNC_OUT_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define COM_SYNC_OUT_PIN_BIT_MASK               (* (reg8 *) COM_SYNC_OUT_PIN__BIT_MASK)
/* Bypass Enable */
#define COM_SYNC_OUT_PIN_BYP                    (* (reg8 *) COM_SYNC_OUT_PIN__BYP)
/* Port wide control signals */                                                   
#define COM_SYNC_OUT_PIN_CTL                    (* (reg8 *) COM_SYNC_OUT_PIN__CTL)
/* Drive Modes */
#define COM_SYNC_OUT_PIN_DM0                    (* (reg8 *) COM_SYNC_OUT_PIN__DM0) 
#define COM_SYNC_OUT_PIN_DM1                    (* (reg8 *) COM_SYNC_OUT_PIN__DM1)
#define COM_SYNC_OUT_PIN_DM2                    (* (reg8 *) COM_SYNC_OUT_PIN__DM2) 
/* Input Buffer Disable Override */
#define COM_SYNC_OUT_PIN_INP_DIS                (* (reg8 *) COM_SYNC_OUT_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define COM_SYNC_OUT_PIN_LCD_COM_SEG            (* (reg8 *) COM_SYNC_OUT_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define COM_SYNC_OUT_PIN_LCD_EN                 (* (reg8 *) COM_SYNC_OUT_PIN__LCD_EN)
/* Slew Rate Control */
#define COM_SYNC_OUT_PIN_SLW                    (* (reg8 *) COM_SYNC_OUT_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define COM_SYNC_OUT_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) COM_SYNC_OUT_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define COM_SYNC_OUT_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) COM_SYNC_OUT_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define COM_SYNC_OUT_PIN_PRTDSI__OE_SEL0        (* (reg8 *) COM_SYNC_OUT_PIN__PRTDSI__OE_SEL0) 
#define COM_SYNC_OUT_PIN_PRTDSI__OE_SEL1        (* (reg8 *) COM_SYNC_OUT_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define COM_SYNC_OUT_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) COM_SYNC_OUT_PIN__PRTDSI__OUT_SEL0) 
#define COM_SYNC_OUT_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) COM_SYNC_OUT_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define COM_SYNC_OUT_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) COM_SYNC_OUT_PIN__PRTDSI__SYNC_OUT) 


#if defined(COM_SYNC_OUT_PIN__INTSTAT)  /* Interrupt Registers */

    #define COM_SYNC_OUT_PIN_INTSTAT                (* (reg8 *) COM_SYNC_OUT_PIN__INTSTAT)
    #define COM_SYNC_OUT_PIN_SNAP                   (* (reg8 *) COM_SYNC_OUT_PIN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins COM_SYNC_OUT_PIN_H */


/* [] END OF FILE */
