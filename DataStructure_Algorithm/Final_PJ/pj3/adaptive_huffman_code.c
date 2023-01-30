#include<stdio.h>

//dynamic huffman tree
#include <malloc.h>
#define NYT -1
typedef struct BN{
    char data;//the character
    int leftchild;//the index of the left child
    int rightchild;//the index of the right child
    int num;//the number of the node,from high to low
    int weight;//the weight of the node
    int isleaf;//if the node is a leaf
    int parent;//the index of the parent
}BTNode;
typedef struct BT{
    BTNode btree[130];//the array of the tree
    int size;//the size of the tree
}BTree;

int number=130;
BTree* CreateBTree(char c);//create a new tree
void Merge(BTree* mother, BTree * son, int j);//merge one tree to the mother tree
int SeekChar(BTree* btree, char c);//seek the character in the tree
int SeekNum(BTree* btree, int num);//seek the node with the number in the tree
void Exchange(BTree* btree, int i, int j);
void destroy(BTree* btree);


//description: realize a dynamic huffman coding tree
//input: a string from a text file
//output: a huffman coding file with .hf extension

void Tick(BTree* btree,int changed_position);
void output(BTree* btree, char c,FILE* fp);
int main()
{
    BTree *btree=CreateBTree(NYT);
    FILE* f;
    int i=0;
    f=fopen("C:\\Users\\18381\\Desktop\\dev_env\\DataStructure_Algorithm\\Final_PJ\\pj3\\Jane.txt", "r");
    FILE* hf;
    hf=fopen("C:\\Users\\18381\\Desktop\\dev_env\\DataStructure_Algorithm\\Final_PJ\\pj3\\encoded.hf", "wb");
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
        
        i++;
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
           
            while(btree->btree[j].weight==btree->btree[i].weight && j!=-1)//if the node has the same weight with its parent and is not the root
             {  
                   j=SeekNum(btree,btree->btree[j].num+1);
             }
            
            if(j==-1)//if the node is the root
            {
                btree->btree[i].weight++;
                i=btree->btree[i].parent;
                continue;
            }

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