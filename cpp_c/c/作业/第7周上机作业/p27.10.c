#include<stdio.h>
#include<string.h>

int main()
{
	char str[100];
	int i,lenth,ch;
	int countnum=0,countupr=0,countlwr=0,countelse=0;
	gets(str);
	for(i=0;i<=99;i++)
		{
			if(str[i]=='\0')
			{
				lenth=i;
				break;
			}
		}
	for(i=0;i<=lenth;i++)
		{
			ch=str[i];
			if(ch>=48&&ch<=57)
			countnum++;
			if(ch>=65 && ch<=90)
			countupr++;
			if(ch>=97 && ch<=122)
			countlwr++;
			else
			countelse++;
		}
		printf("�д�д%d����Сд%d��������%d��������%d��",countupr,countlwr,countnum,countelse);
		
	return 0;
}
