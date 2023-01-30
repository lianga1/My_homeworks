#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "location.h"
#include "link.h"

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
        //TODO:summon a new point
        new_point=get_new_location(new_point);
        
        //TODO:judge the point is the best or not
        if(target(&new_point)>target(&best_location))
        {
            best_location=new_point;
            unchanged=0;
        }
        else
        {
            unchanged++;
        }
        //TODO:summon the next point with vector by D'=alpha*D+beta*(Dbest-D)+(1-alpha-beta)*Drandom
        p=List_pushback(p,new_point);
        
        //TODO:check whether to jump out the search algorithm
        if(unchanged>100||best_location.value>=0.99999)
        {
            break;
        }
        //TODO:print the result
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