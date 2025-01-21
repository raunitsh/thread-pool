#pragma once

template<typename T>
QueueNode<T>::QueueNode ()
{
    uNext = nullptr;
    uData = nullptr;
}

template<typename T>
Queue<T>::Queue ()
{
    vHead = nullptr;
    vTail = nullptr;
}

template<typename T>
Queue<T>::~Queue ()
{
    delete vHead;
//    delete vTail;
}
template<typename T>
void
Queue<T>::Enqueue (T & pData)
{
        QueueNode<T> * node = new QueueNode<T> ();

    node->uData = &pData;

    if (!vHead) {

        vHead = node;
        vTail = node;
        return;
    }

    vTail->uNext = node;
    vTail = node;
}

template<typename T>
T *
Queue<T>::Dequeue ()
{
        QueueNode<T> * ret;

    if (!vHead)
        return nullptr;

    if (vHead == vTail) {

        ret   = vHead;
        vHead = ret->uNext;
        vTail = vHead;
        return ret->uData;
    }

    ret = vHead;
    vHead = ret->uNext;
    ret->uNext = nullptr;

    return ret->uData;
}

template<typename T>
bool
Queue<T>::IsEmpty ()
{
    return vHead == nullptr;
}
