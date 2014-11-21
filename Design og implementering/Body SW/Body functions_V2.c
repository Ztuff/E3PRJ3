#define MAXREGNUM 96
#define DEFAULT_DATA 0 // Default data i array sættes til 0. 
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



uint8_t numOfRegToRead = 0;	//current number of initialized sensor registers to read from 
 
int sensArray[MAXREGNUM][3];	//Array containing {i2c device address, registerToRead, dataTarget}
								//Initeres til 0 og fyldes op undervejs i funktionen setSensarray

int main()
{
	setupI2C(); 
	
	initSensors();
	
	while(1)
		readAllSensors();
		
	return 0;
}

void initSensors()
{	
	/***** INIT INDIVIDUAL SENSORS *****/
	initMPU6050();	//Gyroscope
	initADXL345();	//Accellerometer
	// ..osv
}

void setSensArray(int deviceAddress, int registerToRead, int dataTarget)
{
	sensArray[numOfRegToRead][0]=deviceAddress;		//set device address
	sensArray[numOfRegToRead][1]=registerToRead;	//set register for future read
	sensArray[numOfRegToRead][2]=dataTarget;		//set where to save read data
	++numOfRegToRead;								//increment current number of places in array that are set
	
	//Skriv noget fejlsikring hvis numOfRegToRead kommer over 96, skal der sættes den pin høj på PSoC som styrer fejldioden. 
}

int readAllSensors()
{
	for (int i = 0; i < numOfRegToRead; i++)
	{
		readSensor(i);
	}
	
}

int readSensor(int i)
{
	sendI2C(sensArray[i][0], sensArray[i][1]);	// (DeviceAddress, RegisterToRead)
}

int sendI2C(int sensArray[i][0], sensArray[i][1] )
{
	uint8 rawData; 
	if (I2C_1_I2CMasterSendStart(sensArray[i][0], I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR) /* Check if transfer completed without errors */
    { 
        if(I2C_1_I2CMasterWriteByte(sensArray[i][1]) == I2C_1_I2C_MSTR_NO_ERROR)
		{
            if(I2C_1_I2CMasterSendRestart(sensArray[i][0], I2C_1_I2C_READ_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR)
			{
                rawData = I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA);
                I2C_1_I2CMasterSendStop();
				
				sensArray[i][2] = rawData; // gemmer rawData på den tilhørende plads i sensArray. 
			}
		}
	}
				
	
}

void setupI2C()
{
	I2C_1_Start();
    I2C_1_I2CMasterClearStatus();
}	

//init accelerometer
void initADXL345()
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
	I2C_1_I2CMasterSendStop();		
}

//init gyroscope 
void initMPU6050()
{
	// Fylder ADXL345 ind i sensor array'et. 
	setSensArray(GYRO_ADDRESS, GYRO_XOUT_H, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_XOUT_L, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_YOUT_H, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_YOUT_L, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_ZOUT_H, DEFAULT_DATA);
	setSensArray(GYRO_ADDRESS, GYRO_ZOUT_L, DEFAULT_DATA);
	
	//Opsætter til I2C 
	if(I2C_1_I2CMasterSendStart(GYRO_ADDRESS, I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR //Tjekker om transfer er fuldført uden fejl
	I2C_1_I2CMasterSendStop();	
}

