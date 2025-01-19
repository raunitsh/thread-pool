#pragma once
#include "queue.hpp"
#include "thread_pool.h"
#include "types.h"

class TaskManager {

public:

                    TaskManager     ();
                    ~TaskManager    ();
    void            Add             (tTask & pTask);
    void            Execute         ();

private:

    Queue<tTask> *  vTasks;
    ThreadPool *    vThreadPool;
    pthread_mutex_t vMutex;
    pthread_cond_t  vCond;
};
