#ifndef _principais_h
#define _principais_h

#include <Arduino.h> //LIB PADRAO DO FRAMEWORK ARDUINO
#include "dataTemp.h"
#include "sensor_hal.h"
#include "hardwareInit.hpp"
#include "notification.hpp"
#include "taskManager/taskManager.h"
#include "taskLed/taskLed.h"
#include "dataBase/dataBase.h"
// #include "key.h" //BIBLIOTECA PARA GERENCIAR FILA DA IRRIGACAO

dataTemp dataTemp;
dataBase dataBase;
sensor_hal sensor_hal;
hardware hardware;
notify notify;
managerTask managerTask;
taskLed taskLed(managerTask);
// Key key; //CONTROLE DE FILA DE AGENDAMENTO

#endif