/*******************************************************************************
* File Name: POWERPIN.h  
* Version 2.5
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

#if !defined(CY_PINS_POWERPIN_H) /* Pins POWERPIN_H */
#define CY_PINS_POWERPIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "POWERPIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    POWERPIN_Write(uint8 value) ;
void    POWERPIN_SetDriveMode(uint8 mode) ;
uint8   POWERPIN_ReadDataReg(void) ;
uint8   POWERPIN_Read(void) ;
uint8   POWERPIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define POWERPIN_DRIVE_MODE_BITS        (3)
#define POWERPIN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - POWERPIN_DRIVE_MODE_BITS))
#define POWERPIN_DRIVE_MODE_SHIFT       (0x00u)
#define POWERPIN_DRIVE_MODE_MASK        (0x07u << POWERPIN_DRIVE_MODE_SHIFT)

#define POWERPIN_DM_ALG_HIZ         (0x00u << POWERPIN_DRIVE_MODE_SHIFT)
#define POWERPIN_DM_DIG_HIZ         (0x01u << POWERPIN_DRIVE_MODE_SHIFT)
#define POWERPIN_DM_RES_UP          (0x02u << POWERPIN_DRIVE_MODE_SHIFT)
#define POWERPIN_DM_RES_DWN         (0x03u << POWERPIN_DRIVE_MODE_SHIFT)
#define POWERPIN_DM_OD_LO           (0x04u << POWERPIN_DRIVE_MODE_SHIFT)
#define POWERPIN_DM_OD_HI           (0x05u << POWERPIN_DRIVE_MODE_SHIFT)
#define POWERPIN_DM_STRONG          (0x06u << POWERPIN_DRIVE_MODE_SHIFT)
#define POWERPIN_DM_RES_UPDWN       (0x07u << POWERPIN_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define POWERPIN_MASK               POWERPIN__MASK
#define POWERPIN_SHIFT              POWERPIN__SHIFT
#define POWERPIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POWERPIN_PS                     (* (reg32 *) POWERPIN__PS)
/* Port Configuration */
#define POWERPIN_PC                     (* (reg32 *) POWERPIN__PC)
/* Data Register */
#define POWERPIN_DR                     (* (reg32 *) POWERPIN__DR)
/* Input Buffer Disable Override */
#define POWERPIN_INP_DIS                (* (reg32 *) POWERPIN__PC2)


#if defined(POWERPIN__INTSTAT)  /* Interrupt Registers */

    #define POWERPIN_INTSTAT                (* (reg32 *) POWERPIN__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins POWERPIN_H */


/* [] END OF FILE */
