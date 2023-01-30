#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 5

void scan(char *(str[80]))
{
	int lenth;
	
	for(int i=0;i<=N-1;i++)
	{
		scanf("%s",str+i);
	}
	for(int i=0;i<=N-1;i++)
	{
		lenth = strlen(*(str[i]));
		str[i]=(char*)realloc(str[i],(lenth+1)*sizeof(char));
		int k=sizeof(str[i]);
		
		
	}
	
	for(int i=0;i<=N-1;i++)
	{
		printf("%d\n",sizeof(str[i]));
		
	}
	
}


int main()
{
	
	
//	int check;
//	int k[N];
	char *(str[80])[N];
	char s[80];
	
	
	for(int i=0;i<=N-1;i++)
	{
		scanf("%s",s); 
		*str[i]=s;
		for(int k=0;k<=80;k++)
		{
			if(s[k]!='\0')
			*str[i]=(char *)realloc(*str[i],(k+1)*sizeof(char));
		}
		
		
	}
		for(int i=0;i<=N-1;i++)
		{
			printf("%d\n",sizeof(str[i]));
		}
	
	
	
//	scan(str[80]);	
	
	
	return 0;
}
