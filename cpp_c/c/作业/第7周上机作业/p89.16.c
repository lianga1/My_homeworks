#include<stdio.h>
#include<string.h>


int main()
{
	char str[100];
	int i,k,lenth,ch,ch2;
	gets(str);
	for(i=0;i<=99;i++)
	{
		if(str[i]=='\0')
		{
			lenth=i-1;
			break;
		}		
	
	}
	for(i=0;i<=lenth;i++)
	{
		ch=str[i];
		
		
		if (ch==32||ch==9||ch==10)
			//进行首尾移位操作
		{
			for(k=i;k<=lenth;k++)
			{
				str[k]=str[k+1];
			}
			lenth--;
			
		}
	}
/*	for(i=0;i<=lenth;i++)
	{
		ch=str[i];
		ch2=str[i+1];
		
		if ((ch==32||ch==9||ch==10)&&(ch2==32||ch2==9||ch2==10))
		for(k=i;k<=lenth;k++)
		{
			str[k]=str[k+1];
		}
		lenth--;
	}*/
	ch =str[0];
	if(ch==32||ch==9||ch==10)
	{
	
	for(i=1;i<=lenth;i++)
	
	printf("%c",str[i]);
	}
	else
	{
		for(i=0;i<=lenth;i++)	
		printf("%c",str[i]);
	}
	
	return 0;
} 
/*
去掉空格的函数
	int ch;
	ch=str[i];
	ch2=str[i+1]
	
	if ((ch==32||ch==9||ch==9)&&(ch2==32||ch2==9||ch2==9))
		//进行首尾移位操作
	{
		for(;i<=lenth;i++)
		{
			str[i]=str[i+1];
			
		}
		
	}
 
*/
