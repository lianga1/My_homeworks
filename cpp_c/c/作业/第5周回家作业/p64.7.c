#include<stdio.h>

int main()
{
	int a,b;
	
	for (a=1;a<=10;a++)
	{
		b=a*a;
		printf("%d��ƽ����%d\n",a,b);
		b=a*a*a;
		printf("%d��������%d\n",a,b);
		
	}
	return 0;
} 
