#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define Maxsize 100000

typedef struct node{
    int LeftEdge;//refers to the left edge of the path
    int RightEdge;//refers to the right edge of the path
    int MaxBW;//refers to the original BW of the whole path
    int currentBW;//refers to the current available BW

    struct node* lchild;
    struct node* rchild;
}TreeNode;

TreeNode* NodeInit();//create a node;
TreeNode* BuildTree(int* BW,int LEdge,int REdge);//create a subtree including the leftedge to right edge of the tree

int Add_Occ(TreeNode* root,int Begin,int End,int temp);
void Free_Occ(TreeNode* root,int Begin,int End,int temp);

int main()
{
    int machines;//the number of machines
    int BW[Maxsize];//record the bw
    char note[5];//the number of 

    TreeNode* root;

    int Begin,End;//the temp of begin and end
    int temp;

    scanf("%d",&machines);

    for(int i=0;i<machines-1;i++)
        scanf("%d",&BW[i]);
    root=BuildTree(BW,0,machines-1);
    // free(BW);
    int ops;
    scanf("%d",&ops);
    for(int i=0;i<ops;i++)
    {
        scanf("%s",note);
        if(strcmp(note,"add")==0)//add a occupation
        {
            scanf("%d",&Begin);
            scanf("%d",&End);
            scanf("%d",&temp);
            if(Add_Occ(root,Begin,End,temp))
                printf("true\n");

        }
        else if(strcmp(note,"free")==0)//free the Bw
        {
            scanf("%d",&Begin);
            scanf("%d",&End);
            scanf("%d",&temp);
            Free_Occ(root,Begin,End,temp);
        }
        else break;//wrong input
    }

    return 0;
}

TreeNode* NodeInit()//create a node;
{
    TreeNode* n;
    n=(TreeNode*)malloc(sizeof(TreeNode));
    n->LeftEdge=0;
    n->RightEdge=0;
    n->currentBW=0;
    n->MaxBW=0;
    n->lchild=NULL;
    n->rchild=NULL;

    return n;
}

TreeNode* BuildTree(int* BW,int LEdge,int REdge)//create a subtree including the leftedge to right edge of the tree
{
    TreeNode* root;
    root=NodeInit();
    if(LEdge==REdge)//if the node is leaf
    {
        root->currentBW=root->MaxBW=0;
        root->lchild=root->rchild=NULL;
        root->LeftEdge=root->RightEdge=LEdge;
        return root;
    }
    // if(LEdge==REdge-1)//if the node is leaf on 1
    // {
    //     root->currentBW=root->MaxBW=*(BW+LEdge);
    //     root->lchild=BuildTree(BW,LEdge,(LEdge+REdge)/2);
    //     root->rchild=BuildTree(BW,(LEdge+REdge)/2+1,REdge);
    //     root->LeftEdge=LEdge;
    //     root->RightEdge=REdge;
    //     return root;
    // }
    root->LeftEdge=LEdge;
    root->RightEdge=REdge;
    root->lchild=BuildTree(BW,LEdge,(LEdge+REdge)/2);
    root->rchild=BuildTree(BW,(LEdge+REdge)/2+1,REdge);
    root->currentBW=root->MaxBW=root->MaxBW=*(BW+(LEdge+REdge)/2);
    //(root->lchild->MaxBW > root->rchild->MaxBW ? root->lchild->MaxBW:root->rchild->MaxBW);
    return root;

}


int Add_Occ(TreeNode* root,int Begin,int End,int temp)//Add an occupation of the current path
{
    // if(!Check_Path_Available(root,Begin,End,temp))
    //     return 0;
    if(Begin<root->LeftEdge ||End> root->RightEdge)
        return 0;
    // if(temp>root->currentBW)//check if the maximum can hold the temp
    //     return 0;
    if(root->lchild==NULL && root->rchild==NULL)//if the leaf node
    {
        return 1;
    }
    if(root->lchild!=NULL && End<=root->lchild->RightEdge)//below are not the leaf node of the tree
    {
        if(!Add_Occ(root->lchild,Begin,End,temp))
            return 0;
            // root->currentBW-=temp;
    }
    else if(root->rchild!=NULL && Begin>=root->rchild->LeftEdge)
    {
        if(!Add_Occ(root->rchild,Begin,End,temp))
            return 0;
            // root->currentBW-=temp;
    }
    else
    {
        if(Add_Occ(root,Begin,root->lchild->RightEdge,temp)&& Add_Occ(root,root->rchild->LeftEdge,End,temp))
        {
            if(root->currentBW>=temp)
                root->currentBW-=temp;
            else return 0;    
                
        }
        else  return 0;
    }


    return 1;    

}
void Free_Occ(TreeNode* root,int Begin,int End,int temp)//free an occupation of somewhere of the current path
{

    if(Begin<root->LeftEdge ||End> root->RightEdge)
        return ;
    // if(temp>root->currentBW)//check if the maximum can hold the temp
    //     return 0;
    if(root->lchild==NULL && root->rchild==NULL)//if the leaf node
    {
        return;
    //    root->currentBW=root->MaxBW >(root->currentBW+temp) ? (root->currentBW+temp) : root->MaxBW;
    }

    if(root->lchild!=NULL && End<=root->lchild->RightEdge)//below are not the leaf node of the tree
    {
        Free_Occ(root->lchild,Begin,End,temp);
            // root->currentBW=root->MaxBW >(root->currentBW+temp) ? (root->currentBW+temp) : root->MaxBW;
    }
    else if(root->rchild!=NULL && Begin>=root->rchild->LeftEdge)
    {
        Free_Occ(root->rchild,Begin,End,temp);
            // root->currentBW=root->MaxBW >(root->currentBW+temp) ? (root->currentBW+temp) : root->MaxBW;
    }
    else
    {
    if(Begin==End-1)
        {
            root->currentBW=root->MaxBW >(root->currentBW+temp) ? (root->currentBW+temp) : root->MaxBW;
            return ;
        }
        Free_Occ(root,Begin,root->lchild->RightEdge,temp);
        Free_Occ(root,root->rchild->LeftEdge,End,temp);
        root->currentBW=root->MaxBW >(root->currentBW+temp) ? (root->currentBW+temp) : root->MaxBW;
    }

}