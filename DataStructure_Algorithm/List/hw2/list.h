#ifndef __LIST_H__
#define __LIST_H__
#include<stdio.h>
#include<malloc.h>

typedef struct LNode{
    int data;
    struct LNode* next;
}LinkNode;

LinkNode* CreateEmptyList();
LinkNode* List_pushback(LinkNode* prior,int data);
LinkNode* List_add_from_front(LinkNode* head,int data);
LinkNode* ReverseList(LinkNode* new_head,LinkNode* origin_head);



LinkNode* CreateEmptyList(){
    LinkNode* n= (LinkNode*)malloc(sizeof(LinkNode));
    n->data=-1;
    n->next=NULL;
    return n;
}

LinkNode* List_pushback(LinkNode* prior,int data){

    LinkNode* n= (LinkNode*)malloc(sizeof(LinkNode));
    n->next=NULL;
    n->data=data;
    prior->next=n;
    return n;
}
LinkNode* List_add_from_front(LinkNode* head,int data){

    LinkNode* p= (LinkNode*)malloc(sizeof(LinkNode));
    p->data=data;
    p->next=head->next;
    head->next=p;
    return head;
}
LinkNode* ReverseList(LinkNode* new_head,LinkNode* origin_head){
    LinkNode* n;
    for(n=origin_head; n != NULL;n=n->next){
        List_add_from_front(new_head,n->data);
    }
    return new_head;
}


#endif