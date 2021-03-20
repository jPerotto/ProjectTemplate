#include "sensor_hal.h"

/**
 * @brief FAZ A LEITURA DO SENSOR FAKE E SALVA EM _valorSensor
*/
void sensor_hal::sensorTemperature(void)
{
  _valorSensor = random(0, 100);
}

/**
 * @brief REQUISTA O VALOR SALVO
 * @return RETORNA O VALOR SALVO EM _valorSensor
*/
uint8_t sensor_hal::getSensorValue(void)
{
  return _valorSensor;
}

/**
 * @brief CALCULA O TIPO DA TEMPERATURA E RETORNA O LIMITE DA \enum sensacao_t
 * @return O \enum RESPECTIVO
*/
uint8_t sensor_hal::sensacaoTermica(void)
{
  if ((_valorSensor > NULL) && (_valorSensor <= FRIO))
  {
    return (FRIO);
  }
  else if ((_valorSensor > FRIO) && (_valorSensor <= ABAFADO))
  {
    return (ABAFADO);
  }
  else if ((_valorSensor > ABAFADO) && (_valorSensor <= QUENTE))
  {
    return (QUENTE);
  }
  else
  {
    return NULL;
  }
}