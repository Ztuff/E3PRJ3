//========================================================================
// FILENAME : USI_I2C_Slave_Main.c
// CREATED : 7-11-2014
// AUTHOR  : Jeppe Hofni
// DESCR.  : c file for ATtiny26P
//
//------------------------------------------------------------------------
//
// REV.  DATE/AUTHOR  CHANGE DESCRIPTION
// 0.1  07-11-2014 - Jeppe - First writeup of main.
// 0.2	16-11-2014 - Jeppe - Sorted main function
//------------------------------------------------------------------------
// KNOWN ISSUES:
// REV. - ISSUE(S)
// 0.1 - Needs to be sorted proper
// 0.2 - Needs full implementation of functions
//========================================================================
#include <avr/interrupt.h>
#define F_CPU 1000000UL	      // Sets up the default speed for delay.h
#include <util/delay.h>
#include <avr/io.h>
#include "USI_I2C_Slave_Setup.h"


#define PORT_ADDR  0x38 //0b10011000 I2C address

#define MESSAGEBUF_SIZE       4


//---------------------------------------------------------------------------
// Behavior: 
//---------------------------------------------------------------------------

int main()
{

	unsigned char messageBuf[MESSAGEBUF_SIZE];
	unsigned char I2C_SlaveAddress, temp, myData=0;
	
	
	//Initialize
	USI_I2C_Slave_Initialize();
  
  I2C_SlaveAddress   = PORT_ADDR;	
  
  while(1)
	{

	/* --------------------------------------------------------------
	** Flexiforce read and I2C transfer. 
	**	If Flexiforce A301 is pressed, then an interrupt is generated
	** 	reading the magnitude of the pressure. This pressure is 
	** 	ADC converted into a number between 0 and 127 and then send via
	**	the I2C slave interface.
	**
	** 	Flexiforce A301 has an "not pressed value". When this value 
	**	change Flexiforce is pressed. When this value is at the "not
	** 	pressed value" the pressure is over and the interrupt stops.
	**--------------------------------------------------------------*/
 
 
	}

  return 1;
}




