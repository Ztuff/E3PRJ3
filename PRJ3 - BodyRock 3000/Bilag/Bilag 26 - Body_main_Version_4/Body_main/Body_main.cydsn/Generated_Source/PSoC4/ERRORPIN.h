/*******************************************************************************
* File Name: ERRORPIN.h  
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

#if !defined(CY_PINS_ERRORPIN_H) /* Pins ERRORPIN_H */
#define CY_PINS_ERRORPIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ERRORPIN_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ERRORPIN_Write(uint8 value) ;
void    ERRORPIN_SetDriveMode(uint8 mode) ;
uint8   ERRORPIN_ReadDataReg(void) ;
uint8   ERRORPIN_Read(void) ;
uint8   ERRORPIN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ERRORPIN_DRIVE_MODE_BITS        (3)
#define ERRORPIN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ERRORPIN_DRIVE_MODE_BITS))
#define ERRORPIN_DRIVE_MODE_SHIFT       (0x00u)
#define ERRORPIN_DRIVE_MODE_MASK        (0x07u << ERRORPIN_DRIVE_MODE_SHIFT)

#define ERRORPIN_DM_ALG_HIZ         (0x00u << ERRORPIN_DRIVE_MODE_SHIFT)
#define ERRORPIN_DM_DIG_HIZ         (0x01u << ERRORPIN_DRIVE_MODE_SHIFT)
#define ERRORPIN_DM_RES_UP          (0x02u << ERRORPIN_DRIVE_MODE_SHIFT)
#define ERRORPIN_DM_RES_DWN         (0x03u << ERRORPIN_DRIVE_MODE_SHIFT)
#define ERRORPIN_DM_OD_LO           (0x04u << ERRORPIN_DRIVE_MODE_SHIFT)
#define ERRORPIN_DM_OD_HI           (0x05u << ERRORPIN_DRIVE_MODE_SHIFT)
#define ERRORPIN_DM_STRONG          (0x06u << ERRORPIN_DRIVE_MODE_SHIFT)
#define ERRORPIN_DM_RES_UPDWN       (0x07u << ERRORPIN_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define ERRORPIN_MASK               ERRORPIN__MASK
#define ERRORPIN_SHIFT              ERRORPIN__SHIFT
#define ERRORPIN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ERRORPIN_PS                     (* (reg32 *) ERRORPIN__PS)
/* Port Configuration */
#define ERRORPIN_PC                     (* (reg32 *) ERRORPIN__PC)
/* Data Register */
#define ERRORPIN_DR                     (* (reg32 *) ERRORPIN__DR)
/* Input Buffer Disable Override */
#define ERRORPIN_INP_DIS                (* (reg32 *) ERRORPIN__PC2)


#if defined(ERRORPIN__INTSTAT)  /* Interrupt Registers */

    #define ERRORPIN_INTSTAT                (* (reg32 *) ERRORPIN__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins ERRORPIN_H */


/* [] END OF FILE */
