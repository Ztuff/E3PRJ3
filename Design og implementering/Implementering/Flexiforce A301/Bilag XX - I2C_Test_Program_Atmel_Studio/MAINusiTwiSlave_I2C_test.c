//========================================================================
// FILENAME : MAINusiTwiSlave_I2C_test.c
// CREATED : 30-11-2014
// AUTHOR  : Jeppe Hofni
// DESCR.  : c file for ATtiny26P
//
//------------------------------------------------------------------------
//
// REV.  DATE/AUTHOR  CHANGE DESCRIPTION
// 0.1  30-11-2014 - Jeppe - First writeup of main.
// 0.2	06-12-2014 - Jeppe - Sorted main function
// 0.3	10-12-2014 - Jeppe - Made in to test version from orginal MainusiTwiSlave
//------------------------------------------------------------------------
// KNOWN ISSUES:
// REV. - ISSUE(S)
// 0.1 - Needs to be sorted proper
// 0.2 - Needs ISR and full implementation of functions
// 0.3 - Needs ADC and pointer receiving funktion
//========================================================================


#define F_CPU 8000000UL	      // Sets up the default speed for delay.h
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "usiTwiSlave.h"
#include "FLEXI_ADC.h"

uint8_t slaveadress = 2;	// Static slave address set to 2
uint8_t registers[3];		// Register for Device ID [0] and ADC data [1..2]




int main(void)
{
	//********** Local variables *********
	registers[0] = 4; // Device ID for Flexiforce 301A
	registers[1] = 11;
	registers[2] = 22;
	
	//********** Initialization ********** 
	
	usiTwiSlaveInit( slaveadress ); // Enable TWI I2C and set static slave address
	
	
	
	//********** Main functions **********
	while(1)
	{
				
		while(!usiTwiDataInReceiveBuffer());
		usiTwiTransmitByte(registers[0];
		
		while(!usiTwiDataInReceiveBuffer());
		usiTwiTransmitByte(registers[1];
	
		while(!usiTwiDataInReceiveBuffer());
		usiTwiTransmitByte(registers[2];
		
	}
	
	
	return 0;
}

