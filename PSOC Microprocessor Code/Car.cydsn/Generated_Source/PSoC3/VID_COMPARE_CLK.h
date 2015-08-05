/*******************************************************************************
* File Name: VID_COMPARE_CLK.h
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

#if !defined(CY_CLOCK_VID_COMPARE_CLK_H)
#define CY_CLOCK_VID_COMPARE_CLK_H

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

void VID_COMPARE_CLK_Start(void) ;
void VID_COMPARE_CLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void VID_COMPARE_CLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void VID_COMPARE_CLK_StandbyPower(uint8 state) ;
void VID_COMPARE_CLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 VID_COMPARE_CLK_GetDividerRegister(void) ;
void VID_COMPARE_CLK_SetModeRegister(uint8 modeBitMask) ;
void VID_COMPARE_CLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 VID_COMPARE_CLK_GetModeRegister(void) ;
void VID_COMPARE_CLK_SetSourceRegister(uint8 clkSource) ;
uint8 VID_COMPARE_CLK_GetSourceRegister(void) ;
#if defined(VID_COMPARE_CLK__CFG3)
void VID_COMPARE_CLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 VID_COMPARE_CLK_GetPhaseRegister(void) ;
#endif /* defined(VID_COMPARE_CLK__CFG3) */

#define VID_COMPARE_CLK_Enable()                       VID_COMPARE_CLK_Start()
#define VID_COMPARE_CLK_Disable()                      VID_COMPARE_CLK_Stop()
#define VID_COMPARE_CLK_SetDivider(clkDivider)         VID_COMPARE_CLK_SetDividerRegister(clkDivider, 1u)
#define VID_COMPARE_CLK_SetDividerValue(clkDivider)    VID_COMPARE_CLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define VID_COMPARE_CLK_SetMode(clkMode)               VID_COMPARE_CLK_SetModeRegister(clkMode)
#define VID_COMPARE_CLK_SetSource(clkSource)           VID_COMPARE_CLK_SetSourceRegister(clkSource)
#if defined(VID_COMPARE_CLK__CFG3)
#define VID_COMPARE_CLK_SetPhase(clkPhase)             VID_COMPARE_CLK_SetPhaseRegister(clkPhase)
#define VID_COMPARE_CLK_SetPhaseValue(clkPhase)        VID_COMPARE_CLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(VID_COMPARE_CLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define VID_COMPARE_CLK_CLKEN              (* (reg8 *) VID_COMPARE_CLK__PM_ACT_CFG)
#define VID_COMPARE_CLK_CLKEN_PTR          ((reg8 *) VID_COMPARE_CLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define VID_COMPARE_CLK_CLKSTBY            (* (reg8 *) VID_COMPARE_CLK__PM_STBY_CFG)
#define VID_COMPARE_CLK_CLKSTBY_PTR        ((reg8 *) VID_COMPARE_CLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define VID_COMPARE_CLK_DIV_LSB            (* (reg8 *) VID_COMPARE_CLK__CFG0)
#define VID_COMPARE_CLK_DIV_LSB_PTR        ((reg8 *) VID_COMPARE_CLK__CFG0)
#define VID_COMPARE_CLK_DIV_PTR            ((reg16 *) VID_COMPARE_CLK__CFG0)

/* Clock MSB divider configuration register. */
#define VID_COMPARE_CLK_DIV_MSB            (* (reg8 *) VID_COMPARE_CLK__CFG1)
#define VID_COMPARE_CLK_DIV_MSB_PTR        ((reg8 *) VID_COMPARE_CLK__CFG1)

/* Mode and source configuration register */
#define VID_COMPARE_CLK_MOD_SRC            (* (reg8 *) VID_COMPARE_CLK__CFG2)
#define VID_COMPARE_CLK_MOD_SRC_PTR        ((reg8 *) VID_COMPARE_CLK__CFG2)

#if defined(VID_COMPARE_CLK__CFG3)
/* Analog clock phase configuration register */
#define VID_COMPARE_CLK_PHASE              (* (reg8 *) VID_COMPARE_CLK__CFG3)
#define VID_COMPARE_CLK_PHASE_PTR          ((reg8 *) VID_COMPARE_CLK__CFG3)
#endif /* defined(VID_COMPARE_CLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define VID_COMPARE_CLK_CLKEN_MASK         VID_COMPARE_CLK__PM_ACT_MSK
#define VID_COMPARE_CLK_CLKSTBY_MASK       VID_COMPARE_CLK__PM_STBY_MSK

/* CFG2 field masks */
#define VID_COMPARE_CLK_SRC_SEL_MSK        VID_COMPARE_CLK__CFG2_SRC_SEL_MASK
#define VID_COMPARE_CLK_MODE_MASK          (~(VID_COMPARE_CLK_SRC_SEL_MSK))

#if defined(VID_COMPARE_CLK__CFG3)
/* CFG3 phase mask */
#define VID_COMPARE_CLK_PHASE_MASK         VID_COMPARE_CLK__CFG3_PHASE_DLY_MASK
#endif /* defined(VID_COMPARE_CLK__CFG3) */

#endif /* CY_CLOCK_VID_COMPARE_CLK_H */


/* [] END OF FILE */
