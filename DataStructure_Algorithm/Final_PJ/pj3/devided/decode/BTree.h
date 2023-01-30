#ifndef __BTREE_H__
#define __BTREE_H__
//dynamic huffman tree
#include <stdio.h>
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
    BTNode btree[128];//the array of the tree
    int size;//the size of the tree
}BTree;


BTree* CreateBTree(char c);//create a new tree
void Merge(BTree* mother, BTree * son, int j);//merge one tree to the mother tree
int SeekChar(BTree* btree, char c);//seek the character in the tree
int SeekNum(BTree* btree, int num);//seek the node with the number in the tree
void Exchange(BTree* btree, int i, int j);
void destroy(BTree* btree);

#endif