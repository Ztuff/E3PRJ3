/*******************************************************************************
* File Name: POWERPIN.c  
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
#include "POWERPIN.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        POWERPIN_PC =   (POWERPIN_PC & \
                                (uint32)(~(uint32)(POWERPIN_DRIVE_MODE_IND_MASK << (POWERPIN_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (POWERPIN_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: POWERPIN_Write
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
void POWERPIN_Write(uint8 value) 
{
    uint8 drVal = (uint8)(POWERPIN_DR & (uint8)(~POWERPIN_MASK));
    drVal = (drVal | ((uint8)(value << POWERPIN_SHIFT) & POWERPIN_MASK));
    POWERPIN_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: POWERPIN_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  POWERPIN_DM_STRONG     Strong Drive 
*  POWERPIN_DM_OD_HI      Open Drain, Drives High 
*  POWERPIN_DM_OD_LO      Open Drain, Drives Low 
*  POWERPIN_DM_RES_UP     Resistive Pull Up 
*  POWERPIN_DM_RES_DWN    Resistive Pull Down 
*  POWERPIN_DM_RES_UPDWN  Resistive Pull Up/Down 
*  POWERPIN_DM_DIG_HIZ    High Impedance Digital 
*  POWERPIN_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void POWERPIN_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(POWERPIN__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: POWERPIN_Read
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
*  Macro POWERPIN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 POWERPIN_Read(void) 
{
    return (uint8)((POWERPIN_PS & POWERPIN_MASK) >> POWERPIN_SHIFT);
}


/*******************************************************************************
* Function Name: POWERPIN_ReadDataReg
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
uint8 POWERPIN_ReadDataReg(void) 
{
    return (uint8)((POWERPIN_DR & POWERPIN_MASK) >> POWERPIN_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(POWERPIN_INTSTAT) 

    /*******************************************************************************
    * Function Name: POWERPIN_ClearInterrupt
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
    uint8 POWERPIN_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(POWERPIN_INTSTAT & POWERPIN_MASK);
		POWERPIN_INTSTAT = maskedStatus;
        return maskedStatus >> POWERPIN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
