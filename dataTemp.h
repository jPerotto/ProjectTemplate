#ifndef _data_h
#define _data_h

#include <Arduino.h> //LIB PADRAO DO FRAMEWORK ARDUINO

#define SEMI_COLON ";"
#define PATH_TEMPERATURE "/temperature.CSV"

/* ESTRUTURA DE DADOS PARA TEMPERATURAS */
typedef struct TEMPERATURA_DATA
{
    uint8_t temperaturaSensor = NULL;
    uint8_t sensacaoTermica = NULL;
} temperaturaData_t;

/* ESTRUTURA DE DADOS COM TODOS OS DADOS ARMAZENADOS */
typedef struct DATA_BASE
{
    temperaturaData_t temperaturaData;
} dataTemp_t;

class dataTemp
{
public:
    void setTemperaturaSensor(uint8_t temperatura);
    uint8_t getTemperaturaSensor(void);
    char *getStrDataTemperature(void);
    char *getPathTemp(void);

    void setSensacaoTermica(uint8_t sensacaoTermica);
    uint8_t getSensacaoTermica(void);

protected:
    dataTemp_t _dataBase;

private:
    void semiColon(String *data);
    void bufferingDataString(char *dataBufString, String *dataString);
};

#endif