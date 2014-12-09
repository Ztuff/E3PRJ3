/*******************************************************************************
* File Name: ButtonMatrix01_1_ISR_C.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <ButtonMatrix01_1_ISR_C.h>

#if !defined(ButtonMatrix01_1_ISR_C__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ButtonMatrix01_1_ISR_C_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_Start(void)
{
    /* For all we know the interrupt is active. */
    ButtonMatrix01_1_ISR_C_Disable();

    /* Set the ISR to point to the ButtonMatrix01_1_ISR_C Interrupt. */
    ButtonMatrix01_1_ISR_C_SetVector(&ButtonMatrix01_1_ISR_C_Interrupt);

    /* Set the priority. */
    ButtonMatrix01_1_ISR_C_SetPriority((uint8)ButtonMatrix01_1_ISR_C_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ButtonMatrix01_1_ISR_C_Enable();
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ButtonMatrix01_1_ISR_C_Disable();

    /* Set the ISR to point to the ButtonMatrix01_1_ISR_C Interrupt. */
    ButtonMatrix01_1_ISR_C_SetVector(address);

    /* Set the priority. */
    ButtonMatrix01_1_ISR_C_SetPriority((uint8)ButtonMatrix01_1_ISR_C_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ButtonMatrix01_1_ISR_C_Enable();
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_Stop(void)
{
    /* Disable this interrupt. */
    ButtonMatrix01_1_ISR_C_Disable();

    /* Set the ISR to point to the passive one. */
    ButtonMatrix01_1_ISR_C_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ButtonMatrix01_1_ISR_C.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(ButtonMatrix01_1_ISR_C_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ButtonMatrix01_1_ISR_C_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ButtonMatrix01_1_ISR_C_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ButtonMatrix01_1_ISR_C_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + ButtonMatrix01_1_ISR_C__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress ButtonMatrix01_1_ISR_C_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + ButtonMatrix01_1_ISR_C__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ButtonMatrix01_1_ISR_C_Start
*   or ButtonMatrix01_1_ISR_C_StartEx will override any effect this method would 
*   have had. This method should only be called after ButtonMatrix01_1_ISR_C_Start or 
*   ButtonMatrix01_1_ISR_C_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((ButtonMatrix01_1_ISR_C__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *ButtonMatrix01_1_ISR_C_INTC_PRIOR = (*ButtonMatrix01_1_ISR_C_INTC_PRIOR & (uint32)(~ButtonMatrix01_1_ISR_C__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 ButtonMatrix01_1_ISR_C_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((ButtonMatrix01_1_ISR_C__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*ButtonMatrix01_1_ISR_C_INTC_PRIOR & ButtonMatrix01_1_ISR_C__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_Enable(void)
{
    /* Enable the general interrupt. */
    *ButtonMatrix01_1_ISR_C_INTC_SET_EN = ButtonMatrix01_1_ISR_C__INTC_MASK;
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 ButtonMatrix01_1_ISR_C_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ButtonMatrix01_1_ISR_C_INTC_SET_EN & (uint32)ButtonMatrix01_1_ISR_C__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_Disable(void)
{
    /* Disable the general interrupt. */
    *ButtonMatrix01_1_ISR_C_INTC_CLR_EN = ButtonMatrix01_1_ISR_C__INTC_MASK;
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_SetPending(void)
{
    *ButtonMatrix01_1_ISR_C_INTC_SET_PD = ButtonMatrix01_1_ISR_C__INTC_MASK;
}


/*******************************************************************************
* Function Name: ButtonMatrix01_1_ISR_C_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void ButtonMatrix01_1_ISR_C_ClearPending(void)
{
    *ButtonMatrix01_1_ISR_C_INTC_CLR_PD = ButtonMatrix01_1_ISR_C__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
