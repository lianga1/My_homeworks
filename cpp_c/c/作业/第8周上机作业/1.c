#include<stdio.h>

int main()
{
	int n;

	scanf("%d",&n);
	int triangle(n);
	
	triangle(n);

	
	return 0;
}
int triangle(int n)
{
	int i,k;
	for (i=1;i<=n;i++)
	{
		if(i==1)
		{
			printf("*\n");
			continue;
		}
		if(i==2)
		{
			printf("**\n");
			continue;
		}

		
		if(i==n)
		{
			for(k=1;k<=i;k++)
			{
				printf("*");
		
			}
			break;
		}
				printf("*");
				printf("%*c",i-2,' ');
				printf("*\n");
	}
	return 0;
	
}
