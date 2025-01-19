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
        tTask task;

    task.uFunction = Task;
    task.uArgs     = (void *) "raunit";

    task_manager.Add (task);
    task_manager.Execute ();
}
