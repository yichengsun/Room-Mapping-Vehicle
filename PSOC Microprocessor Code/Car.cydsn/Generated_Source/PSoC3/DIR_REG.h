/*******************************************************************************
* File Name: DIR_REG.h  
* Version 1.70
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_DIR_REG_H) /* CY_CONTROL_REG_DIR_REG_H */
#define CY_CONTROL_REG_DIR_REG_H

#include "cytypes.h"


/***************************************
*         Function Prototypes 
***************************************/

void    DIR_REG_Write(uint8 control) ;
uint8   DIR_REG_Read(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define DIR_REG_Control        (* (reg8 *) DIR_REG_Sync_ctrl_reg__CONTROL_REG )
#define DIR_REG_Control_PTR    (  (reg8 *) DIR_REG_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_DIR_REG_H */


/* [] END OF FILE */
