/* ========================================
 *
 * Copyright E3PRJ3GR09, E2014
 * Enhedstest accellerometer (ADXL345)
 *
 * ========================================
*/
#include <project.h>
#include "stdlib.h"
#include <stdio.h>

#define ACCEL_ADDRESS 0x53 //Accellerometer I2C addresse, med jumper til GND. 
#define DEVID 0x00         //Register hvor device ID står. (0xE5).
#define PWR_CTRL_REG 0x2D  //Power control register side 25 i databladet for ADXL345.
#define PWR_MODE (1<<3)    //Sættes i measure mode, hvilket betyder sleep indtil den aktiveres (strømbesparende). 
uint8 rawData;             //Variabel til at gemme sensordata

int main()
{
    /*UART initiering*/
    UART_1_Start();
    UART_1_UartPutString("This is a unit test of accelerometer ADXL345\n\r\n");
    /*I2C initiering*/
    I2C_1_Start(); 
    I2C_1_I2CMasterClearStatus();
    
    /*Opsætter accellerometer til I2C*/
    if(I2C_1_I2CMasterSendStart(ACCEL_ADDRESS, I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR
        && I2C_1_I2CMasterWriteByte(PWR_CTRL_REG) == I2C_1_I2C_MSTR_NO_ERROR
        && I2C_1_I2CMasterWriteByte(PWR_MODE) == I2C_1_I2C_MSTR_NO_ERROR) 
    UART_1_UartPutString("Accelerometer ADXL345 initialized.\n\r\n");
    UART_1_UartPutString("10000 reads, from reg DEVID, will now be performed.\n\rPlease wait.\n\r\n");
    
    I2C_1_I2CMasterSendStop();
    int errors = 0; //Variabel til at tælle fejl 
    int i;
    for(i = 0; i < 10000; i++) //Forløkke som løber igennem læsningen 10000 gange. (fra DEVID) 
    {
        if (I2C_1_I2CMasterSendStart(ACCEL_ADDRESS, I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR) /* Tjekker om transfer er sket uden fejl */
        { 
            if(I2C_1_I2CMasterWriteByte(DEVID) == I2C_1_I2C_MSTR_NO_ERROR)
            {
                if(I2C_1_I2CMasterSendRestart(ACCEL_ADDRESS, I2C_1_I2C_READ_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR)
                {
                    rawData = I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA); //Læser og gemmer læsningen i rawData
                    I2C_1_I2CMasterSendStop();
                    
                    if(rawData != 0xE5)errors++; //Hvis der læses andet end device ID, inkrementeres fejl. 
                    
                }
                else
                {
                    I2C_1_I2CMasterSendStop(); /* Send Stop */
                    errors++;
                }
            } 
            else 
            {
                errors++;
            }
        }
        else
        {
            I2C_1_I2CMasterSendStop(); /* Send Stop */
            errors++;
        }
        
    }
    
    char errorString[32];
    sprintf(errorString,  "Finished reading.\n\rErrors: %d\n\r\n", errors); //Gemmer antal errors i en string
    UART_1_UartPutString(errorString); //Udskriver hvor mange fejl. 
    char readingString[32];
    sprintf(readingString,  "Data from register: %d\n\r\n", rawData); // Gemmer rawData i som en string
    UART_1_UartPutString(readingString); //Udskriver hvad der står på rawData i UART
    while(1);
}

/* [] END OF FILE */