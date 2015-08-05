/*******************************************************************************
* File Name: PSoC3_8051.h
* Version 4.20
*
*  Description:
*   8051 register definitions for the PSoC3 family of parts.
*
*  Note:
*
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_BOOT_PSoC3_8051_H)
#define CY_BOOT_PSoC3_8051_H

#include "cyfitter.h"

sfr SFRPRT0DR       = 0x80u;

sfr SP              = 0x81u;
sfr DPL             = 0x82u;
sfr DPH             = 0x83u;
sfr DPL1            = 0x84u;
sfr DPH1            = 0x85u;
sfr DPS             = 0x86u;

sfr SFRPRT0PS       = 0x89u;
sfr SFRPRT0SEL      = 0x8Au;
sfr SFRPRT1DR       = 0x90u;
sfr SFRPRT1PS       = 0x91u;

sfr DPX             = 0x93u;
sfr DPX1            = 0x95u;

sfr SFRPRT2DR       = 0x98u;
sfr SFRPRT2PS       = 0x99u;
sfr SFRPRT2SEL      = 0x9Au;

sfr P2AX            = 0xA0u;

sfr SFRPRT1SEL      = 0xA2u;

sfr IE              = 0xA8u;
sbit EA             = 0xA8u^7u;

sfr SFRPRT3DR       = 0xB0u;
sfr SFRPRT3PS       = 0xB1u;
sfr SFRPRT3SEL      = 0xB2u;
sfr SFRPRT4DR       = 0xC0u;
sfr SFRPRT4PS       = 0xC1u;
sfr SFRPRT4SEL      = 0xC2u;
sfr SFRPRT5DR       = 0xC8u;
sfr SFRPRT5PS       = 0xC9u;
sfr SFRPRT5SEL      = 0xCAu;

sfr PSW             = 0xD0u;
sbit P              = 0xD0u^0u;
sbit F1             = 0xD0u^1u;
sbit OV             = 0xD0u^2u;
sbit RS0            = 0xD0u^3u;
sbit RS1            = 0xD0u^4u;
sbit F0             = 0xD0u^5u;
sbit AC             = 0xD0u^6u;
sbit CY             = 0xD0u^7u;

sfr SFRPRT6DR       = 0xD8u;
sfr SFRPRT6PS       = 0xD9u;
sfr SFRPRT6SEL      = 0xDAu;

sfr ACC             = 0xE0u;

sfr SFRPRT12DR      = 0xE8u;
sfr SFRPRT12PS      = 0xE9u;
sfr MXAX            = 0xEAu;

sfr B               = 0xF0u;

sfr SFRPRT12SEL     = 0xF2u;
sfr SFRPRT15DR      = 0xF8u;
sfr SFRPRT15PS      = 0xF9u;
sfr SFRPRT15SEL     = 0xFAu;


#endif  /* (CY_BOOT_PSoC3_8051_H) */


/* [] END OF FILE */
