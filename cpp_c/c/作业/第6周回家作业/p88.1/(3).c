#include<stdio.h>
int main()
{
	int a[100];
	int i,k,mid;
	for (i=0;i<=99;i++)
	{
		a[i]=i;
	}
	for(i=0;i<=99;i++)
	{
		for(k=i+1;k<=99;k++)
		{
			mid=a[k];
			a[k]=a[i];
			a[i]=mid;
		}
	}
	for(i=0;i<=99;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
