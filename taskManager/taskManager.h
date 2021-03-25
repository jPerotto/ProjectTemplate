#ifndef _task_manager_h
#define _task_manager_h

#include <Arduino.h> //LIB PADRAO DO FRAMEWORK ARDUINO
#include <FreeRTOS.h>
#include "variaveis.h"

#define CALLBACK_SIGNATURE void (*callback)(void *parameter)
void doManagerTask(void *parameter);

class managerTask
{
public:
    typedef struct
    {
        TaskFunction_t pvTaskCode;
        char *pcName;
        uint32_t usStackDepth;
        void *pvParameters;
        UBaseType_t uxPriority;
        TaskHandle_t *xHandleTask;
        BaseType_t xCoreID;
        uint8_t command;
        bool state;
        uint32_t lastTimeResetWDT;
    } TaskManager_t;

    managerTask(CALLBACK_SIGNATURE = doManagerTask);
    ~managerTask();
    void createTask(TaskManager_t *taskInfo);
    void inicializeTask(TaskManager_t *taskInfo);
    void startTask(int8_t err, const char *task);
    void checkIntegrityFirmware(const char *nameFunction);

private:
    uint8_t _nTask;
    TaskManager_t *_taskManager;
};

#endif