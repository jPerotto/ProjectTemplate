#include "taskManager.h"

managerTask::managerTask(CALLBACK_SIGNATURE)
{
    _nTask = NULL;
    _taskManager = new TaskManager_t;
    *_taskManager = TaskManager_t{callback, "doManagerTask", 4096, NULL, 3, NULL, APP_CPU_NUM, TASK_CREATE, TASK_OFF, NULL};
    this->inicializeTask(_taskManager);
}

managerTask::~managerTask()
{
}

void managerTask::createTask(TaskManager_t *taskInfo)
{
    TaskManager_t *temp = new TaskManager_t[_nTask];
    for (uint8_t xTask = 0; xTask < _nTask; xTask++)
    {
        temp[xTask] = _taskManager[xTask];
    }
    _nTask++;

    delete[] _taskManager;
    _taskManager = temp;
    _taskManager[_nTask - 1] = *taskInfo;
    this->inicializeTask(taskInfo);
}

void managerTask::inicializeTask(TaskManager_t *taskInfo)
{
    startTask(xTaskCreatePinnedToCore(
                  taskInfo->pvTaskCode,
                  taskInfo->pcName,
                  taskInfo->usStackDepth,
                  taskInfo->pvParameters,
                  taskInfo->uxPriority,
                  taskInfo->xHandleTask,
                  taskInfo->xCoreID),
              taskInfo->pcName);
}

void managerTask::checkIntegrityFirmware(const char *nameFunction)
{
    if (heap_caps_check_integrity_all(true) == false)
    {
        // LOGd_TASK("freeHeap %d minFreeHeap %d", xPortGetFreeHeapSize(), xPortGetMinimumEverFreeHeapSize());
        // LOGd_TASK("Encontrou um erro em %s", nameFunction);
    }
}

void managerTask::startTask(int8_t err, const char *taskName)
{
    if (err != pdTRUE)
    {
        // LOGe_TASK("%s FAIL %d FreeRam %s", task, err, String(ESP.getFreeHeap()).c_str());
        // log_spiffs("%d;%s", LOG_ERRO_START_TASK, task);
        // log_sd("%d;%s", LOG_ERRO_START_TASK, task);
        esp_restart();
    }
    else
    {
        // LOGd_TASK("%s created %d FreeRam %s", task, err, String(ESP.getFreeHeap()).c_str());
        checkIntegrityFirmware(taskName);
    }
}

void doManagerTask(void *parameter)
{
    do
    {
    } while (true);
}