#include "Queue.h"

int isFull(Queue queue)
{
    if(queue.Head == -1) return 1;
    return 0;
}

int isEmpty(Queue queue)
{
    if(queue.Tail == queue.size -1) return 1;
    return 0;
}
