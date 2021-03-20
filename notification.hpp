#ifndef _notify_H
#define _notify_H

#include "hardwareInit.hpp"
#define TIME_DELAY_LED 1000 /* TEMPO DE DELAY */

class notify
{
public:
    void ledNotify(void)
    {
        digitalWrite(LED_BUILTIN, LED_ON);
        delay(TIME_DELAY_LED);
        digitalWrite(LED_BUILTIN, LED_OFF);
        delay(TIME_DELAY_LED);
    }
};

#endif