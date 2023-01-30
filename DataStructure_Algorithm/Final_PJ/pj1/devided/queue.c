#include "queue.h"

Queue* InitQueue(){
    Queue *p_queue=(Queue*)malloc(sizeof(Queue));
    p_queue->heap=(Heap*)malloc(sizeof(Heap));
    p_queue->heap->size=0;
    return p_queue;
}

void Enqueue(Queue *queue,Node n)
{
    queue->heap->data[queue->heap->size].id=n.id;
    queue->heap->data[queue->heap->size].priority=n.priority;
    strcpy(queue->heap->data[queue->heap->size].name,n.name);
    queue->heap->size++;
    shiftup(queue->heap,queue->heap->size-1);
}
Node Dequeue(Queue *queue)
{
    Node temp;
    temp=queue->heap->data[0];

    queue->heap->data[0]=queue->heap->data[queue->heap->size-1];
    queue->heap->size--;
    shiftdown(queue->heap,0);
    return temp;
}
void PrintQueue(Queue *queue)
{
    int i;
    for(i=0;i<queue->heap->size;i++)
    {
        printf("%d %d %s\n",queue->heap->data[i].id,queue->heap->data[i].priority,queue->heap->data[i].name);
    }
}
Node quit(Queue *queue,int num)
{
    int i;
    Node temp;
    for(i=0;i<queue->heap->size;i++)
    {
        if(queue->heap->data[i].id==num)
        {
            temp=queue->heap->data[i];
            queue->heap->data[i]=queue->heap->data[queue->heap->size-1];

            queue->heap->size--;
            shiftdown(queue->heap,i);
            return temp;
        }
    }
}