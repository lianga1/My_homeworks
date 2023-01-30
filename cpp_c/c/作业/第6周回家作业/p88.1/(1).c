#include<stdio.h>

int main()
{
	int a[100],i;
	for(i=0;i<=99;i++)
	{
		a[i]=i*2;
	}
	for(i=4;i<=99;i+=4)
	{
		printf("%d\n",a[i]);
	}
	
	return 0;
}
