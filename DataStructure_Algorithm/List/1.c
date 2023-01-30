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

int main()
{
    int number;
    int i;
    int data;
    scanf("%d",&number);

    LinkNode* head = CreateEmptyList();
    LinkNode* r=head;

    for(i=0;i<number;i++)
    {
        if(scanf("%d",&data))
        {
            r=List_pushback(r,data);
        }
        else
            break;
    }

    LinkNode* Reverse_head=CreateEmptyList();
    Reverse_head=ReverseList(Reverse_head,head);

    for(r=Reverse_head->next;r->next!=NULL;r=r->next)
        printf("%d ",r->data);

    return 0;
}

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
