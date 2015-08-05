/*******************************************************************************
* File Name: UPDATE_STEERING_TIMER.h
* Version 2.70
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_60_UPDATE_STEERING_TIMER_H)
#define CY_Timer_v2_60_UPDATE_STEERING_TIMER_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 UPDATE_STEERING_TIMER_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_70 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define UPDATE_STEERING_TIMER_Resolution                 8u
#define UPDATE_STEERING_TIMER_UsingFixedFunction         1u
#define UPDATE_STEERING_TIMER_UsingHWCaptureCounter      0u
#define UPDATE_STEERING_TIMER_SoftwareCaptureMode        0u
#define UPDATE_STEERING_TIMER_SoftwareTriggerMode        0u
#define UPDATE_STEERING_TIMER_UsingHWEnable              0u
#define UPDATE_STEERING_TIMER_EnableTriggerMode          0u
#define UPDATE_STEERING_TIMER_InterruptOnCaptureCount    0u
#define UPDATE_STEERING_TIMER_RunModeUsed                0u
#define UPDATE_STEERING_TIMER_ControlRegRemoved          0u

#if defined(UPDATE_STEERING_TIMER_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (UPDATE_STEERING_TIMER_UsingFixedFunction)
    #define UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End UPDATE_STEERING_TIMER_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!UPDATE_STEERING_TIMER_UsingFixedFunction)

        uint8 TimerUdb;
        uint8 InterruptMaskValue;
        #if (UPDATE_STEERING_TIMER_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}UPDATE_STEERING_TIMER_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    UPDATE_STEERING_TIMER_Start(void) ;
void    UPDATE_STEERING_TIMER_Stop(void) ;

void    UPDATE_STEERING_TIMER_SetInterruptMode(uint8 interruptMode) ;
uint8   UPDATE_STEERING_TIMER_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define UPDATE_STEERING_TIMER_GetInterruptSource() UPDATE_STEERING_TIMER_ReadStatusRegister()

#if(!UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED)
    uint8   UPDATE_STEERING_TIMER_ReadControlRegister(void) ;
    void    UPDATE_STEERING_TIMER_WriteControlRegister(uint8 control) ;
#endif /* (!UPDATE_STEERING_TIMER_UDB_CONTROL_REG_REMOVED) */

uint8  UPDATE_STEERING_TIMER_ReadPeriod(void) ;
void    UPDATE_STEERING_TIMER_WritePeriod(uint8 period) ;
uint8  UPDATE_STEERING_TIMER_ReadCounter(void) ;
void    UPDATE_STEERING_TIMER_WriteCounter(uint8 counter) ;
uint8  UPDATE_STEERING_TIMER_ReadCapture(void) ;
void    UPDATE_STEERING_TIMER_SoftwareCapture(void) ;

#if(!UPDATE_STEERING_TIMER_UsingFixedFunction) /* UDB Prototypes */
    #if (UPDATE_STEERING_TIMER_SoftwareCaptureMode)
        void    UPDATE_STEERING_TIMER_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!UPDATE_STEERING_TIMER_UsingFixedFunction) */

    #if (UPDATE_STEERING_TIMER_SoftwareTriggerMode)
        void    UPDATE_STEERING_TIMER_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (UPDATE_STEERING_TIMER_SoftwareTriggerMode) */

    #if (UPDATE_STEERING_TIMER_EnableTriggerMode)
        void    UPDATE_STEERING_TIMER_EnableTrigger(void) ;
        void    UPDATE_STEERING_TIMER_DisableTrigger(void) ;
    #endif /* (UPDATE_STEERING_TIMER_EnableTriggerMode) */


    #if(UPDATE_STEERING_TIMER_InterruptOnCaptureCount)
        void    UPDATE_STEERING_TIMER_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (UPDATE_STEERING_TIMER_InterruptOnCaptureCount) */

    #if (UPDATE_STEERING_TIMER_UsingHWCaptureCounter)
        void    UPDATE_STEERING_TIMER_SetCaptureCount(uint8 captureCount) ;
        uint8   UPDATE_STEERING_TIMER_ReadCaptureCount(void) ;
    #endif /* (UPDATE_STEERING_TIMER_UsingHWCaptureCounter) */

    void UPDATE_STEERING_TIMER_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void UPDATE_STEERING_TIMER_Init(void)          ;
void UPDATE_STEERING_TIMER_Enable(void)        ;
void UPDATE_STEERING_TIMER_SaveConfig(void)    ;
void UPDATE_STEERING_TIMER_RestoreConfig(void) ;
void UPDATE_STEERING_TIMER_Sleep(void)         ;
void UPDATE_STEERING_TIMER_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define UPDATE_STEERING_TIMER__B_TIMER__CM_NONE 0
#define UPDATE_STEERING_TIMER__B_TIMER__CM_RISINGEDGE 1
#define UPDATE_STEERING_TIMER__B_TIMER__CM_FALLINGEDGE 2
#define UPDATE_STEERING_TIMER__B_TIMER__CM_EITHEREDGE 3
#define UPDATE_STEERING_TIMER__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define UPDATE_STEERING_TIMER__B_TIMER__TM_NONE 0x00u
#define UPDATE_STEERING_TIMER__B_TIMER__TM_RISINGEDGE 0x04u
#define UPDATE_STEERING_TIMER__B_TIMER__TM_FALLINGEDGE 0x08u
#define UPDATE_STEERING_TIMER__B_TIMER__TM_EITHEREDGE 0x0Cu
#define UPDATE_STEERING_TIMER__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define UPDATE_STEERING_TIMER_INIT_PERIOD             255u
#define UPDATE_STEERING_TIMER_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << UPDATE_STEERING_TIMER_CTRL_CAP_MODE_SHIFT))
#define UPDATE_STEERING_TIMER_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << UPDATE_STEERING_TIMER_CTRL_TRIG_MODE_SHIFT))
#if (UPDATE_STEERING_TIMER_UsingFixedFunction)
    #define UPDATE_STEERING_TIMER_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << UPDATE_STEERING_TIMER_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << UPDATE_STEERING_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define UPDATE_STEERING_TIMER_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << UPDATE_STEERING_TIMER_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << UPDATE_STEERING_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << UPDATE_STEERING_TIMER_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (UPDATE_STEERING_TIMER_UsingFixedFunction) */
#define UPDATE_STEERING_TIMER_INIT_CAPTURE_COUNT      (2u)
#define UPDATE_STEERING_TIMER_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << UPDATE_STEERING_TIMER_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (UPDATE_STEERING_TIMER_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define UPDATE_STEERING_TIMER_STATUS         (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define UPDATE_STEERING_TIMER_STATUS_MASK    (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__SR0 )
    #define UPDATE_STEERING_TIMER_CONTROL        (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__CFG0)
    #define UPDATE_STEERING_TIMER_CONTROL2       (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__CFG1)
    #define UPDATE_STEERING_TIMER_CONTROL2_PTR   ( (reg8 *) UPDATE_STEERING_TIMER_TimerHW__CFG1)
    #define UPDATE_STEERING_TIMER_RT1            (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__RT1)
    #define UPDATE_STEERING_TIMER_RT1_PTR        ( (reg8 *) UPDATE_STEERING_TIMER_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define UPDATE_STEERING_TIMER_CONTROL3       (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__CFG2)
        #define UPDATE_STEERING_TIMER_CONTROL3_PTR   ( (reg8 *) UPDATE_STEERING_TIMER_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define UPDATE_STEERING_TIMER_GLOBAL_ENABLE  (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__PM_ACT_CFG)
    #define UPDATE_STEERING_TIMER_GLOBAL_STBY_ENABLE  (*(reg8 *) UPDATE_STEERING_TIMER_TimerHW__PM_STBY_CFG)

    #define UPDATE_STEERING_TIMER_CAPTURE_LSB         (* (reg16 *) UPDATE_STEERING_TIMER_TimerHW__CAP0 )
    #define UPDATE_STEERING_TIMER_CAPTURE_LSB_PTR       ((reg16 *) UPDATE_STEERING_TIMER_TimerHW__CAP0 )
    #define UPDATE_STEERING_TIMER_PERIOD_LSB          (* (reg16 *) UPDATE_STEERING_TIMER_TimerHW__PER0 )
    #define UPDATE_STEERING_TIMER_PERIOD_LSB_PTR        ((reg16 *) UPDATE_STEERING_TIMER_TimerHW__PER0 )
    #define UPDATE_STEERING_TIMER_COUNTER_LSB         (* (reg16 *) UPDATE_STEERING_TIMER_TimerHW__CNT_CMP0 )
    #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR       ((reg16 *) UPDATE_STEERING_TIMER_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define UPDATE_STEERING_TIMER_BLOCK_EN_MASK                     UPDATE_STEERING_TIMER_TimerHW__PM_ACT_MSK
    #define UPDATE_STEERING_TIMER_BLOCK_STBY_EN_MASK                UPDATE_STEERING_TIMER_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define UPDATE_STEERING_TIMER_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define UPDATE_STEERING_TIMER_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define UPDATE_STEERING_TIMER_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define UPDATE_STEERING_TIMER_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define UPDATE_STEERING_TIMER_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define UPDATE_STEERING_TIMER_CTRL_ENABLE                        ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define UPDATE_STEERING_TIMER_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define UPDATE_STEERING_TIMER_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define UPDATE_STEERING_TIMER_CTRL_MODE_SHIFT                 0x01u
        #define UPDATE_STEERING_TIMER_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << UPDATE_STEERING_TIMER_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define UPDATE_STEERING_TIMER_CTRL_RCOD_SHIFT        0x02u
        #define UPDATE_STEERING_TIMER_CTRL_ENBL_SHIFT        0x00u
        #define UPDATE_STEERING_TIMER_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define UPDATE_STEERING_TIMER_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define UPDATE_STEERING_TIMER_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << UPDATE_STEERING_TIMER_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define UPDATE_STEERING_TIMER_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define UPDATE_STEERING_TIMER_CTRL_RCOD       ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_CTRL_RCOD_SHIFT))
        #define UPDATE_STEERING_TIMER_CTRL_ENBL       ((uint8)((uint8)0x80u << UPDATE_STEERING_TIMER_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define UPDATE_STEERING_TIMER_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define UPDATE_STEERING_TIMER_RT1_MASK                        ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_RT1_SHIFT))
    #define UPDATE_STEERING_TIMER_SYNC                            ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_RT1_SHIFT))
    #define UPDATE_STEERING_TIMER_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define UPDATE_STEERING_TIMER_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << UPDATE_STEERING_TIMER_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define UPDATE_STEERING_TIMER_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << UPDATE_STEERING_TIMER_SYNCDSI_SHIFT))

    #define UPDATE_STEERING_TIMER_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_CTRL_MODE_SHIFT))
    #define UPDATE_STEERING_TIMER_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << UPDATE_STEERING_TIMER_CTRL_MODE_SHIFT))
    #define UPDATE_STEERING_TIMER_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << UPDATE_STEERING_TIMER_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define UPDATE_STEERING_TIMER_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define UPDATE_STEERING_TIMER_STATUS_TC_INT_MASK_SHIFT        (UPDATE_STEERING_TIMER_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT   (UPDATE_STEERING_TIMER_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define UPDATE_STEERING_TIMER_STATUS_TC                       ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_TC_SHIFT))
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define UPDATE_STEERING_TIMER_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define UPDATE_STEERING_TIMER_STATUS              (* (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define UPDATE_STEERING_TIMER_STATUS_MASK         (* (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_rstSts_stsreg__MASK_REG)
    #define UPDATE_STEERING_TIMER_STATUS_AUX_CTRL     (* (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define UPDATE_STEERING_TIMER_CONTROL             (* (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(UPDATE_STEERING_TIMER_Resolution <= 8u) /* 8-bit Timer */
        #define UPDATE_STEERING_TIMER_CAPTURE_LSB         (* (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define UPDATE_STEERING_TIMER_CAPTURE_LSB_PTR       ((reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define UPDATE_STEERING_TIMER_PERIOD_LSB          (* (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define UPDATE_STEERING_TIMER_PERIOD_LSB_PTR        ((reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define UPDATE_STEERING_TIMER_COUNTER_LSB         (* (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR       ((reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(UPDATE_STEERING_TIMER_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB         (* (reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB_PTR       ((reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB          (* (reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB_PTR        ((reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB         (* (reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR       ((reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB         (* (reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB_PTR       ((reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB          (* (reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB_PTR        ((reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB         (* (reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR       ((reg16 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(UPDATE_STEERING_TIMER_Resolution <= 24u)/* 24-bit Timer */
        #define UPDATE_STEERING_TIMER_CAPTURE_LSB         (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define UPDATE_STEERING_TIMER_CAPTURE_LSB_PTR       ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define UPDATE_STEERING_TIMER_PERIOD_LSB          (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define UPDATE_STEERING_TIMER_PERIOD_LSB_PTR        ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define UPDATE_STEERING_TIMER_COUNTER_LSB         (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR       ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB         (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB_PTR       ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB          (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB_PTR        ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB         (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR       ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB         (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define UPDATE_STEERING_TIMER_CAPTURE_LSB_PTR       ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB          (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define UPDATE_STEERING_TIMER_PERIOD_LSB_PTR        ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB         (* (reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR       ((reg32 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define UPDATE_STEERING_TIMER_COUNTER_LSB_PTR_8BIT       ((reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sT8_timerdp_u0__A0_REG )
    
    #if (UPDATE_STEERING_TIMER_UsingHWCaptureCounter)
        #define UPDATE_STEERING_TIMER_CAP_COUNT              (*(reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define UPDATE_STEERING_TIMER_CAP_COUNT_PTR          ( (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define UPDATE_STEERING_TIMER_CAPTURE_COUNT_CTRL     (*(reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define UPDATE_STEERING_TIMER_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) UPDATE_STEERING_TIMER_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (UPDATE_STEERING_TIMER_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define UPDATE_STEERING_TIMER_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define UPDATE_STEERING_TIMER_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_CTRL_INTCNT_SHIFT))
    #define UPDATE_STEERING_TIMER_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_CTRL_TRIG_MODE_SHIFT))
    #define UPDATE_STEERING_TIMER_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_CTRL_TRIG_EN_SHIFT))
    #define UPDATE_STEERING_TIMER_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << UPDATE_STEERING_TIMER_CTRL_CAP_MODE_SHIFT))
    #define UPDATE_STEERING_TIMER_CTRL_ENABLE                    ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define UPDATE_STEERING_TIMER_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define UPDATE_STEERING_TIMER_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_STATUS_TC_INT_MASK_SHIFT       UPDATE_STEERING_TIMER_STATUS_TC_SHIFT
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT  UPDATE_STEERING_TIMER_STATUS_CAPTURE_SHIFT
    #define UPDATE_STEERING_TIMER_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define UPDATE_STEERING_TIMER_STATUS_FIFOFULL_INT_MASK_SHIFT UPDATE_STEERING_TIMER_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define UPDATE_STEERING_TIMER_STATUS_TC                      ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define UPDATE_STEERING_TIMER_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define UPDATE_STEERING_TIMER_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define UPDATE_STEERING_TIMER_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define UPDATE_STEERING_TIMER_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define UPDATE_STEERING_TIMER_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << UPDATE_STEERING_TIMER_STATUS_FIFOFULL_SHIFT))

    #define UPDATE_STEERING_TIMER_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define UPDATE_STEERING_TIMER_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define UPDATE_STEERING_TIMER_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define UPDATE_STEERING_TIMER_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define UPDATE_STEERING_TIMER_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define UPDATE_STEERING_TIMER_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_UPDATE_STEERING_TIMER_H */


/* [] END OF FILE */
