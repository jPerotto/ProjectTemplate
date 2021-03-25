#include "dataTemp.h"

/**
 * @brief SETAR A TEMPERATURA DO SENSOR
 * @param temperaturaSensor TEMPERATURA QUE SERA COLOCADA NO DATABASE
*/
void dataTemp::setTemperaturaSensor(uint8_t temperaturaSensor)
{
    _dataBase.temperaturaData.temperaturaSensor = temperaturaSensor;
}

/**
 * @brief RECUPERAR A TEMPERATURA DO SENSOR
 * @return RETORNA A TEMPERATURA DO DATABASE
*/
uint8_t dataTemp::getTemperaturaSensor(void)
{
    return _dataBase.temperaturaData.temperaturaSensor;
}

char *dataTemp::getStrDataTemperature(void)
{
    String *data;
    data->concat(_dataBase.temperaturaData.temperaturaSensor);
    this->semiColon(data);
    data->concat(_dataBase.temperaturaData.sensacaoTermica);

    char bufData[data->length() + 1] = {NULL};
    this->bufferingDataString(bufData, data);

    return bufData;
}

char *dataTemp::getPathTemp(void)
{
    return PATH_TEMPERATURE;
}

void dataTemp::semiColon(String *data)
{
    data->concat(SEMI_COLON);
}

void dataTemp::bufferingDataString(char *dataBufString, String *dataString)
{
    dataString->toCharArray(dataBufString, dataString->length() + 1);
}

/**
 * @brief SETAR A SENSACAO TERMICA DO SENSOR
 * @param sensacaoTermica SENSACAO QUE SERA COLOCADA NO DATABASE
*/
void dataTemp::setSensacaoTermica(uint8_t sensacaoTermica)
{
    _dataBase.temperaturaData.sensacaoTermica = sensacaoTermica;
}

/**
 * @brief RECUPERAR A SENSACAO DO SENSOR
 * @return RETORNA A SENSACAO DO DATABASE
*/
uint8_t dataTemp::getSensacaoTermica(void)
{
    return _dataBase.temperaturaData.sensacaoTermica;
}
