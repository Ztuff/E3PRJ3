/* ========================================
 *
 * This module provides a very simple API
 * for a 3 by 4 button matrix. The only 
 * thing needed is adding the component in
 * your top-design, and define an implemen-
 * tation for the keyAction(Key key, 
 * EventType et) function which will be 
 * called when a button event is detected.
 *
 * ========================================
*/

#include "cytypes.h"
#include "cyfitter.h"
#include "ButtonMatrix01_1_BM_1.h"
#include "ButtonMatrix01_1_BM_2.h"
#include "ButtonMatrix01_1_BM_3.h"
#include "ButtonMatrix01_1_BM_4.h"
#include "ButtonMatrix01_1_BM_A.h"
#include "ButtonMatrix01_1_BM_B.h"
#include "ButtonMatrix01_1_BM_C.h"
#include "ButtonMatrix01_1_ISR_A.h"
#include "ButtonMatrix01_1_ISR_B.h"
#include "ButtonMatrix01_1_ISR_C.h"

//api types:
typedef enum ButtonMatrix01_1_Key_t 
{
    KEY_1 = 0,  KEY_2 = 1,  KEY_3 = 2, 
    KEY_4 = 3,  KEY_5 = 4,  KEY_6 = 5, 
    KEY_7 = 6,  KEY_8 = 7,  KEY_9 = 8, 
    KEY_A = 9,  KEY_0 = 10,  KEY_H = 11,       //A stands for Asterisk (*) and H for Hash (#)
    KEY_ANY = 12                    
} ButtonMatrix01_1_Key_t;

typedef enum ButtonMatrix01_1_EventType_t
{
    KEY_PRESS = 1, KEY_RELEASE = 0
} ButtonMatrix01_1_EventType_t;

typedef enum ButtonMatrix01_1_KeyState_t
{
    KEY_PRESSED, KEY_RELEASED
} ButtonMatrix01_1_KeyState_t;

//control functions:
void ButtonMatrix01_1_Start(void);
void ButtonMatrix01_1_Stop(void);
void ButtonMatrix01_1_Enable(void);      //This is automatically called when start is called.
void ButtonMatrix01_1_Disable(void);     //This is automatically called when stop is called.

//probing functions:
uint8_t ButtonMatrix01_1_IsButtonPressed(ButtonMatrix01_1_Key_t key);
uint8_t ButtonMatrix01_1_IsButtonReleased(ButtonMatrix01_1_Key_t key);
ButtonMatrix01_1_KeyState_t ButtonMatrix01_1_GetKeyState(ButtonMatrix01_1_Key_t key);

//User defined function
//Defined in UDefKeyActions.c
void _KeyEvent(ButtonMatrix01_1_Key_t key, ButtonMatrix01_1_EventType_t et);

//Internal variables


/* [] END OF FILE */
