#ifndef QUEUE_H
#define QUEUE_H

#include <cstdio>
#include <cstdlib>

typedef struct
{
    int Head;
    int Tail;

    int size;
} Queue;

int isFull(Queue queue);
int isEmpty(Queue queue);

#endif 
