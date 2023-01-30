#include <stdio.h>
#include <malloc.h>

#define MaxV 1000

int visited[MaxV];

typedef struct ANode//the edge points
{
    int adjvex;
    struct ANode* nextarc;
} ArcNode;

typedef struct//the head points
{
    ArcNode *firstarc;
    int number;
} VNode;

typedef struct //the head points' list
{ 
    VNode adjList[MaxV];
    int nodes,edges;
} AdjGraph;


typedef struct 
{
    int data[MaxV];
    int front,rear;
}Queue;

Queue* QueueInit();//Initialize the Queue
void DestroyQueue(Queue* q);//Destroy the Queue
int QueueEmpty(Queue *q);//check if the Queue is empty
void enQueue(Queue *q,int vertex);//push in the Queue without check overflow
int deQueue(Queue *q);//drag out 1 elem in Queue withou check empty


AdjGraph* GraphInit();//initialize a AdjGraph
void InputEdge(AdjGraph *G);//input the whole graph

void BFS1(AdjGraph* G,int begin);
void BFS(AdjGraph* G,int begin);

ArcNode* ArcNodeInit(int end);//initialize an Arcnode with the terminal

int main()
{
    AdjGraph *G;
    int beginer;//the beginer of the DFS;
    G=GraphInit();
    scanf("%d",&(G->nodes));
    scanf("%d",&(G->edges));//input the number of nodes and edges

    InputEdge(G);
    
    scanf("%d",&beginer);
    BFS1(G,beginer);

    return 0;
}

AdjGraph* GraphInit()
{
    AdjGraph* G;
    G=(AdjGraph*)malloc(sizeof(AdjGraph));
    for(int i=0;i<MaxV;i++)
        {
            G->adjList[i].firstarc=NULL;
        }
    G->nodes=0;
    G->edges=0;

    return G;
}

void InputEdge(AdjGraph *G)
{
    int head;
    int end;
    ArcNode* p;//temp of triverse
    ArcNode* inserter;//the input element
    for(int i=0;i<G->edges;i++)//input the each edge
    {
        scanf("%d",&head);
        scanf("%d",&end);//input the current edge

        /*head to end*/
        p=G->adjList[head].firstarc;
        inserter=ArcNodeInit(end);//build the edge for inserting

        if(p==NULL)//if the first node
        {
            G->adjList[head].firstarc=inserter;
        }

        for(;p!=NULL;p=p->nextarc)//insert the node
        {
            if(p->adjvex<inserter->adjvex)//if current is less than inserter
            {
                if(p->nextarc==NULL)//if come to end
                {    
                    p->nextarc=inserter;
                    break;
                }
                else if(p->nextarc->adjvex>inserter->adjvex)//if insert behind p
                {
                    inserter->nextarc=p->nextarc;
                    p->nextarc=inserter;
                    break;
                }
            }
            else//if need to insert to the firstarc
            {
                G->adjList[head].firstarc=inserter;
                inserter->nextarc=p;
                break;
            }
            
        }

        /*****************************************/

        /*end to head*/

        p=G->adjList[end].firstarc;
        inserter=ArcNodeInit(head);//build the edge for inserting

        if(p==NULL)//if the first node
        {
            G->adjList[end].firstarc=inserter;
            continue;
        }

        for(;p!=NULL;p=p->nextarc)//insert the node
        {
            if(p->adjvex<inserter->adjvex)//if current is less than inserter
            {
                if(p->nextarc==NULL)//if come to end
                {    
                    p->nextarc=inserter;
                    break;
                }
                else if(p->nextarc->adjvex>inserter->adjvex)//if insert behind p
                {
                    inserter->nextarc=p->nextarc;
                    p->nextarc=inserter;
                    break;
                }
            }
            else//if need to insert to the firstarc
            {
                G->adjList[end].firstarc=inserter;
                inserter->nextarc=p;
                break;
            }
            
        }

        /*****************************************/
    }
}

void BFS1(AdjGraph* G,int begin)
{
    int i;
    for(i=0;i<MaxV;i++)
        visited[i]=0;
    BFS(G,begin);
    for(i=0;i<G->nodes;i++)
        if(visited[i]!=1)
            BFS(G,i);

}

void BFS(AdjGraph* G,int begin)
{
    int temp;//temp of the dequeue
    ArcNode* p;
    Queue *q;
    q=QueueInit();//the queue

    enQueue(q,begin);
    printf("%d ",begin);
    visited[begin]=1;//visit the first node

    while(!QueueEmpty(q))
    {
        temp=deQueue(q);
        p=G->adjList[temp].firstarc;
        while(p!=NULL)//enqueue all the unvisited vertexes
        {
            if(visited[p->adjvex]==0)//if unvisited
            {
                printf("%d ",p->adjvex);
                enQueue(q,p->adjvex);
                visited[p->adjvex]=1;
            }
            p=p->nextarc;
        }
    }
    

}



ArcNode* ArcNodeInit(int end)
{
    ArcNode* n;
    n=(ArcNode*)malloc(sizeof(ArcNode));
    n->adjvex=end;
    n->nextarc=NULL;
    return n;
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
void enQueue(Queue *q,int vertex)
{
    q->rear=(q->rear+1)%MaxV;
    q->data[q->rear]=vertex;

}
int deQueue(Queue *q)
{
    q->front=(q->front+1)%MaxV;
    int elem=q->data[q->front];
    return elem;
}