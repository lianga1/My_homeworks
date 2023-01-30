#include <stdio.h>
#include <malloc.h>
#define MaxSize 1000

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;


void InitStack(SqStack *&s);
bool Push(SqStack *& s, int c);
bool Pop(SqStack* &s,int &c);
bool StackEmpty(SqStack *s);
int GetTop(SqStack * &s);

int main()
{
    SqStack *store;
    InitStack(store);//initialize the Stack

    int num_of_cars;//the number of cars
    int i=0,k=0;//the iterator
    int head=0;//the head position of the current A rail
    int num;//the register of car_number
    int origin[MaxSize];//store the origin orger
    int target[MaxSize];//store the target order

    scanf("%d",&num_of_cars);//input the number of cars
    
    for(i=0;i<num_of_cars;i++)//input the original order of cars
    {
        scanf("%d",&origin[i]);
    }
    for(i=0;i<num_of_cars;i++)//input the target
    {
        scanf("%d",&target[i]);
    }
    for(k=0;k<num_of_cars;k++)//iterate the target list
    {

        for(i=head;i<=num_of_cars;i++)
        {
            if(i<num_of_cars&& target[k]==origin[i])
            {
                head++;
                break;
            }
            if(target[k]==GetTop(store))
            {
                int temp;
                Pop(store,temp);
                break;
            }
            
            else
                {
                    Push(store,origin[i]);
                    head++;
                    if(i==num_of_cars-1)
                    {
                        printf("NO");
                        return 0;
                    }
                }
            
        }

    }
    printf("YES");

    return 0;
}

void InitStack(SqStack *&s)
{ 
    s=(SqStack*)malloc(sizeof(SqStack));
    // for(int i=0;i<MaxSize-1;i++)
    // {
    //     s->data[i]='\0';
    // }
    s->top=-1;
} 
bool Push(SqStack *& s, int c)
{
    if(s->top==MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=c;
    return true;
}
bool Pop(SqStack*& s,int &c)
{
    if(s->top==-1)
        return false;
    c=s->data[s->top];
   s->top--;
   return true;
}
bool StackEmpty(SqStack *s){
    return s->top==-1;
}
int GetTop(SqStack * &s)
{
    if(s->top == -1)
        return false;
    return s->data[s->top];
}