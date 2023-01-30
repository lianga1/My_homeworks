#include <stdio.h>
#include <malloc.h>
#define MaxSize 10000


typedef struct 
{
    char data[MaxSize];
    int lenth;
    /* data */
}string;

string * string_init();//initialize the string
void StrAssign(string *s,char str[]);
void Get_Next(string *str,int next[]);//get the next array of the string
void Get_Next_I(string *str,int next_i[]);
int KMP(string *ori_str,string *mod_str);//use KMP get the position of the understring
void Destroy_string(string *s);

int main()
{
    string *ori_str=string_init();
    string *mod_str=string_init();//init the original and modified string

    char temp_str[MaxSize];

    scanf("%s",temp_str);
    StrAssign(ori_str,temp_str);//input the ori_string

    scanf("%s",temp_str);//input the mod string
    StrAssign(mod_str,temp_str);

    int target = KMP(ori_str,mod_str);//use KMP to find the understring
    if(target==-1)//judge whether the string is found
        printf("Not found");
    else
        printf("%d",target);

    Destroy_string(ori_str);
    Destroy_string(mod_str);//destroy the strings
    return 0;

}

string * string_init()//initialize the string
{
    string *s ;
    s=(string *)malloc(sizeof(string));
    s->lenth=0;
    return s;
}

void StrAssign(string *s,char str[])
{
    int i; 
    for(i=0;str[i]!='\0';i++)
        s->data[i]=str[i];
    s->lenth=i;
}

void Get_Next(string *str,int next[])//get the next array of the string
{
    int j,k;
    j=0;k=-1;
    /*
        j refers to the current position of which we will fill the next_Array,scan the string at the same time
        
        k refers to the value of next_Array and help to find the return position of longest matching string

    */
    next[0]=-1;
    while(j<str->lenth-1)
    {
        if(k==-1||str->data[j]==str->data[k])//when return to the next[0] or start of the scan or the matching is continueing
        {
            k++;j++;//the value plus and the scan position push 1
                    //so whatever the k changes .the j always push 
                    //whats more the k value changes according to the last k;
            next[j]=k;//get the current position's longest front string
        }
        else k=next[k];//let the k return to the previous possible longest front string
    }
    
    
}

void Get_Next_I(string *str,int next_i[])
{
    int j=0,k=-1;
    next_i[0]=-1;
    while(j<str->lenth)
    {
        if(k==-1||str->data[k]==str->data[j])
        {
            j++;k++;
            if(str->data[k]!=str->data[j])
                next_i[j]=k;
            else 
                next_i[j]=next_i[k];
        }
        else
            k=next_i[k];
    }
}

int KMP(string *ori_str,string *mod_str)//use KMP get the position of the understring
{
    int next[MaxSize];
    int i=0,j=0;

    Get_Next_I(mod_str,next);//get the next_Array of the mod string

    while(i<ori_str->lenth &&j<mod_str->lenth)//scan the origin string ,but dont out of the mod string,if mod ends , the string is matched,if ori ends,the string is not matched
    {
        if(ori_str->data[i]==mod_str->data[j]||j==-1)//if the current char is matched , or when return to the first
        {
            i++;j++;//go to the next position
        }
        else
            j=next[j];
    }
    if(j>=mod_str->lenth)
        return i-mod_str->lenth;
    else
        return -1;

}

void Destroy_string(string *s)
{
    free(s);
}