/* ========================================
 *
 * This file holds the implementation of
 * the ButtonMatrix API
 *
 * ========================================
*/

#include "ButtonMatrix01_1_API.h"

uint8_t ButtonMatrix01_1_keyStates[4][3] = 
{
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};

CY_ISR_PROTO(ButtonMatrix01_1_ColumnAISR);
CY_ISR_PROTO(ButtonMatrix01_1_ColumnBISR);
CY_ISR_PROTO(ButtonMatrix01_1_ColumnCISR);

//control functions:
void ButtonMatrix01_1_Start(void)
{
    ButtonMatrix01_1_ISR_A_StartEx(ButtonMatrix01_1_ColumnAISR);
    ButtonMatrix01_1_ISR_B_StartEx(ButtonMatrix01_1_ColumnBISR);
    ButtonMatrix01_1_ISR_C_StartEx(ButtonMatrix01_1_ColumnCISR);
}
void ButtonMatrix01_1_Stop(void)
{
    ButtonMatrix01_1_ISR_A_Stop();
    ButtonMatrix01_1_ISR_B_Stop();
    ButtonMatrix01_1_ISR_C_Stop();
}
void ButtonMatrix01_1_Enable(void)
{
    ButtonMatrix01_1_ISR_A_Enable();
    ButtonMatrix01_1_ISR_B_Enable();
    ButtonMatrix01_1_ISR_C_Enable();
}
void ButtonMatrix01_1_Disable(void)
{
    ButtonMatrix01_1_ISR_A_Disable();
    ButtonMatrix01_1_ISR_B_Disable();
    ButtonMatrix01_1_ISR_C_Disable();
}

//probing functions:
uint8_t ButtonMatrix01_1_IsButtonPressed(ButtonMatrix01_1_Key_t key)
{
    return ButtonMatrix01_1_keyStates[key / 3][key % 3];
}

uint8_t ButtonMatrix01_1_IsButtonReleased(ButtonMatrix01_1_Key_t key)
{
     return !ButtonMatrix01_1_keyStates[key / 3][key % 3];
}

ButtonMatrix01_1_KeyState_t ButtonMatrix01_1_GetKeyState(ButtonMatrix01_1_Key_t key)
{
    if(ButtonMatrix01_1_keyStates[key / 3][key % 3]) return KEY_PRESSED;
    else return KEY_RELEASED;
}

//ISR functionality 
uint8_t ButtonMatrix01_1_readColumn(uint8_t column)
{
    switch(column)
    {
        case 0:
            return ButtonMatrix01_1_BM_A_Read();
        case 1:
            return ButtonMatrix01_1_BM_B_Read();
        case 2:
            return ButtonMatrix01_1_BM_C_Read();
        default:
            return -1;
    }
}

uint8_t ButtonMatrix01_1_scanForRow(uint8_t column)
{
    uint8_t row = 0;
    
    ButtonMatrix01_1_Disable();
    ButtonMatrix01_1_BM_1_Write(1);
    if(ButtonMatrix01_1_readColumn(column)) row = 0;
    ButtonMatrix01_1_BM_1_Write(0);
    
    ButtonMatrix01_1_BM_2_Write(1);
    if(ButtonMatrix01_1_readColumn(column)) row = 1;
    ButtonMatrix01_1_BM_2_Write(0);
    
    ButtonMatrix01_1_BM_3_Write(1);
    if(ButtonMatrix01_1_readColumn(column)) row = 2;
    ButtonMatrix01_1_BM_3_Write(0);
    
    ButtonMatrix01_1_BM_4_Write(1);
    if(ButtonMatrix01_1_readColumn(column)) row = 3;
    ButtonMatrix01_1_BM_4_Write(0);
    ButtonMatrix01_1_Enable();
    return row;
} 

void ButtonMatrix01_1_handleInterrupt(uint8_t column)
{
    ButtonMatrix01_1_Key_t key;
    ButtonMatrix01_1_EventType_t et;
    uint8_t row = 0;
    
    if(!ButtonMatrix01_1_readColumn(column)){
        et = KEY_PRESS;
        row = ButtonMatrix01_1_scanForRow(column);
        ButtonMatrix01_1_keyStates[row][column] = 1;
    }else{
        et = KEY_RELEASE;
        uint8_t i;
        for(i = 0; i < 4; i++){
            if(ButtonMatrix01_1_keyStates[i][column] != 0){
                ButtonMatrix01_1_keyStates[i][column] = 0;
                row = i;
            }
        }
    }
    key = row * 3 + column;
    _KeyEvent(key, et);
}

CY_ISR(ButtonMatrix01_1_ColumnAISR)
{
    ButtonMatrix01_1_handleInterrupt(0);
    ButtonMatrix01_1_BM_A_ClearInterrupt();
}

CY_ISR(ButtonMatrix01_1_ColumnBISR)
{
    ButtonMatrix01_1_handleInterrupt(1);
    ButtonMatrix01_1_BM_B_ClearInterrupt();
}

CY_ISR(ButtonMatrix01_1_ColumnCISR)
{
    ButtonMatrix01_1_handleInterrupt(2);
    ButtonMatrix01_1_BM_C_ClearInterrupt();
}

/* [] END OF FILE */

