#include<stdio.h>
int main()
{
	int a[1000],i,k;
	for (i=0;i<=999;i++)
	{
		if(i<=1)
			a[i]=0;
		else
			a[i]=1;
	}
	for(i=0;i<=999;i++)
	{
		if(a[i]==1)
		{
			for(k=2;i*k<=999;k++)
			{
				a[i*k]=0;
			}
		}
		
	}
	for(i=0;i<=999;i++)
	{
		if(a[i]==1)
			printf("%dÊÇÖÊÊý\n",i);
		
	}
	
	return 0;
}
