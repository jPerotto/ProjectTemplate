#include "xQueue.h"

template <class dataQueue>
xQueue<dataQueue>::xQueue()
{
    // xQueue_task =  xQueueCreate(nQueue, sizeof(dataQueue));
}

template <class dataQueue>
xQueue<dataQueue>::~xQueue()
{
    // xQueue_task =  xQueueCreate(nQueue, sizeof(dataQueue));
}

template <class dataQueue>
bool xQueue<dataQueue>::sendMsgTask(const char *msg, dataQueue dataSend)
{
    // if (xQueueSend(xQueue_task, (void *)&dataSend, (TickType_t)TIME_QUEUE_ERROR) == pdTRUE)
    // {

    // }
}

template <class dataQueue>
dataQueue xQueue<dataQueue>::recMsgTask()
{
    dataQueue retData;
    // if (xQueueReceive(xQueue_sync_data, &(retData), (TickType_t)TIME_QUEUE_ERROR) == pdFALSE)
    // {

    // }
    return retData;
}