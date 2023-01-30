#include<stdio.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if (a>b)
	{
		if(a%b==0)
			printf("大于且整除");
		else
			printf("大于不整除"); 
	}
	else if(a<b)
	{
		printf("小于不整除");
		 
	}
	
	return 0;
	
}
