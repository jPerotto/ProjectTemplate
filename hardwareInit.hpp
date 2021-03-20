#ifndef _pin_hw_h
#define _pin_hw_h

#include <Arduino.h>

#define LED_BUILTIN 13      /* PINO DO LED */
#define BAUND_RATE 115200   /* VELOCIDADE DE COMUNICACAO EM bps */
#define LED_ON HIGH         /* ESTADO DO LED LIGADO */
#define LED_OFF LOW         /* ESTADO DO LED DESLIGADO */

class hardware
{
public:
    void initPins(void)
    {
        pinMode(LED_BUILTIN, OUTPUT);
    }

    void serialBegin(void)
    {
        Serial.begin(BAUND_RATE);
    }
};

#endif