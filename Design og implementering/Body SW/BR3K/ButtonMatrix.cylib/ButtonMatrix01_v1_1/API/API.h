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
#include "`$INSTANCE_NAME`_BM_1.h"
#include "`$INSTANCE_NAME`_BM_2.h"
#include "`$INSTANCE_NAME`_BM_3.h"
#include "`$INSTANCE_NAME`_BM_4.h"
#include "`$INSTANCE_NAME`_BM_A.h"
#include "`$INSTANCE_NAME`_BM_B.h"
#include "`$INSTANCE_NAME`_BM_C.h"
#include "`$INSTANCE_NAME`_ISR_A.h"
#include "`$INSTANCE_NAME`_ISR_B.h"
#include "`$INSTANCE_NAME`_ISR_C.h"

//api types:
typedef enum `$INSTANCE_NAME`_Key_t 
{
    KEY_1 = 0,  KEY_2 = 1,  KEY_3 = 2, 
    KEY_4 = 3,  KEY_5 = 4,  KEY_6 = 5, 
    KEY_7 = 6,  KEY_8 = 7,  KEY_9 = 8, 
    KEY_A = 9,  KEY_0 = 10,  KEY_H = 11,       //A stands for Asterisk (*) and H for Hash (#)
    KEY_ANY = 12                    
} `$INSTANCE_NAME`_Key_t;

typedef enum `$INSTANCE_NAME`_EventType_t
{
    KEY_PRESS = 1, KEY_RELEASE = 0
} `$INSTANCE_NAME`_EventType_t;

typedef enum `$INSTANCE_NAME`_KeyState_t
{
    KEY_PRESSED, KEY_RELEASED
} `$INSTANCE_NAME`_KeyState_t;

//control functions:
void `$INSTANCE_NAME`_Start(void);
void `$INSTANCE_NAME`_Stop(void);
void `$INSTANCE_NAME`_Enable(void);      //This is automatically called when start is called.
void `$INSTANCE_NAME`_Disable(void);     //This is automatically called when stop is called.

//probing functions:
uint8_t `$INSTANCE_NAME`_IsButtonPressed(`$INSTANCE_NAME`_Key_t key);
uint8_t `$INSTANCE_NAME`_IsButtonReleased(`$INSTANCE_NAME`_Key_t key);
`$INSTANCE_NAME`_KeyState_t `$INSTANCE_NAME`_GetKeyState(`$INSTANCE_NAME`_Key_t key);

//User defined function
//Defined in UDefKeyActions.c
void `$INSTAMCE_NAME`_KeyEvent(`$INSTANCE_NAME`_Key_t key, `$INSTANCE_NAME`_EventType_t et);

//Internal variables


/* [] END OF FILE */
