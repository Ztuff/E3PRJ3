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

#define MAXREGNUM 96 //Maks antal registre at læse fra 
#define MAXSENSDATA 16 // Maks antal som skal fyldes i array'et som sendes via BT
#define DEFAULT_DATA -1 // Default data i array sættes til 0. 

//Sensor ID's 0-15
#define ACC1_ID 0
#define GYR1_ID 1
#define FLE1_ID 2
#define	PRX1_ID 3
#define ACC2_ID 4
#define GYR2_ID 5
#define FLE2_ID 6
#define	PRX2_ID 7
#define ACC3_ID 8
#define GYR3_ID 9
#define FLE3_ID 10
#define	PRX3_ID 11
#define ACC4_ID 12
#define GYR4_ID 13
#define FLE4_ID 14
#define	PRX4_ID 15

void setupI2C(void);
void setSensArray(int deviceAddress, int registerToRead, int dataTarget);
void readAllSensors(void);
void convSensData(void);
void readI2C(int numOfReg);
void handleI2CError(void);




/* [] END OF FILE */
