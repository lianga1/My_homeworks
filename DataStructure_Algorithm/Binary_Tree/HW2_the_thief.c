//constructed by linktree

//so long failed

//succeeded but still have some to improve

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


TreeNode* NodeInit();//initialize a node
int TreeHeight(TreeNode* root);//calculate the height
TreeNode* InputTree();//scan the tree from standard io
void Cut_tail(TreeNode *root);//a function under InputTree,to cut the extra nodes of the tree

// int Input(int * reg);
int cut_trans_str(char* str,int * i);//a function under InputTree, to cut the string into nodes

Queue* QueueInit();//Initialize the Queue
void DestroyQueue(Queue* q);//Destroy the Queue
int QueueEmpty(Queue *q);//check if the Queue is empty
void enQueue(Queue *q,TreeNode* node);//push in the Queue without check overflow
TreeNode* deQueue(Queue *q);//drag out 1 elem in Queue withou check empty


int Thief(TreeNode* root,int eat);//calculate the maximum of the theft,eat stands for whether eat the root node


int main()
{
    int maximum;//height of the tree
    TreeNode *root;
    //root=NodeInit();
    root=InputTree();
    // maximum=TreeHeight(root);
    int red=Thief(root,0);
    int black=Thief(root,1);

    maximum=red>black?red:black;
    printf("%d",maximum);
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

TreeNode* InputTree()
{
    char str[Maxsize];
    TreeNode* root;//root of the tree
    TreeNode* tempnode;//temp of node
    Queue* q;
    q=QueueInit();
   // int check=1;//check whether the is the lchild or rchild
    int temp;//temp of input


    root=NodeInit();
    enQueue(q,root);

    scanf("%s",str);
    //scan the tree
    for(int i=0;str[i]!='\0';)//cut the string and push them into a tree
    {
        temp=cut_trans_str(str,&i);//cut a number or null from the long-input string
        tempnode=deQueue(q);//get the current node
        if(temp==0)
        {
            if(tempnode==root)
                return NULL;
            enQueue(q,NULL);
            enQueue(q,NULL);
        }
        else
        {
            tempnode->data=temp;
            tempnode->lchild=NodeInit();
            tempnode->rchild=NodeInit();
            enQueue(q,tempnode->lchild);
            enQueue(q,tempnode->rchild);
        }
        
    }
    
    DestroyQueue(q);

    Cut_tail(root);


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

// int Input(int * reg)
// {
//     int check=0;//check if the input is the end
//     char str[10];//the temp string 
//     check=scanf("%s",str);//scan the string 
//     if(check==-1)
//         check=0;
//     if(str=="null")//if input null
//     {
//         *reg=0;//the temp in InputTree is NULL
//     }
//     else
//     {
//         *reg=atoi(str);
//     }
//     return check;
// }

int cut_trans_str(char* str,int *i)
{
    int k;
    char result_s[10];
    for(k=0;str[*i]!='\0';(*i)++,k++)
    {
        result_s[k]=str[*i];
        if(str[*i]==',')
        {
            (*i)++;
            break;
        }
    }
    result_s[k]='\0';
    

    if(!strcmp(result_s,"null"))
         return 0;
    else
    {
        return atoi(result_s);
    }

}


int Thief(TreeNode* root,int eat)
{
    int maximum=0;
    
    if(root==NULL)
        return maximum;

    if(eat==1)
    {
        maximum+=root->data;
        maximum+=Thief(root->lchild,0);
        maximum+=Thief(root->rchild,0);
    }
    if(eat==0)
    {
        int left_y=Thief(root->lchild,1);
        int right_y=Thief(root->rchild,1);
        int left_n=Thief(root->lchild,0);
        int right_n=Thief(root->rchild,0);//4 above are calculating which method is the best

        int left=left_y>left_n?left_y:left_n;//get the best left
        int right=right_y>right_n?right_y:right_n;//get the best right

        maximum=left+right;
    }


    return maximum;
}
