#ifndef QUEUE_H
#define QUEUE_H

#pragma once
#include "PlatformBindings.h"

// An example queue using an int item:
#define SIZE 5

// Checks if the queue is full
int isEmpty();

// Checks if the queue is empty
int isFull();

// Add an item to the array
void enQueue(int item);

// Remove an item from the array
int deQueue();


#endif
