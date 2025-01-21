#pragma once

#include <pthread.h>
#include "types.h"

constexpr size_t  NUM_THREADS = 10;

class ThreadPool {

public:
                        ThreadPool      (Function pThreadRoutine);
        void            Start           ();

private:

        Function        vExecutor;
        pthread_t       vThreads        [NUM_THREADS];
};
