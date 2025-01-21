#include <cstdio>
#include "task_manager.h"

void *
Task (void * pArg)
{
    printf ("arg is: %s\n", (const char *) pArg);
    return nullptr;
}

int
main ()
{
        TaskManager task_manager;
        tTask *     task;
        
    for (size_t i=0; i<10; ++i) {
        
        task            = new tTask;
        task->uFunction = Task;
        task->uArgs     = (void *) "raunit";
        
        task_manager.ExecuteAsync (*task);
    }
    
    pthread_exit(0);
}
