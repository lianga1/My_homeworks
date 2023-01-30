#include "heap.h"

void sift(Heap *heap, int low, int high)
{
    int i = low;
    int j = 2 * i + 1;
    Node temp;
    temp=heap->data[i];

    while(j <= high)//if the node has child
    {
        if(j < high && heap->data[j].priority < heap->data[j+1].priority)//if the right child is bigger than the left child
            j++;
        if(temp.priority >= heap->data[j].priority)//if the parent is bigger than the child
            break;

        heap->data[i]=heap->data[j];
        i = j;//exchange the index
        j = 2 * i + 1;//go to the next level
    }

    heap->data[i]=temp;
}

void Heapsort(Heap* heap)
{

    int i;
    Node temp;
    for(i = heap->size/2 - 1;i >= 0;i--)//sift the heap
        sift(heap,i,heap->size-1);
    for(i = heap->size - 1;i > 0;i--)
    {
        temp=heap->data[0];
        heap->data[0]=heap->data[i];
        heap->data[i]=temp;
        sift(heap,0,i-1);
    }
}

void shiftup(Heap *heap,int index)
{
    int i = index;
    int j = (i - 1)/2;
    Node temp;
    temp=heap->data[i];
    while(i > 0)
    {
        if(heap->data[j].priority >= temp.priority)
            break;
        heap->data[i]=heap->data[j];
        i = j;
        j = (i - 1)/2;
    }
    heap->data[i]=temp;
}

void shiftdown(Heap *heap,int index)
{
    int i = index;
    int j = 2 * i + 1;
    Node temp;
    temp=heap->data[i];
    while(j <= heap->size - 1)
    {
        if(j < heap->size - 1 && heap->data[j].priority < heap->data[j+1].priority)
            j++;
        if(temp.priority >= heap->data[j].priority)
            break;
        heap->data[i]=heap->data[j];
        i = j;
        j = 2 * i + 1;
    }
    heap->data[i]=temp;
}