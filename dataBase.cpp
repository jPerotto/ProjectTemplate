#include "dataBase.h"

/**
 * @brief SETAR A TEMPERATURA DO SENSOR
 * @param temperaturaSensor TEMPERATURA QUE SERA COLOCADA NO DATABASE
*/
void dataBase::setTemperaturaSensor(uint8_t temperaturaSensor)
{
    _dataBase.temperaturaData.temperaturaSensor = temperaturaSensor;
}

/**
 * @brief RECUPERAR A TEMPERATURA DO SENSOR
 * @return RETORNA A TEMPERATURA DO DATABASE
*/
uint8_t dataBase::getTemperaturaSensor(void)
{
    return _dataBase.temperaturaData.temperaturaSensor;
}

/**
 * @brief SETAR A SENSACAO TERMICA DO SENSOR
 * @param sensacaoTermica SENSACAO QUE SERA COLOCADA NO DATABASE
*/
void dataBase::setSensacaoTermica(uint8_t sensacaoTermica)
{
    _dataBase.temperaturaData.sensacaoTermica = sensacaoTermica;
}

/**
 * @brief RECUPERAR A SENSACAO DO SENSOR
 * @return RETORNA A SENSACAO DO DATABASE
*/
uint8_t dataBase::getSensacaoTermica(void)
{
    return _dataBase.temperaturaData.sensacaoTermica;
}
