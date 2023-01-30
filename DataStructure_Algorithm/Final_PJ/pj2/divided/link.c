#include "link.h"


LinkNode* CreateEmptyList(){
    LinkNode* n= (LinkNode*)malloc(sizeof(LinkNode));
    n->loc.x=-1;
    n->loc.y=-1;
    n->loc.value=-1;
    n->next=NULL;
    return n;
}

LinkNode* List_pushback(LinkNode* prior,Location data){

    LinkNode* n= (LinkNode*)malloc(sizeof(LinkNode));
    n->next=NULL;
    n->loc=data;
    prior->next=n;
    return n;
}
LinkNode* List_add_from_front(LinkNode* head,Location data){

    LinkNode* p= (LinkNode*)malloc(sizeof(LinkNode));
    p->loc=data;
    p->next=head->next;
    head->next=p;
    return head;
}
LinkNode* ReverseList(LinkNode* new_head,LinkNode* origin_head){
    LinkNode* n;
    for(n=origin_head; n != NULL;n=n->next){
        List_add_from_front(new_head,n->loc);
    }
    return new_head;
}
void DestroyList(LinkNode* head){
    LinkNode* p;
    LinkNode* q;
    for(p=head;p!=NULL;p=q){
        q=p->next;
        free(p);
    }
}
