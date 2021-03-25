#include "dataBase.h"

dataBase::dataBase()
{
}

dataBase::~dataBase()
{
}

void dataBase::inputDataToBase(const char *path, const char *message)
{
    Serial.printf("Insere em %s, dados %s", path, message);
}