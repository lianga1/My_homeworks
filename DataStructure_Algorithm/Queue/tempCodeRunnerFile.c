#include<stdio.h>
#include<malloc.h>
#define Maxsize 2000

typedef struct{
    int id;
    int size;
}Process;

typedef struct 
{
    Process data[Maxsize];
    int front,rear;
}Queue;

Queue* QueueInit();//Initialize the Queue
void DestroyQueue(Queue* q);//Destroy the Queue
int QueueEmpty(Queue *q);//check if the Queue is empty
void enQueue(Queue *q,int id,int size);//push in the Queue without check overflow
Process deQueue(Queue *q);//drag out 1 elem in Queue withou check empty

double tick(Queue *q,int speed,double time);
/*
every tick,we transport data and enQueue and deQueue.
the data we transport depends on the time we give.
if the time*speed > data ,we quit the function and return the time we use.
else we just return 1 as the normal time;
*/

int main()
{
    Queue *process;//Queue of processes
    process=QueueInit();
    
    Process temp;

    int p_num;//number of processes 
    int speed;//the speed of transportation
    int data_temp;//temp data when input
    double time;//set time of the transportation
    double runtime=0;//the running time of
    int i=0;//temp
    /*input the parameters*/
    scanf("%d",&p_num);
    scanf("%d",&speed);
    for(int i=0;i<p_num;i++)//input the data of each process
    {
        scanf("%d",&data_temp);
        enQueue(process,i+1,data_temp);
    }
    scanf("%lf",&time);
    /*input end*/

    while(!QueueEmpty(process)&&time-runtime>(double)(1/speed))//roll when the Queue is not empty and the time is enough to transport
    {
        if(time-runtime>=1)
            runtime+=tick(process,speed,1);
        else
            runtime+=tick(process,speed,time-runtime);
    }
    while(!QueueEmpty(process))
    {
        temp=deQueue(process);
        printf("%d %d\n\n",temp.id,temp.size);
    }
    return 0;
}

Queue* QueueInit()
{
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=q->rear=0;
    return q;
}

void DestroyQueue(Queue* q)
{
    free(q);
}
int QueueEmpty(Queue *q)
{
    return q->front==q->rear;
}
void enQueue(Queue *q,int id,int size)
{
    q->rear=(q->rear+1)%Maxsize;
    q->data[q->rear].id=id;
    q->data[q->rear].size=size;

}
Process deQueue(Queue *q)
{
    q->front=(q->front+1)%Maxsize;
    Process elem=q->data[q->front];
    return elem;
}

double tick(Queue *q,int speed,double time)
{
    Process current;
    if(time<1)
    {
        q->data[q->front+1].size-=time*speed;
        return time;
    }
    current=deQueue(q);
    if(current.size-speed*time<=0)
    {
        return (double)current.size/speed;
    }
    current.size-=speed*time;
    enQueue(q,current.id,current.size);
    return 1;
}