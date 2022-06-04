#include <stdio.h>
#include <stdlib.h>

int items[10];
int Head = 0, Tail = 0;

int isFull()
{
    if(Head == -1) return 1;
    return 0;
}

int isEmpty()
{
    if(Tail == 9) return 1;
    return 0;
}

int enQueue(int item)
{
    if(isEmpty()) Head = 0;

    if(isFull()) return 0;

    items[Tail] = item;
    Tail = (Tail + 1) % 10;
    return 1;
}

int deQueue()
{
    int result;

    result = items[Head];
    Head = (Head + 1) % 10;

    return result;
}

int main()
{
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);
    enQueue(7);
    enQueue(8);
    enQueue(9);
    enQueue(10);

    for(int i = 0; i < 20; i++)
    {
        printf("%d, ", deQueue());
    }

    printf("\n");

    return 0;
}
