#include "thread_pool.h"

ThreadPool::ThreadPool (Function pThreadRoutine)
{
        pthread_attr_t attr;
    
    vExecutor = pThreadRoutine;
    pthread_attr_init (&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    for (size_t i=0; i<NUM_THREADS; ++i)
        pthread_create (vThreads + i, &attr, vExecutor, nullptr);
    
}

void
ThreadPool::Start ()
{
    for (size_t i=0; i<NUM_THREADS; ++i)
        pthread_join (vThreads[i], nullptr);
}
