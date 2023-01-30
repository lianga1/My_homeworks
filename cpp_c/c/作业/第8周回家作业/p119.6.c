#include<stdio.h>

int main()
{
	int i,j=0,k;
	for(i=2;i<=1000;i++)
	{
		
		for(k=1;k<i;k++)
		{
			if(i%k==0)
			{
				j+=k;
			}
		}
		if(j==i)
		printf("%d\n",i);
		j=0;
	}
	return 0;
}
