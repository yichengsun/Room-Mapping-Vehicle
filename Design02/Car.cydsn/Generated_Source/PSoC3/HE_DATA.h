/*******************************************************************************
* File Name: HE_DATA.h  
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

#if !defined(CY_PINS_HE_DATA_H) /* Pins HE_DATA_H */
#define CY_PINS_HE_DATA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "HE_DATA_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    HE_DATA_Write(uint8 value) ;
void    HE_DATA_SetDriveMode(uint8 mode) ;
uint8   HE_DATA_ReadDataReg(void) ;
uint8   HE_DATA_Read(void) ;
uint8   HE_DATA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HE_DATA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define HE_DATA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define HE_DATA_DM_RES_UP          PIN_DM_RES_UP
#define HE_DATA_DM_RES_DWN         PIN_DM_RES_DWN
#define HE_DATA_DM_OD_LO           PIN_DM_OD_LO
#define HE_DATA_DM_OD_HI           PIN_DM_OD_HI
#define HE_DATA_DM_STRONG          PIN_DM_STRONG
#define HE_DATA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define HE_DATA_MASK               HE_DATA__MASK
#define HE_DATA_SHIFT              HE_DATA__SHIFT
#define HE_DATA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HE_DATA_PS                     (* (reg8 *) HE_DATA__PS)
/* Data Register */
#define HE_DATA_DR                     (* (reg8 *) HE_DATA__DR)
/* Port Number */
#define HE_DATA_PRT_NUM                (* (reg8 *) HE_DATA__PRT) 
/* Connect to Analog Globals */                                                  
#define HE_DATA_AG                     (* (reg8 *) HE_DATA__AG)                       
/* Analog MUX bux enable */
#define HE_DATA_AMUX                   (* (reg8 *) HE_DATA__AMUX) 
/* Bidirectional Enable */                                                        
#define HE_DATA_BIE                    (* (reg8 *) HE_DATA__BIE)
/* Bit-mask for Aliased Register Access */
#define HE_DATA_BIT_MASK               (* (reg8 *) HE_DATA__BIT_MASK)
/* Bypass Enable */
#define HE_DATA_BYP                    (* (reg8 *) HE_DATA__BYP)
/* Port wide control signals */                                                   
#define HE_DATA_CTL                    (* (reg8 *) HE_DATA__CTL)
/* Drive Modes */
#define HE_DATA_DM0                    (* (reg8 *) HE_DATA__DM0) 
#define HE_DATA_DM1                    (* (reg8 *) HE_DATA__DM1)
#define HE_DATA_DM2                    (* (reg8 *) HE_DATA__DM2) 
/* Input Buffer Disable Override */
#define HE_DATA_INP_DIS                (* (reg8 *) HE_DATA__INP_DIS)
/* LCD Common or Segment Drive */
#define HE_DATA_LCD_COM_SEG            (* (reg8 *) HE_DATA__LCD_COM_SEG)
/* Enable Segment LCD */
#define HE_DATA_LCD_EN                 (* (reg8 *) HE_DATA__LCD_EN)
/* Slew Rate Control */
#define HE_DATA_SLW                    (* (reg8 *) HE_DATA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define HE_DATA_PRTDSI__CAPS_SEL       (* (reg8 *) HE_DATA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define HE_DATA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) HE_DATA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define HE_DATA_PRTDSI__OE_SEL0        (* (reg8 *) HE_DATA__PRTDSI__OE_SEL0) 
#define HE_DATA_PRTDSI__OE_SEL1        (* (reg8 *) HE_DATA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define HE_DATA_PRTDSI__OUT_SEL0       (* (reg8 *) HE_DATA__PRTDSI__OUT_SEL0) 
#define HE_DATA_PRTDSI__OUT_SEL1       (* (reg8 *) HE_DATA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define HE_DATA_PRTDSI__SYNC_OUT       (* (reg8 *) HE_DATA__PRTDSI__SYNC_OUT) 


#if defined(HE_DATA__INTSTAT)  /* Interrupt Registers */

    #define HE_DATA_INTSTAT                (* (reg8 *) HE_DATA__INTSTAT)
    #define HE_DATA_SNAP                   (* (reg8 *) HE_DATA__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins HE_DATA_H */


/* [] END OF FILE */
