#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define MAX 100
#define Maxsize 2500
#define INF 999999

int visited[Maxsize];

typedef struct Rail{
    int begin;//start point's number
    int end;//end point's number
    struct Rail *next;//next rail

    double w;//weight
} Railway;//define a railway

typedef struct {
    int x;//x coordinate
    int y;//y coordinate
    int number;//the number of the vertex
    int SetNum;//the number of the set
    Railway *first;
} City;//define a point

typedef struct {
    int n;//define nodes
    int e;//define edges so long

    City v[MAX];//define a vertex array
}Graph;//define a graph



typedef struct matrix{
    double w[MAX][MAX];//define a matrix
}Matrix;

Matrix* buildMatrix();

Graph* GraphInit();//initialize a graph

void SetCity(Graph *g,int x,int y,int num);//set the city's coordinate
void SetRailway(Graph *g,int begin,int end);//set the railway's weight

Railway* Kruskal(Graph *g,Matrix* wm);//Kruskal algorithm

Matrix* BuildWeightMatrix(Graph *g);//build a weight matrix


void DFS(Graph *G,int vertex,int sn);
void  DFS1(Graph *G,int begin);
void OutPut(Railway* r);//output the result

int main()
{

    int cities;//define the number of cities
    int railways;//define the number of railways
    int x,y;//define the coordinates of the cities
    int begin,end;//define the start point and the end point of the railway
    Graph *g;//define a graph
    g=GraphInit();//initialize the graph

    scanf("%d",&cities);//input the number of cities

    g->n=cities;//set the number of cities

    if(cities==1)
    {
        printf("NULL");
        return 0;
    }

    for(int i=1;i<=cities;i++)//input the coordinates of the cities
    {
        scanf("%d %d",&x,&y);//input the coordinates of the cities
        SetCity(g,x,y,i);//set the cities
    }

    scanf("%d",&railways);//input the number of railways

    g->e=railways;//set the number of railways

    for(int i=0;i<railways;i++)//input the railways
    {
        scanf("%d %d",&begin,&end);//input the railways
        SetRailway(g,begin,end);//set the railways
    }

    DFS1(g,0);  //get the sets of cities

    Matrix* weightMatrix=BuildWeightMatrix(g);

    //build a weight matrix
    
    Railway* r=Kruskal(g,weightMatrix);//Kruskal algorithm

    OutPut(r);//output the result

    return 0;
}
Graph* GraphInit()
{
    Graph *g=(Graph*)malloc(sizeof(Graph));//initialize a graph
    g->n=0;//initialize the number of vertexes
    g->e=0;//initialize the number of edges
    for(int i=0;i<MAX;i++)
    {
        g->v[i].first=NULL;//initialize the vertex array
    }
    return g;//return the graph
}

void SetCity(Graph *g,int x,int y,int num)
{

    g->v[num].number=num;
    g->v[num].x=x;
    g->v[num].y=y;
    g->v[num].SetNum=num;

}
void SetRailway(Graph *g,int begin,int end)
{
    Railway *r=(Railway*)malloc(sizeof(Railway));//initialize a railway
    r->begin=begin;
    r->end=end;
    r->next=NULL;
    r->w=sqrt(pow(g->v[begin].x-g->v[end].x,2)+pow(g->v[begin].y-g->v[end].y,2));//calculate the weight of the railway

    Railway *p;//define a railway pointer
    p=g->v[begin].first;//set the railway pointer to the first railway
    if(p==NULL)     //if the first railway
        g->v[begin].first=r;//set the railway to the first railway
    if(p!=NULL)
    {
        for(;p!=NULL;p=p->next)//traverse the railways
        {
            if(r->end>p->end)
            {
                if(p->next==NULL)
                {
                    p->next=r;
                    break;
                }
                else if(r->end<p->next->end)
                {
                    r->next=p->next;
                    p->next=r;
                    break;
                }
            }
            else if(r->end<p->end)
            {
                r->next=p;
                g->v[begin].first=r;
                break;
            }
        }
    }


    Railway *r1=(Railway*)malloc(sizeof(Railway));//initialize a railway
    r1->begin=end;
    r1->end=begin;
    r1->next=NULL;
    r1->w=sqrt(pow(g->v[begin].x-g->v[end].x,2)+pow(g->v[begin].y-g->v[end].y,2));//calculate the weight of the railway

    p=g->v[end].first;//set the railway pointer to the first railway
    if(p==NULL)//if the first railway
    {
        g->v[end].first=r;//set the railway to the first railway
        
    }
    if(p!=NULL)
    {
        for(;p!=NULL;p=p->next)//traverse the railways
        {
            if(r->end>p->end)
            {
                if(p->next==NULL)
                {
                    p->next=r;
                    break;
                }
                else if(r->end<p->next->end)
                {
                    r->next=p->next;
                    p->next=r;
                    break;
                }
            }
            else if(r->end<p->end)
            {
                r->next=p;
                g->v[end].first=r;
                break;
            }
        }
    }


}

Railway* Kruskal(Graph *g,Matrix* wm)
{
    int cityset[MAX];//define a set of cities
    Railway R[Maxsize];//define a railway array
    int k=0;
    Railway *p;
    for(int i=1;i<=g->n;i++)//set the city to the set
    {
        cityset[i]=g->v[i].SetNum;
    }
    for(int i=1;i<=g->n;i++)//set the R array
    {
        for(int j=1;j<=g->n;j++)
        {
            if(wm->w[i][j]!=0)
            {
                R[k].begin=i;
                R[k].end=j;
                R[k].w=wm->w[i][j];
                k++;
            }
        }
    }
    
    for(int i=0;i<k;i++)//sort the Edge array
    {
        for(int j=0;j<k-i-1;j++)
        {
            if(R[j].w>R[j+1].w)//if the weight of the railway is bigger than the next railway
            {
                Railway temp;//define a railway
                temp=R[j];//set the railway
                R[j]=R[j+1];//set the railway
                R[j+1]=temp;//set the railway
            }
        }
    }

    int j=0;
    k=1;
    int begin1,end1;
    int SetNum1,SetNum2;

    Railway *r=NULL;//initialize a railway
    SetNum1=cityset[R[0].begin];
    while(j<(g->n)*(g->n))
    {
        begin1=R[j].begin;
        end1=R[j].end;
        SetNum1=cityset[begin1];
        SetNum2=cityset[end1];
        if(SetNum1!=SetNum2)
        {
            for(int i=1;i<=g->n;i++)
            {
                if(cityset[i]==SetNum2)
                {
                    cityset[i]=SetNum1;
                }
            }
            if(k==1)
            {
                r=(Railway*)malloc(sizeof(Railway));//initialize a railway
                r->begin=begin1;
                r->end=end1;
                r->w=R[j].w;
                r->next=NULL;
                p=r; 
                k++;
            }
            else
            {
                Railway *r1=(Railway*)malloc(sizeof(Railway));//initialize a railway
                r1->begin=begin1;
                r1->end=end1;
                r1->w=R[j].w;
                r1->next=NULL;
                p->next=r1;
                p=p->next;
            }
        }
        j++;
    }
    return r;

}

Matrix* BuildWeightMatrix(Graph *g)
{
    Matrix *wm=buildMatrix();

    for(int i=1;i<=g->n;i++)
    {
        for(int j=1;j<=g->n;j++)
        {
            if(i==j||i==0||j==0)
                wm->w[i][j]=0;
            else
                wm->w[i][j]=sqrt(pow(g->v[i].x-g->v[j].x,2)+pow(g->v[i].y-g->v[j].y,2));
        }
    }
        return wm;
}


void DFS(Graph *G,int vertex,int sn)
{
    Railway *p;
    int w;
    visited[vertex]=1;

    p=G->v[vertex].first;
    while(p!=NULL)
    {
        w=p->end;
        if(visited[w]==0)
        {
            G->v[w].SetNum=sn;
            DFS(G,w,sn);
            
        }
        p=p->next;
    }
    
}

void  DFS1(Graph *G,int begin)
{  int i;
   for (i=1;i<=G->n;i++)     //遍历所有未访问过的顶点
      if (visited[i]==0) 
         DFS(G,i,G->v[i].SetNum);
}

void OutPut(Railway* r)//output the railways by the order of weight,begin city ,and end city
{

    Railway *p1,*temp;
    Railway *p;
    Railway* sorted_head=(Railway*)malloc(sizeof(Railway));
    sorted_head->next=NULL;
    sorted_head->w=-1;

    if(r==NULL)
    {
        printf("NULL");
        return;
    }

    for(;r!=NULL;r=r->next)
    {
        for(p1=sorted_head;p1->next!=NULL;p1=p1->next)
        {
            if(r->w<p1->next->w)
            {
                break;
            }
            else if(r->w==p1->next->w)
            {
                if(r->begin<p1->next->begin)
                {
                    break;
                }
                else if(r->begin==p1->next->begin)
                {
                    if(r->end<p1->next->end)
                    {
                        break;
                    }
                }
            }
        }
        temp=(Railway*)malloc(sizeof(Railway));
        temp->begin=r->begin;
        temp->end=r->end;
        temp->w=r->w;
        temp->next=p1->next;
        p1->next=temp;
    }



    for(p1=sorted_head->next;p1!=NULL;p1=p1->next)
    {
        printf("%d %d\n",p1->begin,p1->end);
    }    

}

Matrix* buildMatrix()
{
    Matrix *m=(Matrix*)malloc(sizeof(Matrix));
    return m;
}