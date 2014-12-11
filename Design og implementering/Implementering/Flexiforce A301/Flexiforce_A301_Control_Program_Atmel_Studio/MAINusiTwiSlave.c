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


// Prototypes
void InitADC(void);

// ISR definition
ISR (ADC_vect)
{
	// Set ADC result in
	adcArray[1] = ADCL;
	adcArray[2] = ADCH;
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
				
		while(!usiTwiReceiveByte());		// Wait for master
		usiTwiTransmitByte(adcArray[0]);	// Send sensor ID
		
		while(!usiTwiReceiveByte());		// Wait for master
		usiTwiTransmitByte(adcArray[1]);	// Send low part of sensordata
	
		while(!usiTwiReceiveByte());		// Wait for master
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



