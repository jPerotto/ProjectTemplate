#ifndef _sensor_hal_h
#define _sensor_hal_h

#include <Arduino.h>

enum sensacao_t
{
    FRIO = 10,
    ABAFADO = 25,
    QUENTE = 35
};

class sensor_hal
{
public:
    void sensorTemperature(void);
    uint8_t getSensorValue(void);
    uint8_t sensacaoTermica(void);

protected:
    uint8_t _valorSensor = NULL;
};

#endif
