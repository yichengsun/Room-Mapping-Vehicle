/*******************************************************************************
* File Name: CAM_ADC_AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_CAM_ADC_AMux_H)
#define CY_AMUX_CAM_ADC_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void CAM_ADC_AMux_Start(void) ;
#define CAM_ADC_AMux_Init() CAM_ADC_AMux_Start()
void CAM_ADC_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void CAM_ADC_AMux_Stop(void); */
/* void CAM_ADC_AMux_Select(uint8 channel); */
/* void CAM_ADC_AMux_Connect(uint8 channel); */
/* void CAM_ADC_AMux_Disconnect(uint8 channel); */
/* void CAM_ADC_AMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define CAM_ADC_AMux_CHANNELS  2u
#define CAM_ADC_AMux_MUXTYPE   1
#define CAM_ADC_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define CAM_ADC_AMux_NULL_CHANNEL 0xFFu
#define CAM_ADC_AMux_MUX_SINGLE   1
#define CAM_ADC_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if CAM_ADC_AMux_MUXTYPE == CAM_ADC_AMux_MUX_SINGLE
# if !CAM_ADC_AMux_ATMOSTONE
#  define CAM_ADC_AMux_Connect(channel) CAM_ADC_AMux_Set(channel)
# endif
# define CAM_ADC_AMux_Disconnect(channel) CAM_ADC_AMux_Unset(channel)
#else
# if !CAM_ADC_AMux_ATMOSTONE
void CAM_ADC_AMux_Connect(uint8 channel) ;
# endif
void CAM_ADC_AMux_Disconnect(uint8 channel) ;
#endif

#if CAM_ADC_AMux_ATMOSTONE
# define CAM_ADC_AMux_Stop() CAM_ADC_AMux_DisconnectAll()
# define CAM_ADC_AMux_Select(channel) CAM_ADC_AMux_FastSelect(channel)
void CAM_ADC_AMux_DisconnectAll(void) ;
#else
# define CAM_ADC_AMux_Stop() CAM_ADC_AMux_Start()
void CAM_ADC_AMux_Select(uint8 channel) ;
# define CAM_ADC_AMux_DisconnectAll() CAM_ADC_AMux_Start()
#endif

#endif /* CY_AMUX_CAM_ADC_AMux_H */


/* [] END OF FILE */
