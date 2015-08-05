/*******************************************************************************
* File Name: VERT_SYNC_OUT_PIN.h  
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

#if !defined(CY_PINS_VERT_SYNC_OUT_PIN_H) /* Pins VERT_SYNC_OUT_PIN_H */
#define CY_PINS_VERT_SYNC_OUT_PIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VERT_SYNC_OUT_PIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    VERT_SYNC_OUT_PIN_Write(uint8 value) ;
void    VERT_SYNC_OUT_PIN_SetDriveMode(uint8 mode) ;
uint8   VERT_SYNC_OUT_PIN_ReadDataReg(void) ;
uint8   VERT_SYNC_OUT_PIN_Read(void) ;
uint8   VERT_SYNC_OUT_PIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VERT_SYNC_OUT_PIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VERT_SYNC_OUT_PIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VERT_SYNC_OUT_PIN_DM_RES_UP          PIN_DM_RES_UP
#define VERT_SYNC_OUT_PIN_DM_RES_DWN         PIN_DM_RES_DWN
#define VERT_SYNC_OUT_PIN_DM_OD_LO           PIN_DM_OD_LO
#define VERT_SYNC_OUT_PIN_DM_OD_HI           PIN_DM_OD_HI
#define VERT_SYNC_OUT_PIN_DM_STRONG          PIN_DM_STRONG
#define VERT_SYNC_OUT_PIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VERT_SYNC_OUT_PIN_MASK               VERT_SYNC_OUT_PIN__MASK
#define VERT_SYNC_OUT_PIN_SHIFT              VERT_SYNC_OUT_PIN__SHIFT
#define VERT_SYNC_OUT_PIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VERT_SYNC_OUT_PIN_PS                     (* (reg8 *) VERT_SYNC_OUT_PIN__PS)
/* Data Register */
#define VERT_SYNC_OUT_PIN_DR                     (* (reg8 *) VERT_SYNC_OUT_PIN__DR)
/* Port Number */
#define VERT_SYNC_OUT_PIN_PRT_NUM                (* (reg8 *) VERT_SYNC_OUT_PIN__PRT) 
/* Connect to Analog Globals */                                                  
#define VERT_SYNC_OUT_PIN_AG                     (* (reg8 *) VERT_SYNC_OUT_PIN__AG)                       
/* Analog MUX bux enable */
#define VERT_SYNC_OUT_PIN_AMUX                   (* (reg8 *) VERT_SYNC_OUT_PIN__AMUX) 
/* Bidirectional Enable */                                                        
#define VERT_SYNC_OUT_PIN_BIE                    (* (reg8 *) VERT_SYNC_OUT_PIN__BIE)
/* Bit-mask for Aliased Register Access */
#define VERT_SYNC_OUT_PIN_BIT_MASK               (* (reg8 *) VERT_SYNC_OUT_PIN__BIT_MASK)
/* Bypass Enable */
#define VERT_SYNC_OUT_PIN_BYP                    (* (reg8 *) VERT_SYNC_OUT_PIN__BYP)
/* Port wide control signals */                                                   
#define VERT_SYNC_OUT_PIN_CTL                    (* (reg8 *) VERT_SYNC_OUT_PIN__CTL)
/* Drive Modes */
#define VERT_SYNC_OUT_PIN_DM0                    (* (reg8 *) VERT_SYNC_OUT_PIN__DM0) 
#define VERT_SYNC_OUT_PIN_DM1                    (* (reg8 *) VERT_SYNC_OUT_PIN__DM1)
#define VERT_SYNC_OUT_PIN_DM2                    (* (reg8 *) VERT_SYNC_OUT_PIN__DM2) 
/* Input Buffer Disable Override */
#define VERT_SYNC_OUT_PIN_INP_DIS                (* (reg8 *) VERT_SYNC_OUT_PIN__INP_DIS)
/* LCD Common or Segment Drive */
#define VERT_SYNC_OUT_PIN_LCD_COM_SEG            (* (reg8 *) VERT_SYNC_OUT_PIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define VERT_SYNC_OUT_PIN_LCD_EN                 (* (reg8 *) VERT_SYNC_OUT_PIN__LCD_EN)
/* Slew Rate Control */
#define VERT_SYNC_OUT_PIN_SLW                    (* (reg8 *) VERT_SYNC_OUT_PIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VERT_SYNC_OUT_PIN_PRTDSI__CAPS_SEL       (* (reg8 *) VERT_SYNC_OUT_PIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VERT_SYNC_OUT_PIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VERT_SYNC_OUT_PIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VERT_SYNC_OUT_PIN_PRTDSI__OE_SEL0        (* (reg8 *) VERT_SYNC_OUT_PIN__PRTDSI__OE_SEL0) 
#define VERT_SYNC_OUT_PIN_PRTDSI__OE_SEL1        (* (reg8 *) VERT_SYNC_OUT_PIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VERT_SYNC_OUT_PIN_PRTDSI__OUT_SEL0       (* (reg8 *) VERT_SYNC_OUT_PIN__PRTDSI__OUT_SEL0) 
#define VERT_SYNC_OUT_PIN_PRTDSI__OUT_SEL1       (* (reg8 *) VERT_SYNC_OUT_PIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VERT_SYNC_OUT_PIN_PRTDSI__SYNC_OUT       (* (reg8 *) VERT_SYNC_OUT_PIN__PRTDSI__SYNC_OUT) 


#if defined(VERT_SYNC_OUT_PIN__INTSTAT)  /* Interrupt Registers */

    #define VERT_SYNC_OUT_PIN_INTSTAT                (* (reg8 *) VERT_SYNC_OUT_PIN__INTSTAT)
    #define VERT_SYNC_OUT_PIN_SNAP                   (* (reg8 *) VERT_SYNC_OUT_PIN__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins VERT_SYNC_OUT_PIN_H */


/* [] END OF FILE */
