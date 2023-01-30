#include<stdio.h>
#include "BTree.h"
//description: realize a dynamic huffman coding tree
//input: a string from a text file
//output: a huffman coding file with .hf extension

void Tick(BTree* btree,int changed_position);
void output(BTree* btree, char c,FILE* fp);
int main()
{
    BTree *btree=CreateBTree(NYT);
    FILE* f;

    f=fopen("C:\\Users\\18381\\Desktop\\dev_env\\DataStructure_Algorithm\\Final_PJ\\pj3\\devided\\test.txt", "r");
    FILE* hf;
    hf=fopen("C:\\Users\\18381\\Desktop\\dev_env\\DataStructure_Algorithm\\Final_PJ\\pj3\\devided\\result.hf", "wb");
    char c;
    c=getc(f);

    while(c!=EOF)
    {
        if(SeekChar(btree,c)==-1)//if the character is not in the tree
        {
            BTree* son=CreateBTree(c);
            Merge(btree,son ,SeekChar(btree, NYT));
        }
         //write the huffman coding
        output(btree, c, hf);
        Tick(btree,SeekChar(btree,c));
        c=getc(f);
    }



    return 0;
}

// Path: BTree.c
void Tick(BTree* btree,int changed_position)
{
/*
description:
tick every time a character is read
change the weight of the recursive parent,
if the number of the parent is smaller than the number of all the other nodes with same weight,
change the two nodes and go on.
input:
btree: the tree
changed_position: the position of the node which is changed

*/
    int i=changed_position;
    int j;//j refers to the position of the position of the node with biggest number among the same weight
    while(i!=-1)//in this circulation, the node will recursively add the weight and change the position if nessesary
    {
        //the first step is to add the weight of the node ,but need to judge if it need to change the position
        
        if(btree->btree[i].parent!=-1)//if the node is not the root
        {
            j=i;
            while(btree->btree[j].weight==btree->btree[i].weight&&j!=-1)//if the node has the same weight with its parent and is not the root
                j=SeekNum(btree,btree->btree[j].num+1);

            j=SeekNum(btree,btree->btree[j].num-1);
            if(btree->btree[j].num>btree->btree[i].num && j!=btree->btree[i].parent)
            {
                Exchange(btree,i,j);
            }
        }
        btree->btree[i].weight++;
        i=btree->btree[i].parent;//the last step is to change the parent
    }

}

void output(BTree* btree, char c,FILE* fp)
{
    int position=SeekChar(btree, c);
    int size=0;
    int stack[128];
    while(position!=-1)
    {
        stack[size]=position;
        size++;
        position=btree->btree[position].parent;
    }
    for(int i=size-1;i>0;i--)
    {
        if(i==1 && btree->btree[stack[i-1]].weight==0)
        {
            fwrite(&c, sizeof(char), 1, fp);
            fflush(fp);
            return;
        }
        else
        {
            if(btree->btree[stack[i]].leftchild==stack[i-1])//print 0 if the node is the left child
            {
                fwrite("0", sizeof(char), 1, fp);
            }
            else//print 1 if the node is the right child
            {
                fwrite("1", sizeof(char), 1, fp);
            }
        }
    }
    fflush(fp);
}
