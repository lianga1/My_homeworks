#include<stdio.h>

int a=2,c=4;


int f(int a,int *x)
{
	int b = 10;
	static int c = 20;
	b+=a++;
	c+=a+b;
	*x=c+2;
	
} 

int main()
{
	f(a,&c);
	printf("%d\t%d\n",a,c);
	f(c+3,&a);
	
	printf("%d\t%d\n",a,c);
	
	
	return 0;
}
