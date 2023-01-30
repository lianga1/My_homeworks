#include "BTree.h"

int number=128;
BTree* CreateBTree(char c)
{
    
    BTree* son = (BTree*)malloc(sizeof(BTree));
    if(c==NYT)//create the initialize tree
    {
        son->btree[0].isleaf=1;
        son->btree[0].data=NYT;
        son->btree[0].leftchild=-1;
        son->btree[0].rightchild=-1;
        son->btree[0].num=number;

        number--;
        son->btree[0].weight=0;
        son->size=1;
        son->btree[0].parent=-1;

        return son;
    }
    //create a new tree with a new character
    son->btree[0].isleaf= 0;

    son->btree[0].data = NYT;
    son->btree[0].leftchild = 1;
    son->btree[0].rightchild = 2;
    son->btree[0].num = 0;
    son->btree[0].weight = 0;
    son->btree[0].parent = -1;

    son->btree[2].data = c;
    son->btree[2].isleaf = 1;
    son->btree[2].leftchild = -1;
    son->btree[2].rightchild = -1;
    son->btree[2].num = number;
    number--;
    son->btree[2].weight = 0;
    son->btree[1].parent = 0;
    son->btree[2].parent = 0;
    son->btree[1].num = number;
    number--;
    son->btree[1].isleaf = 1;
    son->btree[1].data = NYT;
    son->btree[1].leftchild = -1;
    son->btree[1].rightchild = -1;
    son->btree[1].weight =0;
    son->size = 3;
    return son;
}

void Merge(BTree* mother, BTree * son, int i)
{
    mother->btree[i].isleaf=0;
    mother->btree[i].data=NYT;
    mother->btree[i].leftchild=mother->size;
    mother->btree[i].rightchild=mother->size+1;
    // mother->btree[i].weight=1;
    mother->btree[mother->size]=son->btree[1];
    mother->btree[mother->size+1]=son->btree[2];

    mother->btree[mother->size].parent=i;
    mother->btree[mother->size+1].parent=i;
    mother->size+=2;

    destroy(son);

}

int SeekChar(BTree* btree, char c)
{
    int i;
    for(i=0;i<btree->size;i++)
    {
        if(btree->btree[i].data==c && btree->btree[i].isleaf==1)
        {
            return i;
        }
    }
    return -1;
}
int SeekNum(BTree* btree, int num)
{
    int i;
    for(i=0;i<btree->size;i++)
    {
        if(btree->btree[i].num==num)
        {
            return i;
        }
    }
    return -1;
}
void Exchange(BTree* btree, int i, int j)//i refers to the number of the node which is not the biggest of the block, j refers to the number of the node which is the biggest of the block
{
    //change the parents
    int temp_left_i=-1;
    int temp_right_i=-1;
    int temp_left_j=-1;
    int temp_right_j=-1;
    if(btree->btree[i].parent!=-1)
    {
        if(btree->btree[btree->btree[i].parent].leftchild==i)
        {
            // btree->btree[btree->btree[i].parent].leftchild=j;
            temp_left_i=j;
        }
        else
        {
            // btree->btree[btree->btree[i].parent].rightchild=j;
            temp_right_i=j;
        }

    }
    int pare;
    pare=btree->btree[j].parent;
    btree->btree[j].parent=btree->btree[i].parent;
    if(pare!=-1)
    {
        if(btree->btree[pare].leftchild==j)
        {
            // btree->btree[pare].leftchild=i;
            temp_left_j=i;
        }
        else
        {
            // btree->btree[pare].rightchild=i;
            temp_right_j=i;
        }
    }
    if(temp_left_i!=-1)
    {
        btree->btree[btree->btree[i].parent].leftchild=j;
    }
    else
    {
        btree->btree[btree->btree[i].parent].rightchild=j;
    }
    if(temp_left_j!=-1)
    {
        btree->btree[pare].leftchild=i;
    }
    else
    {
        btree->btree[pare].rightchild=i;
    }



    btree->btree[i].parent=pare;

    int temp;
    temp=btree->btree[i].num;
    btree->btree[i].num=btree->btree[j].num;
    btree->btree[j].num=temp;
}

void destroy(BTree* btree)
{
    free(btree);
}