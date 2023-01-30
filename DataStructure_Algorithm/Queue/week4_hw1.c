//priority queue
#include <stdio.h>
#include <malloc.h>
#define N1 100
#define N2 500
#define N3 3000

typedef struct {
    int* data;
    int maximum;
    int current;
    int front,rear;
}Queue;

Queue* QueueInit(int a);//initialize the queue with 3 types
void DestroyQueue(Queue* q);
int QueueEmpty(Queue* q);
int enQueue(Queue* q,int elem);//the fuction includes enqueue, judge whether merge and dequeue and plus to the current
int deQueue(Queue* q);
void QueueClear(Queue* q);
void Queue3Flush(Queue *q);

int main()
{
    Queue *q1=QueueInit(1);
    Queue *q2=QueueInit(2);
    Queue *q3=QueueInit(3);//initialize 3 queues with 100,500 and 3000 capacity

    int total;//total number of elements
    int temp;//temp of input
    
    scanf("%d",&total);//get the total number of elements

    for(int i=0;i<total;i++)//input and judge which queue the temp should go into
    {
        scanf("%d",&temp);//input the numbers
        if(temp>=0&&temp<=N1)
        {
            if(enQueue(q1,temp))//if q1 overflows
            {
                if(enQueue(q2,q1->current))//if q2 overflows
                {
                    if(enQueue(q3,q2->current))//if q3 overflows
                    {
                        Queue3Flush(q3);//deQueue until the
                    }
                    QueueClear(q2);
                }
                QueueClear(q1);
            }
        }
        else if(temp<=N2)
        {
            if(enQueue(q2,temp))//if q2 overflows
                {
                    if(enQueue(q3,q2->current))//if q3 overflows
                    {
                        Queue3Flush(q3);//deQueue until the
                    }
                    QueueClear(q2);
                }
        }
        else if(temp<=N3)
        {
            if(enQueue(q3,temp))//if q3 overflows
                {
                    Queue3Flush(q3);//deQueue until the
                }
        }
        else break;
    }

    while(!QueueEmpty(q3)){
        printf("%d ",deQueue(q3));
    }
    while(!QueueEmpty(q2)){
        printf("%d ",deQueue(q2));
    }
    while(!QueueEmpty(q1)){
        printf("%d ",deQueue(q1));
    }

    DestroyQueue(q1);
    DestroyQueue(q2);
    DestroyQueue(q3);

    return 0;
}

Queue* QueueInit(int a)//initialize the queue with 3 types
{
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->current=0;
    q->front=q->rear=0;
    if(a==1)
       { 
        q->data=(int*)malloc(N1*sizeof(int));
        q->maximum=N1;
       }    
    if(a==2)
       { 
        q->data=(int*)malloc(N2*sizeof(int));
        q->maximum=N2;
       }
    if(a==3)
       { 
        q->data=(int*)malloc(N3*sizeof(int));
        q->maximum=N3;
       }
    return q;
}
void DestroyQueue(Queue* q)
{
    free(q->data);
    free(q);
}
int QueueEmpty(Queue* q)
{
    return q->front==q->rear;
}
int enQueue(Queue* q,int elem)//the fuction includes enqueue, judge whether merge and dequeue and plus to the current
{
    q->rear=(q->rear+1)%(q->maximum);
    q->data[q->rear]=elem;
    q->current+=elem;
    if(q->maximum<q->current)
        return 1;
    return 0;

}
int deQueue(Queue* q)
{
    q->front=(q->front+1)%(q->maximum);
    int elem=q->data[q->front];
    q->current-=elem;
    return elem;
}
void QueueClear(Queue* q)
{
    q->front=q->rear;
    q->current=0;
}
void Queue3Flush(Queue *q)
{
    while(q->current>q->maximum)
    {
        deQueue(q);
    }
}