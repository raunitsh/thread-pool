#include "thread_pool.h"

void *
ThreadPool::Wrapper (void * pArg)
{
    while (true) {

        pthread_cond_wait (&vCond, &vMutex);
    }

    return nullptr;
}

ThreadPool::ThreadPool (const pthread_mutex_t & pMutex, const pthread_cond_t & pCond)
{
    vMutex = pMutex;
    vCond  = pCond;

    for (size_t i=0; i<NUM_THREADS; ++i) {

        pthread_create (vThreads + i, nullptr, &Wrapper, nullptr);
    }
}
