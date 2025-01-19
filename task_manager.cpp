//
// Created by herbalchappal on 1/19/25.
//

#include "task_manager.h"

TaskManager::TaskManager ()
{
    vTasks = new Queue<tTask> ();
    vThreadPool = new ThreadPool (vMutex, vCond);

    pthread_mutex_init (&vMutex, nullptr);
    pthread_cond_init (&vCond, nullptr);
}

TaskManager::~TaskManager ()
{
    delete vTasks;
    delete vThreadPool;

    pthread_mutex_destroy (&vMutex);
    pthread_cond_destroy (&vCond);
}

void
TaskManager::Add (tTask & pTask)
{
    pthread_mutex_lock (&vMutex);
    vTasks->Enqueue (pTask);
    pthread_mutex_unlock (&vMutex);
    pthread_cond_signal (&vCond);
}

void
TaskManager::Execute ()
{
        tTask * curr_task;

    while (true) {

        pthread_mutex_lock (&vMutex);
        if (vTasks->IsEmpty ()) {
            pthread_cond_wait (&vCond, &vMutex);
        }

        curr_task = vTasks->Dequeue ();
        pthread_mutex_unlock (&vMutex);
    }
}

