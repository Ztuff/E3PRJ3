/*******************************************************************************
* File Name: ButtonMatrix01_1_BM_3.h  
* Version 2.0
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

#if !defined(CY_PINS_ButtonMatrix01_1_BM_3_H) /* Pins ButtonMatrix01_1_BM_3_H */
#define CY_PINS_ButtonMatrix01_1_BM_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ButtonMatrix01_1_BM_3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ButtonMatrix01_1_BM_3_Write(uint8 value) ;
void    ButtonMatrix01_1_BM_3_SetDriveMode(uint8 mode) ;
uint8   ButtonMatrix01_1_BM_3_ReadDataReg(void) ;
uint8   ButtonMatrix01_1_BM_3_Read(void) ;
uint8   ButtonMatrix01_1_BM_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ButtonMatrix01_1_BM_3_DRIVE_MODE_BITS        (3)
#define ButtonMatrix01_1_BM_3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ButtonMatrix01_1_BM_3_DRIVE_MODE_BITS))
#define ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT       (0x00u)
#define ButtonMatrix01_1_BM_3_DRIVE_MODE_MASK        (0x07u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)

#define ButtonMatrix01_1_BM_3_DM_ALG_HIZ         (0x00u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)
#define ButtonMatrix01_1_BM_3_DM_DIG_HIZ         (0x01u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)
#define ButtonMatrix01_1_BM_3_DM_RES_UP          (0x02u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)
#define ButtonMatrix01_1_BM_3_DM_RES_DWN         (0x03u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)
#define ButtonMatrix01_1_BM_3_DM_OD_LO           (0x04u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)
#define ButtonMatrix01_1_BM_3_DM_OD_HI           (0x05u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)
#define ButtonMatrix01_1_BM_3_DM_STRONG          (0x06u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)
#define ButtonMatrix01_1_BM_3_DM_RES_UPDWN       (0x07u << ButtonMatrix01_1_BM_3_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define ButtonMatrix01_1_BM_3_MASK               ButtonMatrix01_1_BM_3__MASK
#define ButtonMatrix01_1_BM_3_SHIFT              ButtonMatrix01_1_BM_3__SHIFT
#define ButtonMatrix01_1_BM_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ButtonMatrix01_1_BM_3_PS                     (* (reg32 *) ButtonMatrix01_1_BM_3__PS)
/* Port Configuration */
#define ButtonMatrix01_1_BM_3_PC                     (* (reg32 *) ButtonMatrix01_1_BM_3__PC)
/* Data Register */
#define ButtonMatrix01_1_BM_3_DR                     (* (reg32 *) ButtonMatrix01_1_BM_3__DR)
/* Input Buffer Disable Override */
#define ButtonMatrix01_1_BM_3_INP_DIS                (* (reg32 *) ButtonMatrix01_1_BM_3__PC2)


#if defined(ButtonMatrix01_1_BM_3__INTSTAT)  /* Interrupt Registers */

    #define ButtonMatrix01_1_BM_3_INTSTAT                (* (reg32 *) ButtonMatrix01_1_BM_3__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins ButtonMatrix01_1_BM_3_H */


/* [] END OF FILE */
