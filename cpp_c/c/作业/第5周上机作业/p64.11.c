#include<stdio.h>

int main()
{
	int a,i,k;
	
	scanf("%d",&a);
	
	for (i=1;i<=a;i++)
	{
		printf("%*c",a-i+1,' ');
		for(k=1;k<=i;k++)
			printf("*");
		printf("\n");
	}
	return 0;
} 
