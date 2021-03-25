#ifndef _task_led
#define _task_led

#include <Arduino.h>
#include <FreeRTOS.h>
#include "../taskManager/taskManager.h"
#include "../xQueueTask/xQueue.h"

void doLedTask(void *parameter);

typedef struct
{
    bool x = NULL;
} dataA_t;

typedef struct
{
    bool x = NULL;
} dataB_t;

class taskLed : public managerTask
{
public:
    taskLed(managerTask taskManager, CALLBACK_SIGNATURE = doLedTask);
    ~taskLed();
    managerTask::TaskManager_t *taskInfo;
    managerTask _taskManager;

protected:
    TaskHandle_t _taskHandle = NULL;

private:
    xQueue<dataA_t> interfaceA();
    xQueue<dataB_t> interfaceB();
};

#endif