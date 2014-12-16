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


#define START_SENSDATA 0x0F // Start byte, 


void initUART(void);
void setdataArray(uint8 ID, uint8 x_data, uint8 y_data, uint8 z_data);
void sendDataArray(void);




/* [] END OF FILE */
