#pragma once

#include <pthread.h>
#include "types.h"

constexpr size_t  NUM_THREADS = 10;

class ThreadPool {

public:
                        ThreadPool      (const pthread_mutex_t & pMutex, const pthread_cond_t & pCond);
        void            Run             (tTask pTask);

private:

static  void *          Wrapper         (void * pArg);

        pthread_t       vThreads        [NUM_THREADS];
static  pthread_cond_t  vCond;
static  pthread_mutex_t vMutex;
};
