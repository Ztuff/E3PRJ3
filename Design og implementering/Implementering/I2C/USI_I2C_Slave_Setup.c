//========================================================================
// FILENAME : USI_I2C_Slave_Setup.c
// CREATED : 7-11-2014
// AUTHOR  : Jeppe Hofni
// DESCR.  : c file for ATtiny26P
//
//------------------------------------------------------------------------
//
// REV.  DATE/AUTHOR  CHANGE DESCRIPTION
// 0.1  07-11-2014 - Jeppe - First writeup of initiation functions.
// 0.2	16-11-2014 - Jeppe - Ver 1 of initiation functions for I2C and ADC conversion.
//
//------------------------------------------------------------------------
// KNOWN ISSUES:
// REV. - ISSUE(S)
// 0.1 - Needs proper USI I2C setup and Flexiforce A301 interface
// 0.2 - Needs testing of USI I2C and proper Flexiforce ADC initiation
//========================================================================
#include <avr/interrupt.h>
#define F_CPU 8000000UL	      // Sets up the default speed for delay.h
#include <util/delay.h>
#include <avr/io.h>
#include "USI_I2C_Slave_Setup.h"

/*---------------------------------------------------------------
 USI I2C_Slave initialization function
---------------------------------------------------------------*/
void USI_I2C_Slave_Initialize( void ) //Initialize I2C and Flexiforce_Transicer 
{
	PORT_USI |= (1<<PIN_USI_SDA);           // Enable pullup on SDA, to set high as released state.
	PORT_USI |= (1<<PIN_USI_SCL);           // Enable pullup on SCL, to set high as released state.
	
	DDR_USI  |= (1<<PIN_USI_SCL);           // Enable SCL as output.
	DDR_USI  |= (1<<PIN_USI_SDA);           // Enable SDA as output.
	
	
	/*Setup settings can be found in datasheet page 81-84 */
	USIDR    =  0xFF;												// Preload data-register with "released level" data.
	
	USISR	 =  (1<<USISIF)|(1<<USIOIF)|(1<<USIPF)|(1<<USIDC)|      // Clear flags,
				(0<<USICNT0);										// and reset counter.
																	
	USICR    =	(1<<USISIE)|(0<<USIOIE)|                            // Enable Interrupts.
	(1<<USIWM1)|(0<<USIWM0)|										// Set USI in Two-wire mode.
	(1<<USICS1)|(1<<USICS0)|(0<<USICLK)|							// External clock source negative edge
	(0<<USITC);			
	
}


/*****************************************************************************************************************************************
 Når der kommer et start interrupt så skal USI_I2C_Start_Transceiver_With_Data have USIDR registret sendt til sig så det kan tjekke på det
******************************************************************************************************************************************/




/*---------------------------------------------------------------
 USI Normal Read / Write Function
 Transmit and receive function. LSB of first byte in buffer 
 indicates if a read or write cycles is performed. If set a read
 operation is performed.

 Function generates (Repeated) Start Condition, sends address and
 R/W, Reads/Writes Data, and verifies/sends ACK.
 
---------------------------------------------------------------*/
unsigned char USI_I2C_Start_Transceiver_With_Data( unsigned char *msg, unsigned char msgSize)
{
	int USI_READ_READY = 0;
	
	if(msgSize <= 1)									// Test if the transmission buffer is empty
	{
		return 0;
	}                              
	if( USISR & (1<<USISIF) )							// Test if any unexpected conditions have arrived prior to this execution.
	{
		return 0;										// Unexpected Start Condition						
	}
	if( USISR & (1<<USIPF) )
	{
		return 0;										// Unexpected Stop Condition
	}
	if( USISR & (1<<USIDC) )
	{
		return 0;										// Unexpected Data Collision
	}
	
	
	if ( !(*msg & (1<<USI_I2C_READ_BIT)) )									// The LSB in the address byte determines if is a Read or Write operation.
	{
		USI_READ_READY = 1;
	}



	if (USI_READ_READY == 1)
	{
		USI_READ_READY = 0;
		USI_I2C_Slave_Start();
		
		
		/*****************************************************************************************************************************************
		Send sensordata over bus
		******************************************************************************************************************************************/
		USI_I2C_Slave_Transfer( msg ); //??????????
		
		
		USI_I2C_Slave_Stop();
	}

}


/*---------------------------------------------------------------
 Function for shifting data in and out from the USI.
 Data to be sent has to be placed into the USIDR before to calling
 this function. Data read, will be return'ed from the function.
---------------------------------------------------------------*/
unsigned char USI_I2C_Slave_Transfer( unsigned char temp )
{
  /*Datasheet page ??? */
  USISR = temp;                                     // Set USISR according to temp.
                                                    // Prepare clocking.
													
  temp  =	(1<<USISIE)|(0<<USIOIE)|                // Enable Interrupts.
			(1<<USIWM1)|(0<<USIWM0)|				// Set USI in Two-wire mode.
			(1<<USICS1)|(1<<USICS0)|(0<<USICLK)|	// External clock source negative edge
			(0<<USITC);								// Toggle Clock Port.?????
  
  
  do
  {													
	_delay_us(Time5);
	USICR = temp;									// Generate positive SCL edge.
	while( !(PIN_USI & (1<<PIN_USI_SCL)) );			// Wait for SCL to go high.
	delay_us(Time4);
	USICR = temp;									// Generate negative SCL edge.
  }while( !(USISR & (1<<USIOIF)) );					// Check for transfer complete.
  
	_delay_us(Time5);
  temp  = USIDR;									// Read out data.
  USIDR = 0xFF;										// Release SDA.
  DDR_USI |= (1<<PIN_USI_SDA);						// Enable SDA as output.

  return temp;										// Return the data from the USIDR
}		



/*---------------------------------------------------------------
 Function for generating a I2C_Slave Start Condition. 
---------------------------------------------------------------*/
unsigned char USI_I2C_Slave_Start( void )
{
 /*Datasheet page 85 */
 /* Release SCL to ensure that (repeated) Start can be performed */
  PORT_USI |= (1<<PIN_USI_SCL);                     // Release SCL.
  while( !(PORT_USI & (1<<PIN_USI_SCL)) );          // Verify that SCL becomes high.
  _delay_us(Time5);

 /* Generate Start Condition */
  PORT_USI &= ~(1<<PIN_USI_SDA);                    // Force SDA LOW.
	_delay_us(Time4);                         
  PORT_USI &= ~(1<<PIN_USI_SCL);                    // Pull SCL LOW.
  PORT_USI |= (1<<PIN_USI_SDA);                     // Release SDA.

  return 1;
}



/*---------------------------------------------------------------
 Function for generating a I2C_Slave Stop Condition. Used to release 
 the I2C_Slave bus.
---------------------------------------------------------------*/
unsigned char U1SI_I2C_Slave_Stop( void )
{
  /*Datasheet page 85 */
  PORT_USI &= ~(1<<PIN_USI_SDA);           // Pull SDA low.
  PORT_USI |= (1<<PIN_USI_SCL);            // Release SCL.
  while( !(PIN_USI & (1<<PIN_USI_SCL)) );  // Wait for SCL to go high.  
	_delay_us(Time4);
  PORT_USI |= (1<<PIN_USI_SDA);            // Release SDA.
	_delay_us(Time5);
  
  return 1;
}




/*---------------------------------------------------------------
 Flexiforce A301 ADC initialization function
---------------------------------------------------------------*/
void Flexiforce_ADC_Initialize( void )	
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
											
	//MANGLER "Trigger Source" = 
}
