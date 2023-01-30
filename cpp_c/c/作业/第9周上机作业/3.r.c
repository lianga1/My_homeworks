//filename:week9.3.c(递归方法)
#include<stdio.h>

int i=0;

int go(int n)
{
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n>2)
		return go(n-1)+go(n-2);
		
}

int main()
{
	int n;
	printf("请输入要走几节台阶");
	scanf("%d",&n);
	i=go(n);
	printf("%d",i);
	
	return 0;
} 
