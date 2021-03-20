#include "taskManager.h"

managerTask::managerTask()
{
    _nTask = NULL;
    // _taskManager = new TaskManager_t[_nTask];
}

managerTask::~managerTask()
{
}

void managerTask::createTask(TaskManager_t taskCreate)
{
    TaskManager_t *temp = new TaskManager_t[_nTask];
    for (uint8_t xTask = 0; xTask < _nTask; xTask++)
    {
        temp[xTask] = _taskManager[xTask];
    }
    _nTask++;

    delete[] _taskManager;
    _taskManager = temp;
    _taskManager[_nTask-1] = taskCreate;
    startTask(xTaskCreatePinnedToCore(
        taskCreate.pvTaskCode,
        taskCreate.pcName,
        taskCreate.usStackDepth,
        taskCreate.pvParameters,
        taskCreate.uxPriority,
        taskCreate.xHandleTask,
        taskCreate.xCoreID),
        taskCreate.pcName);
}

void managerTask::checkIntegrityFirmware(const char *nameFunction)
{
    if (heap_caps_check_integrity_all(true) == false)
    {
        // LOGd_TASK("freeHeap %d minFreeHeap %d", xPortGetFreeHeapSize(), xPortGetMinimumEverFreeHeapSize());
        // LOGd_TASK("Encontrou um erro em %s", nameFunction);
    }
}

void managerTask::startTask(int8_t err, const char *task)
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
        checkIntegrityFirmware(task);
    }
}
