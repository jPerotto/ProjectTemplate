#ifndef _data_h
#define _data_h

#include <Arduino.h> //LIB PADRAO DO FRAMEWORK ARDUINO

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
} dataBase_t;

class dataBase
{
public:
    void setTemperaturaSensor(uint8_t temperatura);
    uint8_t getTemperaturaSensor(void);
    void setSensacaoTermica(uint8_t sensacaoTermica);
    uint8_t getSensacaoTermica(void);

protected:
    dataBase_t _dataBase;
};

#endif