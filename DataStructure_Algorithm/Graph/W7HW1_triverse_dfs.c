#include <stdio.h>
#include <malloc.h>

#define MaxV 1000

int visited[MaxV];

typedef struct ANode//the edge points
{
    int adjvex;
    struct ANode* nextarc;
}ArcNode;

typedef struct//the head points
{
    ArcNode *firstarc;
    int number;
} VNode;

typedef struct //the head points' list
{
    
    VNode adjList[MaxV];
    int nodes,edges;

}AdjGraph;

AdjGraph* GraphInit();//initialize a AdjGraph
void InputEdge(AdjGraph *G);//input the whole graph
void DFS(AdjGraph *G,int vertex);//scan the whole graph
void DFS1(AdjGraph *G,int begin);//non connected graph

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
    DFS1(G,beginer);

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

void DFS(AdjGraph *G,int vertex)
{
    ArcNode *p;
    int w;
    visited[vertex]=1;
    printf("%d ",vertex);

    p=G->adjList[vertex].firstarc;
    while(p!=NULL)
    {
        w=p->adjvex;
        if(visited[w]==0)
            DFS(G,w);
        p=p->nextarc;
    }
    
}

void  DFS1(AdjGraph *G,int begin)
{  int i;
    DFS(G,begin);
   for (i=0;i<G->nodes;i++)     //遍历所有未访问过的顶点
      if (visited[i]==0) 
         DFS(G,i);
}


ArcNode* ArcNodeInit(int end)
{
    ArcNode* n;
    n=(ArcNode*)malloc(sizeof(ArcNode));
    n->adjvex=end;
    n->nextarc=NULL;
    return n;
}