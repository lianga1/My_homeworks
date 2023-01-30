#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define Maxsize 2000



typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}TreeNode;

typedef struct 
{
    TreeNode* data[Maxsize];
    int front,rear;
}Queue;


TreeNode* NodeInit();
int TreeHeight(TreeNode* root);
TreeNode* BuildTree(int* Post,int* Mid,int n);
void Cut_tail(TreeNode *root);
void OutPutTree(TreeNode* root);

// int Input(int * reg);

Queue* QueueInit();//Initialize the Queue
void DestroyQueue(Queue* q);//Destroy the Queue
int QueueEmpty(Queue *q);//check if the Queue is empty
void enQueue(Queue *q,TreeNode* node);//push in the Queue without check overflow
TreeNode* deQueue(Queue *q);//drag out 1 elem in Queue withou check empty



int main()
{
    int number;
    int Mid[Maxsize];
    int Post[Maxsize];

    scanf("%d",&number);

    for(int i =0;i<number;i++)
        scanf("%d",&Mid[i]);
    for(int i=0;i<number;i++)
        scanf("%d",&Post[i]);
    TreeNode* root;
    root=BuildTree(Post,Mid,number);

    OutPutTree(root);

    return 0;
}

TreeNode* NodeInit()
{
    TreeNode *n;
    n=(TreeNode*)malloc(sizeof(TreeNode));
    n->lchild=NULL;
    n->rchild=NULL;
    return n;

}

int TreeHeight(TreeNode* root)
{
    int temp1;
    int temp2;
    if(root==NULL)
        return 0;
    else
    {
        temp1=TreeHeight(root->lchild);
        temp2=TreeHeight(root->rchild);
        return (temp1>temp2?temp1:temp2)+1;
    }
}

TreeNode* BuildTree(int* Post,int* Mid,int n)//build a subtree , current stands for the current end of Post
{

    TreeNode* root;
    root=NodeInit();
    int next=0;
    if(n<=0)
        return NULL;
    root->data=*(Post+n-1);

    int *p;
    for(p=Mid;p<Mid+n;p++)
    {
        if(*p==root->data)
            break;
    }
    next=p-Mid;
    root->lchild=BuildTree(Post,Mid,next);
    root->rchild=BuildTree(Post+next,p+1,n-next-1);

    return root;
}

void Cut_tail(TreeNode *root)
{
    if(root->lchild==NULL)
        return;
    
    if(root->lchild->lchild==NULL)
        {root->lchild=NULL;}
    if(root->rchild->rchild==NULL)
        root->rchild=NULL;

        if(root->lchild!=NULL)
            Cut_tail(root->lchild);
        if(root->rchild!=NULL)    
            Cut_tail(root->rchild);
    
    
}

void OutPutTree(TreeNode* root)
{
    TreeNode* tempnode;//temp of node
    Queue* q;
    q=QueueInit();
    enQueue(q,root);

    while(!QueueEmpty(q))//cut the string and push them into a tree
    {
        tempnode=deQueue(q);//get the current node
        if((tempnode->lchild!=NULL)||(tempnode->rchild!=NULL))
        {
            if(tempnode->lchild!=NULL)
                enQueue(q,tempnode->lchild);
            if(tempnode->rchild!=NULL)
                enQueue(q,tempnode->rchild);
        }
        printf("%d ",tempnode->data);
    }
    
    DestroyQueue(q);
    
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
void enQueue(Queue *q,TreeNode* node)
{
    q->rear=(q->rear+1)%Maxsize;
    q->data[q->rear]=node;

}
TreeNode* deQueue(Queue *q)
{
    q->front=(q->front+1)%Maxsize;
    TreeNode* elem=q->data[q->front];
    return elem;
}
