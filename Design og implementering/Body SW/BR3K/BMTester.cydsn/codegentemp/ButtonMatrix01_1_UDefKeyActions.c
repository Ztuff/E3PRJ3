/* ========================================
 *
 * This file hold the user implementation
 * of the keyEvent function.
 * void KeyEvent(Key key, EventType et);
 * @param key
 *    This is an enumerated type refferencing
 *    Which key generated the event.
 * @param et
 *    An enumerated type indicating the type 
 *    of the event.
 * ========================================
*/

#include "ButtonMatrix01_1_API.h"
/* `#START UserIncludes` */
    #include "UART_SPI_UART.h"
    #include <stdio.h>
/* `#END` */

void _KeyEvent(ButtonMatrix01_1_Key_t key, ButtonMatrix01_1_EventType_t et)
{
    /* `#START UserCode` */
    char string[50];
    sprintf(string, "Key event: %d, Key: %d\n\r", et, key);
    UART_UartPutString(string);
    /* `#END` */ 
}

/* [] END OF FILE */
