#include <stdio.h>
#include <malloc.h>

#define MaxV 1000

int visited[MaxV];
int type;
typedef struct ANode//the edge points
{
    int adjvex;
    int gone;//0 is not walked , 1 is walked
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
void InputEdge(AdjGraph *G);//input the whole graph,type refers to the direction of graph(1 is directed, 0 is undirected)
int DFS(AdjGraph *G,int vertex,int origin);//scan the whole graph
// void DFS1(AdjGraph *G,int begin);//non connected graph

ArcNode* ArcNodeInit(int end);//initialize an Arcnode with the terminal

int Euler(AdjGraph* G);//find out if there is a Euler Circuit
int CheckConnect(AdjGraph *G);
void GoEdge(AdjGraph* G,int begin,int end);
void Refresh(AdjGraph *G);

int main()
{
    AdjGraph *G;
    int result;//the result of euler circuit    
    G=GraphInit();
    scanf("%d",&type);//scan the type of the graph
    scanf("%d",&(G->nodes));
    scanf("%d",&(G->edges));//input the number of nodes and edges

    
    
    InputEdge(G);
    
    result=Euler(G);
    if(result==0)
        printf("NO");
    else
        printf("YES");


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

        
        if(type==0)//if it's an undirected graph
        {
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
        }

        /*****************************************/
    }
}

int DFS(AdjGraph *G,int vertex,int origin)
{
    ArcNode *p;
    int w;
    //printf("%d ",vertex);

    if(CheckConnect(G)&&origin==vertex)//if the graph is totally travelled
        return 1;

    p=G->adjList[vertex].firstarc;
    while(p!=NULL)//or go on travel
    {
        if(p->gone==0)
        {   
            w=p->adjvex;
            GoEdge(G,vertex,w);
            if(DFS(G,w,origin))
                return 1;
            p->gone=0;
        }
        p=p->nextarc;
    }

    return 0;
}

// void  DFS1(AdjGraph *G,int begin)
// {  int i;
//     DFS(G,begin);
//    for (i=0;i<G->nodes;i++)     //triverse all unvisited points
//       if (visited[i]==0) 
//          DFS(G,i);
// }


ArcNode* ArcNodeInit(int end)
{
    ArcNode* n;
    n=(ArcNode*)malloc(sizeof(ArcNode));
    n->adjvex=end;
    n->nextarc=NULL;
    return n;
}

int Euler(AdjGraph* G)
{
    /*
    Description:   Find a Euler circuit
    Method:        try every node of the graph,if it ends with every edge of the graph visited 
                and the last node can connect to the beginer node, return 1. Else,clear the visited 
                list and go to the next beginer


    */

    for(int i=1;i<=G->nodes;i++)
    {
        if(DFS(G,i,i))
            return 1;
        Refresh(G);
    }



    return 0;
}

int CheckConnect(AdjGraph *G)//check if the path is all_edge_travelled
{
    ArcNode *p;
    p=G->adjList[0].firstarc;
    for(int i=0;i<=G->nodes;i++)
    {
        for(p=G->adjList[i].firstarc;p!=NULL;p=p->nextarc)
        {
            if(p->gone==0)
                return 0;
        }
    }
    return 1;
}
void GoEdge(AdjGraph* G,int begin,int end)
{
    /*delete the begin to end edge*/

    ArcNode* p,*pre;
    pre=G->adjList[begin].firstarc;
    p=pre->nextarc;
    if(pre->adjvex==end)
    {
        pre->gone=1;
    }
    else
    {
    for(;pre!=NULL && p!=NULL;p=p->nextarc)
    {
        if(p->adjvex==end)
        {
            p->gone=1;
        }
    }
    }
    /*********************************/

    if(type==0)
    {
    pre=G->adjList[end].firstarc;
    p=pre->nextarc;
    if(pre->adjvex==begin)
    {
        pre->gone=1;
    }
    else
    {
    for(;pre!=NULL && p!=NULL;p=p->nextarc)
    {
        if(p->adjvex==begin)
        {
            p->gone=1;
        }
    }
    }    
    }

}

void Refresh(AdjGraph *G)
{
    ArcNode *p;
    for(int i=0;i<=G->nodes;i++)
    {
        for(p=G->adjList[i].firstarc;p!=NULL;p=p->nextarc)
        {
            p->gone=0;
        }
    }
}