/*******************************************************************************
* File Name: ERRORPIN.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ERRORPIN.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        ERRORPIN_PC =   (ERRORPIN_PC & \
                                (uint32)(~(uint32)(ERRORPIN_DRIVE_MODE_IND_MASK << (ERRORPIN_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (ERRORPIN_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: ERRORPIN_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void ERRORPIN_Write(uint8 value) 
{
    uint8 drVal = (uint8)(ERRORPIN_DR & (uint8)(~ERRORPIN_MASK));
    drVal = (drVal | ((uint8)(value << ERRORPIN_SHIFT) & ERRORPIN_MASK));
    ERRORPIN_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: ERRORPIN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ERRORPIN_DM_STRONG     Strong Drive 
*  ERRORPIN_DM_OD_HI      Open Drain, Drives High 
*  ERRORPIN_DM_OD_LO      Open Drain, Drives Low 
*  ERRORPIN_DM_RES_UP     Resistive Pull Up 
*  ERRORPIN_DM_RES_DWN    Resistive Pull Down 
*  ERRORPIN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ERRORPIN_DM_DIG_HIZ    High Impedance Digital 
*  ERRORPIN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ERRORPIN_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(ERRORPIN__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: ERRORPIN_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro ERRORPIN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ERRORPIN_Read(void) 
{
    return (uint8)((ERRORPIN_PS & ERRORPIN_MASK) >> ERRORPIN_SHIFT);
}


/*******************************************************************************
* Function Name: ERRORPIN_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 ERRORPIN_ReadDataReg(void) 
{
    return (uint8)((ERRORPIN_DR & ERRORPIN_MASK) >> ERRORPIN_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ERRORPIN_INTSTAT) 

    /*******************************************************************************
    * Function Name: ERRORPIN_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 ERRORPIN_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(ERRORPIN_INTSTAT & ERRORPIN_MASK);
		ERRORPIN_INTSTAT = maskedStatus;
        return maskedStatus >> ERRORPIN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
