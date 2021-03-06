//========================================================================
// FILENAME : USI_I2C_Slave_Setup.h
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
    
//********** Defines **********//

#define USI_I2C_READ_BIT  0       // Bit position for R/W bit in "address byte".

// Device dependant defines - These for ATtiny26(L).
//PortB I2C interface
#define DDR_USI             DDRB
#define PORT_USI            PORTB
#define PIN_USI             PINB
#define PORT_USI_SDA        PB5
#define PORT_USI_SCL        PB7
#define PIN_USI_SDA         PINB0
#define PIN_USI_SCL         PINB3

//PortA Flexiforce interface
#define DDR_Flex             DDRA
#define PORT_Flex            PORTA
#define PIN_Flex             PINA
#define PIN_Flex_In			 PINA0 //ADC0

// For use with _delay_us()
#define Time5    40 		// >4,7us
#define Time4    32 		// >4,0us

//********** Prototypes **********//

/*---------------------------------------------------------------
 USI I2C_Slave initialization function
---------------------------------------------------------------*/
void USI_I2C_Slave_Initialize( void ); //Initierer I2C og Flexiforce_Transicer 

/*---------------------------------------------------------------
 USI I2C_Slave Flexiforce interface
---------------------------------------------------------------*/
void Flexiforce_ADC_Initialize( void );
void USI_I2C_Slave_Start_Flexiforce_ADC_Receiver( ); // Hvad modtager den?

/*---------------------------------------------------------------
 USI I2C_Slave transfer functions
---------------------------------------------------------------*/
unsigned char USI_I2C_Slave_Transfer( unsigned char ); //I2C sender
unsigned char USI_I2C_Slave_Start( void ); // Bruges til at sende start signal over bus
unsigned char USI_I2C_Slave_Stop( void ); // Bruges til at sende stop signal over bus
unsigned char USI_TWI_Start_Transceiver_With_Data( unsigned char * , unsigned char ); //Tjek read or write