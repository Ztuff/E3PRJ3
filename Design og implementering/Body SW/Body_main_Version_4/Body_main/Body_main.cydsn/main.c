/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include "stdlib.h"
#include <stdio.h>

#include "SerialUnit.h"
#include "Sensor.h"

//Accelerometer ADXL345 defines
#define ACCEL_ADDRESS 0x53 // jumperen sættes til GND 
#define PWR_CTRL_REG 0x2D //Power control registeret Datablad side 26
#define PWR_MODE (1<<3) // Sættes i measurement mode, standby til den skal måle (Strømbesparende) 
#define DATAX0 0x32 //least significant 
#define DATAX1 0x33 //most significant
#define DATAY0 0x34
#define DATAY1 0x35
#define DATAZ0 0x36
#define DATAZ1 0x37

//Gyroscope MPU6050 defines 
#define GYRO_ADDRESS 0x68 //Jumperen sættes til GND 
#define GYRO_XOUT_H 0x43 // Most significant
#define GYRO_XOUT_L 0x44 // Least significant 
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48


//Prototyper
void initSensors(void);
void initADXL345(void);
void initMPU6050(void);


int main()
{
    //Initialisering
    initUART();
    initSensors();
    
    // Tænd Power indikator
    POWERPIN_Write(1);
    
	while(1)
    {
        // Klargøre I2C før hver aflæsning sensorer
        setupI2C();
  
        // Læs sensorer
        readAllSensors();
         
        // Standartiser sensordata
        convSensData();
        
        // Send sensordata
        sendDataArray(); 
        
        // Tilpas afsending til 50 Hz
        CyDelay(19); // 19 ms
        
    }     
            
		
	return 0;
}




void initSensors()
{	
	/***** INIT INDIVIDUAL SENSORS *****/
	//initMPU6050();	//Gyroscope
	initADXL345();	//Accellerometer
	// ..osv
}



//init accelerometer
void initADXL345(void)
{
	// Fylder ADXL345 ind i sensor array'et. 
	setSensArray(ACCEL_ADDRESS, DATAX0, DEFAULT_DATA);
	setSensArray(ACCEL_ADDRESS, DATAX1, DEFAULT_DATA);
	setSensArray(ACCEL_ADDRESS, DATAY0, DEFAULT_DATA);
	setSensArray(ACCEL_ADDRESS, DATAY1, DEFAULT_DATA);
	setSensArray(ACCEL_ADDRESS, DATAZ0, DEFAULT_DATA);
	setSensArray(ACCEL_ADDRESS, DATAZ1, DEFAULT_DATA);
	
	//Opsætter til I2C 
	if(I2C_1_I2CMasterSendStart(ACCEL_ADDRESS, I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR //Tjekker om transfer er fuldført uden fejl 
        && I2C_1_I2CMasterWriteByte(PWR_CTRL_REG) == I2C_1_I2C_MSTR_NO_ERROR // POWER CONTROL REGISTER
        && I2C_1_I2CMasterWriteByte(PWR_MODE) == I2C_1_I2C_MSTR_NO_ERROR) // Sættes i measurement mode. Standby til den skal måle (Strømbesparende) 
	handleI2CError();
}

//init gyroscope 
void initMPU6050(void)
{
	// Fylder ADXL345 ind i sensor array'et. 
	setSensArray(GYRO_ADDRESS, GYRO_XOUT_H, DEFAULT_DATA);
    setSensArray(GYRO_ADDRESS, GYRO_XOUT_L, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_YOUT_H, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_YOUT_L, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_ZOUT_H, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_ZOUT_L, DEFAULT_DATA);
	
	//Opsætter til I2C 
	if(I2C_1_I2CMasterSendStart(GYRO_ADDRESS, I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR) //Tjekker om transfer er fuldført uden fejl
	handleI2CError();
}


    




