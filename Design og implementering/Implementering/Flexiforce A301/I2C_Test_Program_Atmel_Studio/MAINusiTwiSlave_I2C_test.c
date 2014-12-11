


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

