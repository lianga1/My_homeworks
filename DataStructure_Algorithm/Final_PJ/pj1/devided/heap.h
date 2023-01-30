#ifndef __HEAP_H__
#define __HEAP_H__
#define NAME 20
#define MAX 100
typedef struct Node{
    int id;

    char name[NAME];
    int priority;
}Node;
typedef struct Heap{
    Node data[MAX];
    int size;

}Heap;

void sift(Heap *heap,int low,int high);//sift the heap
void Heapsort(Heap *heap);//sort the heap
void shiftup(Heap *heap,int index);//shift up the heap
void shiftdown(Heap *heap,int index);//shift down the heap
#endif