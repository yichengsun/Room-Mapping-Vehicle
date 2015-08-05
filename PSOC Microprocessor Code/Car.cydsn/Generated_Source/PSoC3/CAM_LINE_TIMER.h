/*******************************************************************************
* File Name: CAM_LINE_TIMER.h
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

#if !defined(CY_Timer_v2_60_CAM_LINE_TIMER_H)
#define CY_Timer_v2_60_CAM_LINE_TIMER_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 CAM_LINE_TIMER_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_70 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define CAM_LINE_TIMER_Resolution                 16u
#define CAM_LINE_TIMER_UsingFixedFunction         0u
#define CAM_LINE_TIMER_UsingHWCaptureCounter      0u
#define CAM_LINE_TIMER_SoftwareCaptureMode        0u
#define CAM_LINE_TIMER_SoftwareTriggerMode        0u
#define CAM_LINE_TIMER_UsingHWEnable              0u
#define CAM_LINE_TIMER_EnableTriggerMode          0u
#define CAM_LINE_TIMER_InterruptOnCaptureCount    1u
#define CAM_LINE_TIMER_RunModeUsed                0u
#define CAM_LINE_TIMER_ControlRegRemoved          0u

#if defined(CAM_LINE_TIMER_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG)
    #define CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED            (0u)
#elif  (CAM_LINE_TIMER_UsingFixedFunction)
    #define CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED            (0u)
#else 
    #define CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED            (1u)
#endif /* End CAM_LINE_TIMER_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG */


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!CAM_LINE_TIMER_UsingFixedFunction)

        uint16 TimerUdb;
        uint8 InterruptMaskValue;
        #if (CAM_LINE_TIMER_UsingHWCaptureCounter)
            uint8 TimerCaptureCounter;
        #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */

        #if (!CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */

}CAM_LINE_TIMER_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    CAM_LINE_TIMER_Start(void) ;
void    CAM_LINE_TIMER_Stop(void) ;

void    CAM_LINE_TIMER_SetInterruptMode(uint8 interruptMode) ;
uint8   CAM_LINE_TIMER_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define CAM_LINE_TIMER_GetInterruptSource() CAM_LINE_TIMER_ReadStatusRegister()

#if(!CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED)
    uint8   CAM_LINE_TIMER_ReadControlRegister(void) ;
    void    CAM_LINE_TIMER_WriteControlRegister(uint8 control) ;
#endif /* (!CAM_LINE_TIMER_UDB_CONTROL_REG_REMOVED) */

uint16  CAM_LINE_TIMER_ReadPeriod(void) ;
void    CAM_LINE_TIMER_WritePeriod(uint16 period) ;
uint16  CAM_LINE_TIMER_ReadCounter(void) ;
void    CAM_LINE_TIMER_WriteCounter(uint16 counter) ;
uint16  CAM_LINE_TIMER_ReadCapture(void) ;
void    CAM_LINE_TIMER_SoftwareCapture(void) ;

#if(!CAM_LINE_TIMER_UsingFixedFunction) /* UDB Prototypes */
    #if (CAM_LINE_TIMER_SoftwareCaptureMode)
        void    CAM_LINE_TIMER_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!CAM_LINE_TIMER_UsingFixedFunction) */

    #if (CAM_LINE_TIMER_SoftwareTriggerMode)
        void    CAM_LINE_TIMER_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (CAM_LINE_TIMER_SoftwareTriggerMode) */

    #if (CAM_LINE_TIMER_EnableTriggerMode)
        void    CAM_LINE_TIMER_EnableTrigger(void) ;
        void    CAM_LINE_TIMER_DisableTrigger(void) ;
    #endif /* (CAM_LINE_TIMER_EnableTriggerMode) */


    #if(CAM_LINE_TIMER_InterruptOnCaptureCount)
        void    CAM_LINE_TIMER_SetInterruptCount(uint8 interruptCount) ;
    #endif /* (CAM_LINE_TIMER_InterruptOnCaptureCount) */

    #if (CAM_LINE_TIMER_UsingHWCaptureCounter)
        void    CAM_LINE_TIMER_SetCaptureCount(uint8 captureCount) ;
        uint8   CAM_LINE_TIMER_ReadCaptureCount(void) ;
    #endif /* (CAM_LINE_TIMER_UsingHWCaptureCounter) */

    void CAM_LINE_TIMER_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void CAM_LINE_TIMER_Init(void)          ;
void CAM_LINE_TIMER_Enable(void)        ;
void CAM_LINE_TIMER_SaveConfig(void)    ;
void CAM_LINE_TIMER_RestoreConfig(void) ;
void CAM_LINE_TIMER_Sleep(void)         ;
void CAM_LINE_TIMER_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define CAM_LINE_TIMER__B_TIMER__CM_NONE 0
#define CAM_LINE_TIMER__B_TIMER__CM_RISINGEDGE 1
#define CAM_LINE_TIMER__B_TIMER__CM_FALLINGEDGE 2
#define CAM_LINE_TIMER__B_TIMER__CM_EITHEREDGE 3
#define CAM_LINE_TIMER__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define CAM_LINE_TIMER__B_TIMER__TM_NONE 0x00u
#define CAM_LINE_TIMER__B_TIMER__TM_RISINGEDGE 0x04u
#define CAM_LINE_TIMER__B_TIMER__TM_FALLINGEDGE 0x08u
#define CAM_LINE_TIMER__B_TIMER__TM_EITHEREDGE 0x0Cu
#define CAM_LINE_TIMER__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define CAM_LINE_TIMER_INIT_PERIOD             65535u
#define CAM_LINE_TIMER_INIT_CAPTURE_MODE       ((uint8)((uint8)3u << CAM_LINE_TIMER_CTRL_CAP_MODE_SHIFT))
#define CAM_LINE_TIMER_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << CAM_LINE_TIMER_CTRL_TRIG_MODE_SHIFT))
#if (CAM_LINE_TIMER_UsingFixedFunction)
    #define CAM_LINE_TIMER_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << CAM_LINE_TIMER_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)1 << CAM_LINE_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define CAM_LINE_TIMER_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << CAM_LINE_TIMER_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)1 << CAM_LINE_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << CAM_LINE_TIMER_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (CAM_LINE_TIMER_UsingFixedFunction) */
#define CAM_LINE_TIMER_INIT_CAPTURE_COUNT      (2u)
#define CAM_LINE_TIMER_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(4u - 1u) << CAM_LINE_TIMER_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (CAM_LINE_TIMER_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define CAM_LINE_TIMER_STATUS         (*(reg8 *) CAM_LINE_TIMER_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define CAM_LINE_TIMER_STATUS_MASK    (*(reg8 *) CAM_LINE_TIMER_TimerHW__SR0 )
    #define CAM_LINE_TIMER_CONTROL        (*(reg8 *) CAM_LINE_TIMER_TimerHW__CFG0)
    #define CAM_LINE_TIMER_CONTROL2       (*(reg8 *) CAM_LINE_TIMER_TimerHW__CFG1)
    #define CAM_LINE_TIMER_CONTROL2_PTR   ( (reg8 *) CAM_LINE_TIMER_TimerHW__CFG1)
    #define CAM_LINE_TIMER_RT1            (*(reg8 *) CAM_LINE_TIMER_TimerHW__RT1)
    #define CAM_LINE_TIMER_RT1_PTR        ( (reg8 *) CAM_LINE_TIMER_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define CAM_LINE_TIMER_CONTROL3       (*(reg8 *) CAM_LINE_TIMER_TimerHW__CFG2)
        #define CAM_LINE_TIMER_CONTROL3_PTR   ( (reg8 *) CAM_LINE_TIMER_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define CAM_LINE_TIMER_GLOBAL_ENABLE  (*(reg8 *) CAM_LINE_TIMER_TimerHW__PM_ACT_CFG)
    #define CAM_LINE_TIMER_GLOBAL_STBY_ENABLE  (*(reg8 *) CAM_LINE_TIMER_TimerHW__PM_STBY_CFG)

    #define CAM_LINE_TIMER_CAPTURE_LSB         (* (reg16 *) CAM_LINE_TIMER_TimerHW__CAP0 )
    #define CAM_LINE_TIMER_CAPTURE_LSB_PTR       ((reg16 *) CAM_LINE_TIMER_TimerHW__CAP0 )
    #define CAM_LINE_TIMER_PERIOD_LSB          (* (reg16 *) CAM_LINE_TIMER_TimerHW__PER0 )
    #define CAM_LINE_TIMER_PERIOD_LSB_PTR        ((reg16 *) CAM_LINE_TIMER_TimerHW__PER0 )
    #define CAM_LINE_TIMER_COUNTER_LSB         (* (reg16 *) CAM_LINE_TIMER_TimerHW__CNT_CMP0 )
    #define CAM_LINE_TIMER_COUNTER_LSB_PTR       ((reg16 *) CAM_LINE_TIMER_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define CAM_LINE_TIMER_BLOCK_EN_MASK                     CAM_LINE_TIMER_TimerHW__PM_ACT_MSK
    #define CAM_LINE_TIMER_BLOCK_STBY_EN_MASK                CAM_LINE_TIMER_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define CAM_LINE_TIMER_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define CAM_LINE_TIMER_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define CAM_LINE_TIMER_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define CAM_LINE_TIMER_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define CAM_LINE_TIMER_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define CAM_LINE_TIMER_CTRL_ENABLE                        ((uint8)((uint8)0x01u << CAM_LINE_TIMER_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define CAM_LINE_TIMER_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define CAM_LINE_TIMER_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << CAM_LINE_TIMER_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define CAM_LINE_TIMER_CTRL_MODE_SHIFT                 0x01u
        #define CAM_LINE_TIMER_CTRL_MODE_MASK                 ((uint8)((uint8)0x07u << CAM_LINE_TIMER_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define CAM_LINE_TIMER_CTRL_RCOD_SHIFT        0x02u
        #define CAM_LINE_TIMER_CTRL_ENBL_SHIFT        0x00u
        #define CAM_LINE_TIMER_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define CAM_LINE_TIMER_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << CAM_LINE_TIMER_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define CAM_LINE_TIMER_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << CAM_LINE_TIMER_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define CAM_LINE_TIMER_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << CAM_LINE_TIMER_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define CAM_LINE_TIMER_CTRL_RCOD       ((uint8)((uint8)0x03u << CAM_LINE_TIMER_CTRL_RCOD_SHIFT))
        #define CAM_LINE_TIMER_CTRL_ENBL       ((uint8)((uint8)0x80u << CAM_LINE_TIMER_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define CAM_LINE_TIMER_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define CAM_LINE_TIMER_RT1_MASK                        ((uint8)((uint8)0x03u << CAM_LINE_TIMER_RT1_SHIFT))
    #define CAM_LINE_TIMER_SYNC                            ((uint8)((uint8)0x03u << CAM_LINE_TIMER_RT1_SHIFT))
    #define CAM_LINE_TIMER_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define CAM_LINE_TIMER_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << CAM_LINE_TIMER_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define CAM_LINE_TIMER_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << CAM_LINE_TIMER_SYNCDSI_SHIFT))

    #define CAM_LINE_TIMER_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << CAM_LINE_TIMER_CTRL_MODE_SHIFT))
    #define CAM_LINE_TIMER_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << CAM_LINE_TIMER_CTRL_MODE_SHIFT))
    #define CAM_LINE_TIMER_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << CAM_LINE_TIMER_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define CAM_LINE_TIMER_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define CAM_LINE_TIMER_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define CAM_LINE_TIMER_STATUS_TC_INT_MASK_SHIFT        (CAM_LINE_TIMER_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define CAM_LINE_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT   (CAM_LINE_TIMER_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define CAM_LINE_TIMER_STATUS_TC                       ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_TC_SHIFT))
    #define CAM_LINE_TIMER_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define CAM_LINE_TIMER_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define CAM_LINE_TIMER_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define CAM_LINE_TIMER_STATUS              (* (reg8 *) CAM_LINE_TIMER_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define CAM_LINE_TIMER_STATUS_MASK         (* (reg8 *) CAM_LINE_TIMER_TimerUDB_rstSts_stsreg__MASK_REG)
    #define CAM_LINE_TIMER_STATUS_AUX_CTRL     (* (reg8 *) CAM_LINE_TIMER_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define CAM_LINE_TIMER_CONTROL             (* (reg8 *) CAM_LINE_TIMER_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(CAM_LINE_TIMER_Resolution <= 8u) /* 8-bit Timer */
        #define CAM_LINE_TIMER_CAPTURE_LSB         (* (reg8 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define CAM_LINE_TIMER_CAPTURE_LSB_PTR       ((reg8 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define CAM_LINE_TIMER_PERIOD_LSB          (* (reg8 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define CAM_LINE_TIMER_PERIOD_LSB_PTR        ((reg8 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define CAM_LINE_TIMER_COUNTER_LSB         (* (reg8 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define CAM_LINE_TIMER_COUNTER_LSB_PTR       ((reg8 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(CAM_LINE_TIMER_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define CAM_LINE_TIMER_CAPTURE_LSB         (* (reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define CAM_LINE_TIMER_CAPTURE_LSB_PTR       ((reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB          (* (reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB_PTR        ((reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB         (* (reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB_PTR       ((reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define CAM_LINE_TIMER_CAPTURE_LSB         (* (reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define CAM_LINE_TIMER_CAPTURE_LSB_PTR       ((reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB          (* (reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB_PTR        ((reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB         (* (reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB_PTR       ((reg16 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(CAM_LINE_TIMER_Resolution <= 24u)/* 24-bit Timer */
        #define CAM_LINE_TIMER_CAPTURE_LSB         (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define CAM_LINE_TIMER_CAPTURE_LSB_PTR       ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define CAM_LINE_TIMER_PERIOD_LSB          (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define CAM_LINE_TIMER_PERIOD_LSB_PTR        ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define CAM_LINE_TIMER_COUNTER_LSB         (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define CAM_LINE_TIMER_COUNTER_LSB_PTR       ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define CAM_LINE_TIMER_CAPTURE_LSB         (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define CAM_LINE_TIMER_CAPTURE_LSB_PTR       ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB          (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB_PTR        ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB         (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB_PTR       ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define CAM_LINE_TIMER_CAPTURE_LSB         (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define CAM_LINE_TIMER_CAPTURE_LSB_PTR       ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB          (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define CAM_LINE_TIMER_PERIOD_LSB_PTR        ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB         (* (reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define CAM_LINE_TIMER_COUNTER_LSB_PTR       ((reg32 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #define CAM_LINE_TIMER_COUNTER_LSB_PTR_8BIT       ((reg8 *) CAM_LINE_TIMER_TimerUDB_sT16_timerdp_u0__A0_REG )
    
    #if (CAM_LINE_TIMER_UsingHWCaptureCounter)
        #define CAM_LINE_TIMER_CAP_COUNT              (*(reg8 *) CAM_LINE_TIMER_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define CAM_LINE_TIMER_CAP_COUNT_PTR          ( (reg8 *) CAM_LINE_TIMER_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define CAM_LINE_TIMER_CAPTURE_COUNT_CTRL     (*(reg8 *) CAM_LINE_TIMER_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define CAM_LINE_TIMER_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) CAM_LINE_TIMER_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (CAM_LINE_TIMER_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define CAM_LINE_TIMER_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define CAM_LINE_TIMER_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << CAM_LINE_TIMER_CTRL_INTCNT_SHIFT))
    #define CAM_LINE_TIMER_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << CAM_LINE_TIMER_CTRL_TRIG_MODE_SHIFT))
    #define CAM_LINE_TIMER_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << CAM_LINE_TIMER_CTRL_TRIG_EN_SHIFT))
    #define CAM_LINE_TIMER_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << CAM_LINE_TIMER_CTRL_CAP_MODE_SHIFT))
    #define CAM_LINE_TIMER_CTRL_ENABLE                    ((uint8)((uint8)0x01u << CAM_LINE_TIMER_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define CAM_LINE_TIMER_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define CAM_LINE_TIMER_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_STATUS_TC_INT_MASK_SHIFT       CAM_LINE_TIMER_STATUS_TC_SHIFT
    #define CAM_LINE_TIMER_STATUS_CAPTURE_INT_MASK_SHIFT  CAM_LINE_TIMER_STATUS_CAPTURE_SHIFT
    #define CAM_LINE_TIMER_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define CAM_LINE_TIMER_STATUS_FIFOFULL_INT_MASK_SHIFT CAM_LINE_TIMER_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define CAM_LINE_TIMER_STATUS_TC                      ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define CAM_LINE_TIMER_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define CAM_LINE_TIMER_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define CAM_LINE_TIMER_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define CAM_LINE_TIMER_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define CAM_LINE_TIMER_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define CAM_LINE_TIMER_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << CAM_LINE_TIMER_STATUS_FIFOFULL_SHIFT))

    #define CAM_LINE_TIMER_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define CAM_LINE_TIMER_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define CAM_LINE_TIMER_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define CAM_LINE_TIMER_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define CAM_LINE_TIMER_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define CAM_LINE_TIMER_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_CAM_LINE_TIMER_H */


/* [] END OF FILE */
