#pragma once
#include "queue.hpp"
#include "thread_pool.h"
#include "types.h"

class TaskManager {

public:
                            TaskManager     ();
                            ~TaskManager    ();
            
            void            ExecuteAsync    (tTask & pTask);

private:
static      void *          ExecuteTask     (void * pArgs);

static      Queue<tTask> *  vTasks;
            ThreadPool *    vThreadPool;
static      pthread_mutex_t vQueueMutex;
static      pthread_cond_t  vQueueCond;
};
