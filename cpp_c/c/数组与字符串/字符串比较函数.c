#include<stdio.h>
#include<string.h>

int main()
{
	char a[50],b[5];
	gets(a);
	gets(b);
	if(strcmp(a,b)>0)
		printf("yes");
	else
		printf("no");
		
	
	return 0;
} 
