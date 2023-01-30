#include<stdio.h>
#include<string.h>

#include "queue.h"
#define COMMAND 20
int main()
{
    char command[COMMAND];
    Queue *p_queue=InitQueue();

    while(1)
    {
        scanf("%s",command);
        if(strcmp(command,"enqueue")==0)
        {
            Node temp;
            scanf("%s %d %d",temp.name,&temp.id,&temp.priority);
            Enqueue(p_queue,temp);
        }
        else if(strcmp(command,"dequeue")==0)
        {
            Dequeue(p_queue);
        }
        else if(strcmp(command,"print")==0)
        {
            PrintQueue(p_queue);
        }
        else if(strcmp(command,"quit")==0)
        {
            int num;
            scanf("%d",&num);
            quit(p_queue,num);

        }
        else if(strcmp(command,"update")==0)
        {
            Node temp;
            int num;
            int prior;
            scanf("%d %d",&num,&prior);
            temp=quit(p_queue,num);
            temp.priority=prior;
            Enqueue(p_queue,temp);
        }
        else if(strcmp(command,"end")==0)
        {
            break;
        }
        else
        {
            printf("error command");
        }
    }   
    return 0;


}