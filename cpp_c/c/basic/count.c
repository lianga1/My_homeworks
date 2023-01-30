#include <stdio.h>
void main()
{
    char str[18]="I am a good boy",c; 
int num=0, i=0;
printf("\nPlease input a number:");
scanf("%c", &c);
while(str[i]!='\0')
{
if(str[i]==c) 
{num++;

i++;}
}
printf("Have %d character %c in str",num,c); 

}