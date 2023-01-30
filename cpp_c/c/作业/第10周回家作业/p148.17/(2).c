#include<stdio.h>

int scount (char *s)
{
	int i;
	
	for(i=0;*s!='\0';s++)
	{
		i++;
		
	}
	
	
	return i;
	
}

int main()
{
	int a;
	char s[]="I like programmming.";
	a=scount(s);
	printf("%d",a);
	
	
	
	return 0;
} 
