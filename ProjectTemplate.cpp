#include "principais.h"

void setup()
{
  hardware.initPins();
  hardware.serialBegin();
  notify.ledNotify();

  taskLed.createTask(taskLed.taskCreate);

  Serial.println("SETUP OK");
}

void loop()
{
  sensor_hal.sensorTemperature();
  dataBase.setTemperaturaSensor(sensor_hal.getSensorValue());
  dataBase.setSensacaoTermica(sensor_hal.sensacaoTermica());

  Serial.printf("Sensor temperatura %d-%d\n", sensor_hal.getSensorValue(), dataBase.getTemperaturaSensor());
  Serial.printf("Sensacao %d-%d\n", sensor_hal.sensacaoTermica(), dataBase.getSensacaoTermica());
}
