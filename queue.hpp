#pragma once

template<typename T>
class QueueNode {
    
public:
        QueueNode ();

    QueueNode * uNext;
    T *         uData;
};

template<typename T>
class Queue {

public:
                    Queue       ();
                    ~Queue      ();
    void            Enqueue     (T & pData);
    T *             Dequeue     ();
    bool            IsEmpty     ();

private:
    QueueNode<T> *  vHead;
    QueueNode<T> *  vTail;
};

#include "queue.hxx"
