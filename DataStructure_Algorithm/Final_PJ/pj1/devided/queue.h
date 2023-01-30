#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"

typedef struct Queue{
    Heap *heap;
    
}Queue;

Queue* InitQueue();//initialize the queue
void Enqueue(Queue *queue,Node n);//enqueue the node
Node Dequeue(Queue *queue);//dequeue the node
void PrintQueue(Queue *queue);//print the queue
Node quit(Queue *queue,int num);//quit the node
#endif