//========================================================================
// FILENAME : MAINusiTwiSlave.c
// CREATED : 30-11-2014
// AUTHOR  : Jeppe Hofni
// DESCR.  : c file for ATtiny26P
//
//------------------------------------------------------------------------
//
// REV.  DATE/AUTHOR  CHANGE DESCRIPTION
// 0.1  30-11-2014 - Jeppe - First writeup of main.
// 0.2	06-12-2014 - Jeppe - Sorted main function
// 0.3	11-12-2014 - Jeppe - I2C full implementation
//------------------------------------------------------------------------
// KNOWN ISSUES:
// REV. - ISSUE(S)
// 0.1 - Needs to be sorted proper
// 0.2 - Needs ISR and full implementation of functions
// 0.3 - Needs testing and full implementation
//========================================================================

#define F_CPU 8000000UL	      // Sets up the default speed for delay.h
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "usiTwiSlave.h"


//PortA Flexiforce interface
#define DDR_Flex             DDRA
#define PORT_Flex            PORTA
#define PIN_Flex             PINA
#define PIN_Flex_In			 PINA0 //ADC0


// Local variables
uint8_t slaveadress = 2;	// Static slave address set to 2
uint8_t adcArray[3];		// Register for Device ID [0] and ADC data [1..2]
unit8_t ADC_flag = 1;

// Prototypes
void InitADC(void);

// ISR definition
ISR (ADC_vect)
{
	// Set ADC_flag
	ADC_flag = 1;
}



int main(void)
{
	//********** Initiate variables *********
	adcArray[0] = 4;						// Device ID for Flexiforce 301A
	adcArray[1] = 0;
	adcArray[2] = 0;
	
	//********** Initialization ********** 
	
	usiTwiSlaveInit( slaveadress );			// Enable TWI I2C and set static slave address
	InitADC();								// Init ADC
	sei();									// Init global interupt
	
	//********** Main functions **********
	while(1)
	{
		
		if(!ADC_flag)
		{
		adcArray[1] = ADCL;
		adcArray[2] = ADCH;
		ADC_flag = 0;
		}

		
		while(!usiTwiDataInReceiveBuffer());		// Wait for master
		usiTwiTransmitByte(adcArray[0]);	// Send sensor ID
		
		while(!usiTwiDataInReceiveBuffer());		// Wait for master
		usiTwiTransmitByte(adcArray[1]);	// Send low part of sensordata
	
		while(!usiTwiDataInReceiveBuffer());		// Wait for master
		usiTwiTransmitByte(adcArray[2]);	// Send high part of sensordata
		
	}
	
	
	return 0;
}




void InitADC(void)
{
	DDR_Flex |= (0<<PIN_Flex_In);			//Enable ADC0 input on PINA0.
	
	//Datasheet page 101
	ADMUX = (0<<REFS1)|(1<<REFS0)|          //External PA3 reference VCC/2 = 3.3V/2 = 1.65V
	(0<<ADLAR)|								//ADLAR = 0
	(0<<MUX4)|(0<<MUX3)|(0<<MUX2)|			//Input = ADC3 single ended
	(1<<MUX1)|(1<<MUX0);
	
	
	//Datasheet page 103
	ADCSR = (1<<ADEN)|(0<<ADSC)|			//ADEN = 1 ADC enable, ADSC = 0
	(1<<ADFR)|(0<<ADIF)|					//ADRF = 1 Free Running Select, ADIF = 0
	(1<<ADIE)|								//ADIE = 1 ADC Interrupt Enable,
	(0<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);		//ADC prescaler = 8 (=> ADC clock = 8 MHz / 4 = 125 kHZ)
	
}



