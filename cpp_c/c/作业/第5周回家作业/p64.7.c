#include<stdio.h>

int main()
{
	int a,b;
	
	for (a=1;a<=10;a++)
	{
		b=a*a;
		printf("%d的平方是%d\n",a,b);
		b=a*a*a;
		printf("%d的立方是%d\n",a,b);
		
	}
	return 0;
} 
