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

#include "Sensor.h"
#include "BTUART.h"



uint8_t numOfRegToRead = 0;
int sensArray[MAXREGNUM][3];	//Array containing {i2c device address, registerToRead, dataTarget}
								//Initeres til 0 og fyldes op undervejs i funktionen setSensarray

void setupI2C()
{
	I2C_1_Start();
    I2C_1_I2CMasterClearStatus();
}	



void setSensArray(int deviceAddress, int registerToRead, int dataTarget)
{
	sensArray[numOfRegToRead][0]=deviceAddress;		//set device address
	sensArray[numOfRegToRead][1]=registerToRead;	//set register for future read
	sensArray[numOfRegToRead][2]=dataTarget;		//set where to save read data
	++numOfRegToRead;								//increment current number of places in array that are set
	
	//Skriv noget fejlsikring hvis numOfRegToRead kommer over 96, skal der sættes den pin høj på PSoC som styrer fejldioden. 
}



void readAllSensors()
{
    int numOfReg; 
	for (numOfReg = 0; numOfReg < numOfRegToRead; numOfReg++)
	{
		readI2C(numOfReg);
	}
	
}

void convSensData(void)
{
    //ADXL345
    int16 x, y, z; // Da det er to 8 bit registre som skal lægges sammen
    unsigned char x1, y1, z1; 
    //Samler most significant og least significant for X
    x = sensArray[1][2]<< 8; 
    x+= sensArray[0][2];
    
    //Samler most significant og least significant for Y
    y = sensArray[3][2]<< 8; 
    y+= sensArray[2][2];
    
    //Samler most significant og least significant for Z
    z = sensArray[5][2]<< 8; 
    z+= sensArray[4][2];
    
    
    //conversion from int16 to uint8 which is the scale midi can receive
    x1 = (x+512)/8; 
    y1 = (y+512)/8;
    z1 = (z+512)/8;
    
    setdataArray(ACC1_ID, x1, y1, z1);
    
    
}



void readI2C(int numOfReg)
{
   	uint8 rawData; 
    
	if (I2C_1_I2CMasterSendStart(sensArray[numOfReg][0], I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR) /* Check if transfer completed without errors */
    { 
        if(I2C_1_I2CMasterWriteByte(sensArray[numOfReg][1]) == I2C_1_I2C_MSTR_NO_ERROR)
		{
            if(I2C_1_I2CMasterSendRestart(sensArray[numOfReg][0], I2C_1_I2C_READ_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR)
			{
                rawData = I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA);
                I2C_1_I2CMasterSendStop();
				
                
				sensArray[numOfReg][2] = rawData; // gemmer rawData på den tilhørende plads i sensArray. 
			}
		}
	}
				
}


void handleI2CError(void)
{
    I2C_1_I2CMasterSendStop();	 
}





/* [] END OF FILE */
