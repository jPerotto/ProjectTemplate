#ifndef _task_led
#define _task_led

#include <Arduino.h>
#include <FreeRTOS.h>
#include "../taskManager/taskManager.h"

void doLedTask(void *parameter);

class taskLed : public managerTask
{
public:
    taskLed(CALLBACK_SIGNATURE = doLedTask);
    ~taskLed();
    managerTask::TaskManager_t taskCreate;

private:
    TaskHandle_t _taskHandle = NULL;
};

#endif