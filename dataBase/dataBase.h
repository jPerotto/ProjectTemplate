#ifndef _data_base_h
#define _data_base_h

#include <Arduino.h>

// template <class FS_TYPE>
class dataBase
{
public:
    dataBase();
    ~dataBase();
    void inputDataToBase(const char *path, const char *message);
};

#endif