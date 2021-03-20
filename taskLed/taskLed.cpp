#include "taskLed.h"

taskLed::taskLed(CALLBACK_SIGNATURE)
{
    taskCreate = managerTask::TaskManager_t{callback, "doLedTask", 8192, NULL, 1, &_taskHandle, APP_CPU_NUM, TASK_CREATE, TASK_OFF, NULL};
}

taskLed::~taskLed() 
{
}

void doLedTask(void *parameter)
{
    do
    {
    } while (true);
}
