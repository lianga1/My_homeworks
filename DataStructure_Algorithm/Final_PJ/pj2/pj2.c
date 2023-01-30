#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include <malloc.h>
#include <stdlib.h>
#define alpha 0.3
#define beta 0.3
#define step 0.1

typedef struct v{
    double x;
    double y;
}vector;

typedef struct l{
    double x;//x coordinate
    double y;//y coordinate
    vector v;//record the comeway of the point
    double value;//record the value of the point
} Location;

typedef struct n{
    Location loc;
    struct n *next;
} LinkNode;
Location best_location;//record the location with the best value

double target(Location *loc);//calculate the value of the location
Location get_random_location();//get a random location
Location get_new_location(Location cur);//get a new location by the current location, best location and random location
Location move(Location cur,double x,double y);//do the move operation




LinkNode* CreateEmptyList();
LinkNode* List_pushback(LinkNode* prior,Location data);
LinkNode* List_add_from_front(LinkNode* head,Location data);
LinkNode* ReverseList(LinkNode* new_head,LinkNode* origin_head);
void DestroyList(LinkNode* head);

//description:this program is to realize a random search algorithm


#define MAX 1000



LinkNode* Init();
 

int main()
{
    srand(time(NULL));
    int unchanged=0;
    LinkNode* head = Init();//initialize the whole search
    LinkNode* p = head->next;
    Location new_point=head->next->loc;
    //TODO:go the search algorithm
    for(int i=0;i<MAX;i++)
    {

        new_point=get_new_location(new_point);
        

        if(target(&new_point)>target(&best_location))
        {
            best_location=new_point;
            unchanged=0;
        }
        else
        {
            unchanged++;
        }

        p=List_pushback(p,new_point);
        

        if(unchanged>100||best_location.value>0.99999)
        {
            break;
        }

        printf("the %dth time:the best location is (%lf,%lf),the value is %lf \n",i+1,best_location.x,best_location.y,best_location.value);
    }
    // for(LinkNode *p=head->next;p!=NULL;p=p->next)
    // {
        
    //     printf("(%lf,%lf),%lf, (%lf,%lf) \n",p->loc.x,p->loc.y,p->loc.value,p->loc.v.x,p->loc.v.y);
    // }



    DestroyList(head);
    
    return 0;
}

LinkNode* Init()
{
    LinkNode* head = CreateEmptyList();
    LinkNode* h=CreateEmptyList();
    Location cur;
    Location loc=get_random_location();
    cur=loc;
    for(int i=0;i<10;i++)//summon the first 10 points
    {
        cur=get_random_location();
        h=List_pushback(h,cur);
        if(target(&cur)>target(&best_location))
        {
            best_location=cur;
        }
    }
    List_pushback(head,cur);
    DestroyList(h);
    return head;
}


double target(Location *loc)
{
    return loc->x*loc->x*(1-loc->y)+loc->y;
}
Location get_random_location()
{
    Location loc;
    loc.x=rand()/((double)RAND_MAX+1.0);
    loc.y=rand()/((double)RAND_MAX+1.0);
    loc.value=target(&loc);
    return loc;
}
Location get_new_location(Location cur)
{
    Location new_loc;

    double x=alpha*cur.v.x+beta*(best_location.x-cur.x)+(1-alpha-beta)*(rand()*2/(double)(RAND_MAX+1)-1);
    double y=alpha*cur.v.y+beta*(best_location.y-cur.y)+(1-alpha-beta)*(rand()*2/(double)(RAND_MAX+1)-1);//get the new vector
    x=x/sqrt(x*x+y*y)*step;
    y=y/sqrt(x*x+y*y)*step;//normalize the vector
    new_loc=move(cur,x,y);//

    return new_loc;
}
Location move(Location cur,double x,double y)
{
    Location new_loc;
    new_loc.x=cur.x+x;
    new_loc.y=cur.y+y;
    new_loc.v.x=x;
    new_loc.v.y=y;
    if(new_loc.x<0)    //check if new_loc is out of the range
    {
        new_loc.x=-new_loc.x;
    }
    else if(new_loc.x>1)
    {
        new_loc.x=(new_loc.x-1)*(-1)+1;
    }
    if(new_loc.y<0)
    {
        new_loc.y=-new_loc.y;
    }
    else if(new_loc.y>1)
    {
        new_loc.y=(new_loc.y-1)*(-1)+1;
    }

    new_loc.value=target(&new_loc);
    return new_loc;
}
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
