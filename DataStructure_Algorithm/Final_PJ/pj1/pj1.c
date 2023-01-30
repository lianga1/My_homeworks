#include<stdio.h>
#include<string.h>


#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define NAME 20
#define MAX 100
#define COMMAND 20
typedef struct Node{
    int id;

    char name[NAME];
    int priority;
}Node;
typedef struct Heap{
    Node data[MAX];
    int size;

}Heap;

typedef struct Queue{
    Heap *heap;
    
}Queue;


Queue* InitQueue();//initialize the queue
void Enqueue(Queue *queue,Node n);//enqueue the node
Node Dequeue(Queue *queue);//dequeue the node
void PrintQueue(Queue *queue);//print the queue
Node quit(Queue *queue,int num);//quit the node


void shiftup(Heap *heap,int index);//shift up the heap
void shiftdown(Heap *heap,int index);//shift down the heap


int main()
{
    char command[COMMAND];
    Queue *p_queue=InitQueue();

    while(1)
    {
        scanf("%s",command);
        if(strcmp(command,"enqueue")==0)
        {
            Node temp;
            scanf("%s %d %d",temp.name,&temp.id,&temp.priority);
            Enqueue(p_queue,temp);
        }
        else if(strcmp(command,"dequeue")==0)
        {
            Dequeue(p_queue);
        }
        else if(strcmp(command,"print")==0)
        {
            PrintQueue(p_queue);
        }
        else if(strcmp(command,"quit")==0)
        {
            int num;
            scanf("%d",&num);
            quit(p_queue,num);

        }
        else if(strcmp(command,"update")==0)
        {
            Node temp;
            int num;
            int prior;
            scanf("%d %d",&num,&prior);
            temp=quit(p_queue,num);
            temp.priority=prior;
            Enqueue(p_queue,temp);
        }
        else if(strcmp(command,"end")==0)
        {
            break;
        }
        else
        {
            printf("error command");
        }
    }   
    return 0;


}

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


void shiftup(Heap *heap,int index)
{
    int i = index;
    int j = (i - 1)/2;
    Node temp;
    temp=heap->data[i];
    while(i > 0)
    {
        if(heap->data[j].priority >= temp.priority)//if the parent is bigger than the child,then break
            break;
        heap->data[i]=heap->data[j];//if the parent is smaller than the child,then the child is the parent
        i = j;//
        j = (i - 1)/2;//
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
