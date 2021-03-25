#ifndef _xQueue_h
#define _xQueue_h

#include "principais.h"
#include "Arduino.h"
#include <FreeRTOS.h>

template <class dataQueue>
class xQueue
{
public:
    xQueue();
    ~xQueue();

    bool sendMsgTask(const char *msg, dataQueue dataSend);
    dataQueue recMsgTask();

    // QueueHandle_t xQueue_task = NULL;
};

#endif