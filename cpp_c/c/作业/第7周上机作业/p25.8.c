#include<stdio.h>

int main()
{
	int a[9][9];
	int i,k;
	for (i=0;i<=8;i++)
	{
		for(k=0;k<=8;k++)
		{
			a[i][k]=0;
		}
		
	}
	a[0][1]=1;
	for(i=1;i<=8;i++)
	{
		k=1;
		for(;k<=i+1;k++)
		{
			a[i][k]=a[i-1][k-1]+a[i-1][k];
			if(k==8)
			break;
		}
		
	}
	
	for(i=0;i<=8;i++)
	{
		printf("%*c",20-2*i,' ');
		printf("\n");
		for(k=1;k<=i+1;k++)
		{

			printf("%d\t",a[i][k]);
			if(k==8)
			break;
		}


	}
		printf("%d\t",1);
	return 0;
} 
