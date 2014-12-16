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
#include "SerialUnit.h"
#include "Sensor.h"


// Klasse-lokalt array
char dataArray[MAXSENSDATA];     // Array with id-number and data to send via BT

void initUART()
{
    // Enable og initier UART komponenten
    UART_1_Start();
}



void setdataArray(uint8 ID, uint8 x_data, uint8 y_data, uint8 z_data)
{
    // // Klasse-lokale dataarray til ID, x_data, y_data, z_data
    dataArray[0] = ID+1; 
    dataArray[1] = x_data+1;
    dataArray[2] = y_data+1;
    dataArray[3] = z_data+1;
    
    //Sætter de resterende pladser i array'et til 1.
    int i;
    for(i = 4; i<MAXSENSDATA; i++)  
    {
        dataArray[i] = 1; 
    }
    
}


void sendDataArray()
{
    // Opret et array med seks pladser pr sensor 
    char accelArray[6];
    char gyroArray[6];
    char proxArray[6];
    char flexArray[6];
    
    // Sætter accelerometer array.
    accelArray[0] = START_SENSDATA;
    accelArray[1] = dataArray[0];   // dataArray[0] - ID 0
    accelArray[2] = dataArray[1];   // dataArray[1] - x
    accelArray[3] = dataArray[2];   // dataArray[2] - y
    accelArray[4] = dataArray[3];   // dataArray[3] - z
    accelArray[5] = 0;              // Nul terminering 
    
    // Sætter gyroskop array
    gyroArray[0] = START_SENSDATA;
    gyroArray[1] = 1+1;             // dataArray[4] - ID 1
    gyroArray[2] = 1+1;             // dataArray[5] - x
    gyroArray[3] = 1+1;             // dataArray[6] - y
    gyroArray[4] = 1+1;             // dataArray[7] - z
    gyroArray[5] = 0;               // Nul terminering
    
    // Sætter Proximity array
    proxArray[0] = START_SENSDATA;
    proxArray[1] = 2+1;             // dataArray[8]  - ID 2
    proxArray[2] = 1+1;             // dataArray[9]  - x
    proxArray[3] = 1+1;             // dataArray[10] - y
    proxArray[4] = 1+1;             // dataArray[11] - z
    proxArray[5] = 0;               // Nul terminering
    
    // Sætter flex array
    flexArray[0] = START_SENSDATA;
    flexArray[1] = 3+1;             // dataArray[12] - ID 3
    flexArray[2] = 1+1;             // dataArray[13] - x
    flexArray[3] = 1+1;             // dataArray[14] - y
    flexArray[4] = 1+1;             // dataArray[15] - z
    flexArray[5] = 0;               // Nul terminering
    
    
    
    
    // Send sensordata
    //CyDelay(3);
    UART_1_UartPutString(accelArray);
    //CyDelay(3);
    //UART_1_UartPutString(gyroArray);
    //CyDelay(3);
    //UART_1_UartPutString(proxArray);
    //CyDelay(3);
    //UART_1_UartPutString(flexArray);
    
    //Error Check om I2C sensordata er valid
    if((dataArray[1] == 65)&&(dataArray[2] == 65)&&(dataArray[3] == 65))
    {
        ERRORPIN_Write(1);
    }
    
    //Reset dataArray til kendt acii værdier 48 = '0';
    int i;
    for(i = 0; i < MAXSENSDATA; i++)
    {
        dataArray[i] = 48;
    }
    
}



/* [] END OF FILE */
