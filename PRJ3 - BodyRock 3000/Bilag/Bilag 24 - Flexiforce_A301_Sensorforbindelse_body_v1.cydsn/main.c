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

#define FLEXI_ADDRESS 2
#define X0_REG 0x00
#define PWR_CTRL_REG 0x2D
#define PWR_MODE (1<<3)
uint8 rawData;

// PROGRAM sat op til 10 Reads med udskrift af data
int main()
{
    UART_1_Start();
    UART_1_UartPutString("\n\rI2C_Slave Flexiforce 301A connected\n\r");
    I2C_1_Start(); 
    I2C_1_I2CMasterClearStatus();
    char dataString[4]; 
    
    if(I2C_1_I2CMasterSendStart(FLEXI_ADDRESS, I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR
        && I2C_1_I2CMasterWriteByte(PWR_CTRL_REG) == I2C_1_I2C_MSTR_NO_ERROR
        && I2C_1_I2CMasterWriteByte(PWR_MODE) == I2C_1_I2C_MSTR_NO_ERROR) 
    UART_1_UartPutString("\n\rFlexiforce initialized.\n\r");
    UART_1_UartPutString("\n\r10 reads will now be performed.\nPlease wait.\n\r");
    
    I2C_1_I2CMasterSendStop();
    int errors = 0;
    int i;
    for(i = 0; i < 10; i++){
        if (I2C_1_I2CMasterSendStart(FLEXI_ADDRESS, I2C_1_I2C_WRITE_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR) /* Check if transfer completed without errors */
        { 
          
            if(I2C_1_I2CMasterWriteByte(X0_REG) == I2C_1_I2C_MSTR_NO_ERROR)
            {
                
                if(I2C_1_I2CMasterSendRestart(FLEXI_ADDRESS, I2C_1_I2C_READ_XFER_MODE) == I2C_1_I2C_MSTR_NO_ERROR)
                {
                    rawData = I2C_1_I2CMasterReadByte(I2C_1_I2C_NAK_DATA);
                    I2C_1_I2CMasterSendStop();
                    
                    char rawDataTest[32];
                    sprintf(rawDataTest,  "\n\rRawData: %d\n\r", rawData);
                    UART_1_UartPutString(rawDataTest);
                    
                  if((rawData != 4)&&(rawData !=11)&&(rawData !=22))errors++;
                    
                }else{
                    I2C_1_I2CMasterSendStop(); /* Send Stop */
                    errors++;
                    //UART_1_UartPutString("\n\rElse stop\n\r");
                }
            } else {
                errors++;
                UART_1_UartPutString("\n\rerroes++\n\r");
            }
        }
        else
        {
            I2C_1_I2CMasterSendStop(); /* Send Stop */
            errors++;
            
        }
        
    }
    char errorString[67];
    sprintf(errorString,  "Finished reading.\nErrors: %d\n", errors);
    UART_1_UartPutString(errorString);
    while(1);
}

/* [] END OF FILE */
