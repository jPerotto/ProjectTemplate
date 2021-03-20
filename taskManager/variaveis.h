#ifndef _var_task_manage
#define _var_task_manage

enum taskManagerAction
{
  TASK_NSTART = 0,
  TASK_CREATE = 1,
  TASK_DELETE = 2,
  TASK_STOP = 3,
  TASK_RUN = 4,
  TASK_RESET = 5
};

enum taskManagerState
{
  TASK_OFF = false, //task nao active
  TASK_ON = true
};

#endif