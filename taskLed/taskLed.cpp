#include "taskLed.h"

taskLed::taskLed(managerTask taskManager, CALLBACK_SIGNATURE)
{
    *taskInfo = managerTask::TaskManager_t{callback, "doLedTask", 8192, (void *)this, 1, &_taskHandle, APP_CPU_NUM, TASK_CREATE, TASK_OFF, NULL};
    _taskManager = taskManager;
}

taskLed::~taskLed()
{
}

void doLedTask(void *parameter)
{
    do
    {
        taskLed *ledTask = (taskLed *)parameter;
        ledTask->_taskManager.checkIntegrityFirmware(ledTask->taskInfo->pcName);
    } while (true);
}
