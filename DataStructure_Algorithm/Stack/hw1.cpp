#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 100

typedef struct {
    char data[MaxSize];
    int top;
}SqStack;//define the stack

void InitStack(SqStack *&s);
bool Push(SqStack *& s, char c);
bool Pop(SqStack* &s,char &c);
bool StackEmpty(SqStack *s);

int main(){
    SqStack *stack;
    InitStack(stack);
    char str_in[MaxSize];
    int i=0;//the iterator
    char c=0;//the temp char
    scanf("%s",str_in);//input the string

    for(i=0;i<strlen(str_in);i++)//iterate the string
    {
        switch (str_in [i])//if the left half,push;if the right half,check wether the top is its related left half
        {
        case '(': 
            Push(stack,str_in[i]);
            break;
        case ')': 
            if(!Pop(stack, c))
                {printf("NO");return 1;}
            if(c!='(')
                {printf("NO");return 1;}
            break;
        case '[': Push(stack,str_in[i]);break;

        case ']': 
            if(!Pop(stack, c))
                {printf("NO");return 1;}
            if(c!='[')
                {printf("NO");return 1;}break;
        case '{': Push(stack,str_in[i]);break;
        case '}': 
            if(!Pop(stack, c))
                {printf("NO");return 1;}
            if(c!='{')
                {printf("NO");return 1;}break;
        default:
            break;
        }
    }
    if(!StackEmpty(stack))
    {
        printf("NO");
        return 1;
    }
    printf("YES");
    free(stack);
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
bool Push(SqStack *& s, char c)
{
    if(s->top==MaxSize-1)
        return false;
    s->top++;
    s->data[s->top]=c;
    return true;
}
bool Pop(SqStack*& s,char &c)
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