#include<stdio.h>

int gcd(int a,int b)
{
	printf("%d %d\n",a,b);
	
	if(a==b)
	return a;
	
	if(a>b)
	return gcd(a-b,b);
	
	if (a<b)
	return gcd(a,b-a);
	
	
}

int main()
{
	int a,b,g;
	do
	{
		printf("请输入两个大于1的正整数");
	
		scanf("%d%d",&a,&b);
		if(a*b<=1)
		printf("输入非法");
		
		 
	}
	while(a*b<=1);
	g=gcd(a,b);
	printf("最大公约数是%d",g);
	
	return 0;
}
