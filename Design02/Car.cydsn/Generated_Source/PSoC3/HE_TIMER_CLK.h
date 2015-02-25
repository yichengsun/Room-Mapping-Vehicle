/*******************************************************************************
* File Name: HE_TIMER_CLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_HE_TIMER_CLK_H)
#define CY_CLOCK_HE_TIMER_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void HE_TIMER_CLK_Start(void) ;
void HE_TIMER_CLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void HE_TIMER_CLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void HE_TIMER_CLK_StandbyPower(uint8 state) ;
void HE_TIMER_CLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 HE_TIMER_CLK_GetDividerRegister(void) ;
void HE_TIMER_CLK_SetModeRegister(uint8 modeBitMask) ;
void HE_TIMER_CLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 HE_TIMER_CLK_GetModeRegister(void) ;
void HE_TIMER_CLK_SetSourceRegister(uint8 clkSource) ;
uint8 HE_TIMER_CLK_GetSourceRegister(void) ;
#if defined(HE_TIMER_CLK__CFG3)
void HE_TIMER_CLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 HE_TIMER_CLK_GetPhaseRegister(void) ;
#endif /* defined(HE_TIMER_CLK__CFG3) */

#define HE_TIMER_CLK_Enable()                       HE_TIMER_CLK_Start()
#define HE_TIMER_CLK_Disable()                      HE_TIMER_CLK_Stop()
#define HE_TIMER_CLK_SetDivider(clkDivider)         HE_TIMER_CLK_SetDividerRegister(clkDivider, 1u)
#define HE_TIMER_CLK_SetDividerValue(clkDivider)    HE_TIMER_CLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define HE_TIMER_CLK_SetMode(clkMode)               HE_TIMER_CLK_SetModeRegister(clkMode)
#define HE_TIMER_CLK_SetSource(clkSource)           HE_TIMER_CLK_SetSourceRegister(clkSource)
#if defined(HE_TIMER_CLK__CFG3)
#define HE_TIMER_CLK_SetPhase(clkPhase)             HE_TIMER_CLK_SetPhaseRegister(clkPhase)
#define HE_TIMER_CLK_SetPhaseValue(clkPhase)        HE_TIMER_CLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(HE_TIMER_CLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define HE_TIMER_CLK_CLKEN              (* (reg8 *) HE_TIMER_CLK__PM_ACT_CFG)
#define HE_TIMER_CLK_CLKEN_PTR          ((reg8 *) HE_TIMER_CLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define HE_TIMER_CLK_CLKSTBY            (* (reg8 *) HE_TIMER_CLK__PM_STBY_CFG)
#define HE_TIMER_CLK_CLKSTBY_PTR        ((reg8 *) HE_TIMER_CLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define HE_TIMER_CLK_DIV_LSB            (* (reg8 *) HE_TIMER_CLK__CFG0)
#define HE_TIMER_CLK_DIV_LSB_PTR        ((reg8 *) HE_TIMER_CLK__CFG0)
#define HE_TIMER_CLK_DIV_PTR            ((reg16 *) HE_TIMER_CLK__CFG0)

/* Clock MSB divider configuration register. */
#define HE_TIMER_CLK_DIV_MSB            (* (reg8 *) HE_TIMER_CLK__CFG1)
#define HE_TIMER_CLK_DIV_MSB_PTR        ((reg8 *) HE_TIMER_CLK__CFG1)

/* Mode and source configuration register */
#define HE_TIMER_CLK_MOD_SRC            (* (reg8 *) HE_TIMER_CLK__CFG2)
#define HE_TIMER_CLK_MOD_SRC_PTR        ((reg8 *) HE_TIMER_CLK__CFG2)

#if defined(HE_TIMER_CLK__CFG3)
/* Analog clock phase configuration register */
#define HE_TIMER_CLK_PHASE              (* (reg8 *) HE_TIMER_CLK__CFG3)
#define HE_TIMER_CLK_PHASE_PTR          ((reg8 *) HE_TIMER_CLK__CFG3)
#endif /* defined(HE_TIMER_CLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define HE_TIMER_CLK_CLKEN_MASK         HE_TIMER_CLK__PM_ACT_MSK
#define HE_TIMER_CLK_CLKSTBY_MASK       HE_TIMER_CLK__PM_STBY_MSK

/* CFG2 field masks */
#define HE_TIMER_CLK_SRC_SEL_MSK        HE_TIMER_CLK__CFG2_SRC_SEL_MASK
#define HE_TIMER_CLK_MODE_MASK          (~(HE_TIMER_CLK_SRC_SEL_MSK))

#if defined(HE_TIMER_CLK__CFG3)
/* CFG3 phase mask */
#define HE_TIMER_CLK_PHASE_MASK         HE_TIMER_CLK__CFG3_PHASE_DLY_MASK
#endif /* defined(HE_TIMER_CLK__CFG3) */

#endif /* CY_CLOCK_HE_TIMER_CLK_H */


/* [] END OF FILE */
