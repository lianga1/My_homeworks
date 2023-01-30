#include<stdio.h>

int main()
{
	int a[100];
	int key=256,i;
	for(i=0;i<=99;i++)
	{
		a[i]=i*i;
	}
	for(i=0;i<=99;i++)
	{
		if (a[i]==key)
		{
			printf("这是第%d项",i+1);
			break;
		}
	}
	
	return 0;
}
