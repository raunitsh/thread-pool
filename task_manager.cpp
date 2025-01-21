#include "task_manager.h"

pthread_mutex_t TaskManager::vQueueMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  TaskManager::vQueueCond  = PTHREAD_COND_INITIALIZER;

Queue<tTask> * TaskManager::vTasks = new Queue<tTask> ();

void *
TaskManager::ExecuteTask (void * pArgs)
{
        tTask * task;
    
    while (true) {
        
        pthread_mutex_lock (&vQueueMutex);
        
        while (vTasks->IsEmpty ())
            pthread_cond_wait (&vQueueCond, &vQueueMutex);
        
        task = vTasks->Dequeue ();
        pthread_mutex_unlock (&vQueueMutex);
        
        // execute task
        task->uFunction (task->uArgs);
    }
    
    return nullptr;
}

TaskManager::TaskManager ()
{
    vTasks = new Queue<tTask> ();
    vThreadPool = new ThreadPool (ExecuteTask);
    
    pthread_mutex_init (&vQueueMutex, nullptr);
    pthread_cond_init (&vQueueCond, nullptr);
}

TaskManager::~TaskManager ()
{
    delete vTasks;
    delete vThreadPool;

    pthread_mutex_destroy (&vQueueMutex);
    pthread_cond_destroy (&vQueueCond);
}

void
TaskManager::ExecuteAsync (tTask & pTask)
{
    pthread_mutex_lock (&vQueueMutex);
    
    vTasks->Enqueue (pTask);
    
    pthread_mutex_unlock (&vQueueMutex);
    pthread_cond_signal (&vQueueCond);
}
