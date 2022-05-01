#include "Queue.h"

// The "item" (int) array:
int items[SIZE];

// The indexes of the items that are at the front and rear of the array
int HeadOTheQueue = 0, RearOTheQueue = 0;

int isEmpty()
{
    if(HeadOTheQueue == -1) return 1;
    return 0;
}

int isFull()
{
    if(RearOTheQueue == SIZE) return 1;
    return 0;
}

void enQueue(int item)
{
    // If the queue is empty then the first position of the queue needs to be 0.
    if(isEmpty()) RearOTheQueue = 0;

    if(!isFull())
    {
        items[RearOTheQueue] = item;
        RearOTheQueue = (RearOTheQueue + 1) % 5;
    }
}

int deQueue()
{
    int result;

    if(isEmpty()) return -1;

    result = items[HeadOTheQueue];
    HeadOTheQueue = (HeadOTheQueue + 1) % 5;

    return result;
}
