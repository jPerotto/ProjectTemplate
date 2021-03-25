#include "principais.h"

void setup()
{
  hardware.initPins();
  hardware.serialBegin();
  notify.ledNotify();

  managerTask.createTask(taskLed.taskInfo);

  Serial.println("SETUP OK");
}

void loop()
{
  sensor_hal.updateSensor();
  dataTemp.setTemperaturaSensor(sensor_hal.getSensorValue());
  dataTemp.setSensacaoTermica(sensor_hal.sensacaoTermica());

  dataBase.inputDataToBase(dataTemp.getPathTemp(), dataTemp.getStrDataTemperature());

  Serial.printf("Sensor temperatura %d-%d\n", sensor_hal.getSensorValue(), dataTemp.getTemperaturaSensor());
  Serial.printf("Sensacao %d-%d\n", sensor_hal.sensacaoTermica(), dataTemp.getSensacaoTermica());
}
