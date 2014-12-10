/* ========================================
 *
 * This file holds the implementation of
 * the ButtonMatrix API
 *
 * ========================================
*/

#include "`$INSTANCE_NAME`_API.h"

uint8_t `$INSTANCE_NAME`_keyStates[4][3] = 
{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

CY_ISR_PROTO(`$INSTANCE_NAME`_ColumnAISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_ColumnBISR);
CY_ISR_PROTO(`$INSTANCE_NAME`_ColumnCISR);

//control functions:
void `$INSTANCE_NAME`_Start(void)
{
    `$INSTANCE_NAME`_ISR_A_StartEx(`$INSTANCE_NAME`_ColumnAISR);
    `$INSTANCE_NAME`_ISR_B_StartEx(`$INSTANCE_NAME`_ColumnBISR);
    `$INSTANCE_NAME`_ISR_C_StartEx(`$INSTANCE_NAME`_ColumnCISR);
}
void `$INSTANCE_NAME`_Stop(void)
{
    `$INSTANCE_NAME`_ISR_A_Stop();
    `$INSTANCE_NAME`_ISR_B_Stop();
    `$INSTANCE_NAME`_ISR_C_Stop();
}
void `$INSTANCE_NAME`_Enable(void)
{
    `$INSTANCE_NAME`_ISR_A_Enable();
    `$INSTANCE_NAME`_ISR_B_Enable();
    `$INSTANCE_NAME`_ISR_C_Enable();
}
void `$INSTANCE_NAME`_Disable(void)
{
    `$INSTANCE_NAME`_ISR_A_Disable();
    `$INSTANCE_NAME`_ISR_B_Disable();
    `$INSTANCE_NAME`_ISR_C_Disable();
}

//probing functions:
uint8_t `$INSTANCE_NAME`_IsButtonPressed(`$INSTANCE_NAME`_Key_t key)
{
    return `$INSTANCE_NAME`_keyStates[key / 3][key % 3];
}

uint8_t `$INSTANCE_NAME`_IsButtonReleased(`$INSTANCE_NAME`_Key_t key)
{
     return !`$INSTANCE_NAME`_keyStates[key / 3][key % 3];
}

`$INSTANCE_NAME`_KeyState_t `$INSTANCE_NAME`_GetKeyState(`$INSTANCE_NAME`_Key_t key)
{
    if(`$INSTANCE_NAME`_keyStates[key / 3][key % 3]) return KEY_PRESSED;
    else return KEY_RELEASED;
}

//ISR functionality 
uint8_t `$INSTANCE_NAME`_readColumn(uint8_t column)
{
    switch(column)
    {
        case 0:
            return `$INSTANCE_NAME`_BM_A_Read();
        case 1:
            return `$INSTANCE_NAME`_BM_B_Read();
        case 2:
            return `$INSTANCE_NAME`_BM_C_Read();
        default:
            return -1;
    }
}

uint8_t `$INSTANCE_NAME`_scanForRow(uint8_t column)
{
    uint8_t row = 0;
    
    `$INSTANCE_NAME`_Disable();
    `$INSTANCE_NAME`_BM_1_Write(1);
    if(`$INSTANCE_NAME`_readColumn(column)) row = 0;
    `$INSTANCE_NAME`_BM_1_Write(0);
    
    `$INSTANCE_NAME`_BM_2_Write(1);
    if(`$INSTANCE_NAME`_readColumn(column)) row = 1;
    `$INSTANCE_NAME`_BM_2_Write(0);
    
    `$INSTANCE_NAME`_BM_3_Write(1);
    if(`$INSTANCE_NAME`_readColumn(column)) row = 2;
    `$INSTANCE_NAME`_BM_3_Write(0);
    
    `$INSTANCE_NAME`_BM_4_Write(1);
    if(`$INSTANCE_NAME`_readColumn(column)) row = 3;
    `$INSTANCE_NAME`_BM_4_Write(0);
    `$INSTANCE_NAME`_Enable();
    return row;
} 

void `$INSTANCE_NAME`_handleInterrupt(uint8_t column)
{
    `$INSTANCE_NAME`_Key_t key;
    `$INSTANCE_NAME`_EventType_t et;
    uint8_t row = 0;
    
    if(!`$INSTANCE_NAME`_readColumn(column)){
        et = KEY_PRESS;
        row = `$INSTANCE_NAME`_scanForRow(column);
        `$INSTANCE_NAME`_keyStates[row][column] = 1;
    }else{
        et = KEY_RELEASE;
        uint8_t i;
        for(i = 0; i < 4; i++){
            if(`$INSTANCE_NAME`_keyStates[i][column] != 0){
                `$INSTANCE_NAME`_keyStates[i][column] = 0;
                row = i;
            }
        }
    }
    key = row * 3 + column;
    `$INSTAMCE_NAME`_KeyEvent(key, et);
}

CY_ISR(`$INSTANCE_NAME`_ColumnAISR)
{
    `$INSTANCE_NAME`_handleInterrupt(0);
    `$INSTANCE_NAME`_BM_A_ClearInterrupt();
}

CY_ISR(`$INSTANCE_NAME`_ColumnBISR)
{
    `$INSTANCE_NAME`_handleInterrupt(1);
    `$INSTANCE_NAME`_BM_B_ClearInterrupt();
}

CY_ISR(`$INSTANCE_NAME`_ColumnCISR)
{
    `$INSTANCE_NAME`_handleInterrupt(2);
    `$INSTANCE_NAME`_BM_C_ClearInterrupt();
}

/* [] END OF FILE */

