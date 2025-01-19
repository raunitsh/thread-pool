#pragma once

using Function = void * (*) (void * pArgs);

typedef struct {

    Function uFunction;
    void *   uArgs;
} tTask;
