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
#include "BTUART.h"
#include "Sensor.h"



char dataArray[MAXSENSDATA];     // Array with id-number and data to send via BT

void initUART()
{
    UART_1_Start();
}



void setdataArray(int ID, int x_data, int y_data, int z_data)
{
    int i;
    
    dataArray[0] = ID+1; 
    dataArray[1] = x_data+1;
    dataArray[2] = y_data+1;
    dataArray[3] = z_data+1;
    
    for(i = 4; i<MAXSENSDATA; i++) //Sætter de resterende pladser i array'et til 0. 
    {
        dataArray[i] = 1; 
    }
    
}


void sendDataArray()
{
    char accelArray[6];
    char gyroArray[6];
    char proxArray[6];
    char flexArray[6];
    // Sætter accelerometer array.
    accelArray[0] = START_SENSDATA;
    accelArray[1] = dataArray[0];   // ID 0
    accelArray[2] = dataArray[1];   // x
    accelArray[3] = dataArray[2];   // y
    accelArray[4] = dataArray[3];   // z
    accelArray[5] = 0; //Nul terminering 
    //Sætter gyroskop array
    gyroArray[0] = START_SENSDATA;
    gyroArray[1] = 1+1;             // ID 1
    gyroArray[2] = 1+1;               // x
    gyroArray[3] = 1+1;               // y
    gyroArray[4] = 1+1;               // z
    gyroArray[5] = 0; //Nul terminering
    //Sætter Proximity array
    proxArray[0] = START_SENSDATA;
    proxArray[1] = 2+1;             // ID 2
    proxArray[2] = 1+1;               // x
    proxArray[3] = 1+1;               // y
    proxArray[4] = 1+1;               // z
    proxArray[5] = 0; //Nul terminering
    //Sætter flex array
    flexArray[0] = START_SENSDATA;
    flexArray[1] = 3+1;             // ID 3
    flexArray[2] = 1+1;               // x
    flexArray[3] = 1+1;               // y
    flexArray[4] = 1+1;               // z
    flexArray[5] = 0; //Nul terminering
    
    
    
    CyDelay(3);
    UART_1_UartPutString(accelArray);
    CyDelay(3);
    //UART_1_UartPutString(gyroArray);
    CyDelay(3);
    //UART_1_UartPutString(proxArray);
    CyDelay(3);
    //UART_1_UartPutString(flexArray);
    
    //Error Check if I2C sensordata is valid
    if((dataArray[1] == 61)&&(dataArray[2] == 61)&&(dataArray[3] == 61))
    {
        ERRORPIN_Write(1);
    }
    
    //Reset dataArray to known acii value 48 = '0';
    int i;
    for(i = 0; i < MAXSENSDATA; i++)
    {
        dataArray[i] = 48;
    }
    
}



/* [] END OF FILE */
