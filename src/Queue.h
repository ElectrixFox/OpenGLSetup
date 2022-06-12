#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Head;
    int Tail;

    int size;
} Queue;

int isFull(Queue queue);
int isEmpty(Queue queue);

#endif 
