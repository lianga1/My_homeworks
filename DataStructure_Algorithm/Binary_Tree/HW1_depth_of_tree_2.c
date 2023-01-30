#include <stdio.h>
#include <malloc.h>
#define Maxsize 1000

typedef struct 
{
    int data;
    int parent;
}BTNode;


typedef struct 
{
    BTNode data[Maxsize];
}BTree;

BTree* TreeInit();
int TreeHeight(BTree* tree);
void DestroyTree(BTree* tree);
void TreeInput(BTree* tree);



int main()
{



    return 0;
}