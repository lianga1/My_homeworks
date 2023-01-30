#define check(x) (int)(((x%4==0)&&(x%100!=0))||(x%400==0)?1:0)
#include<stdio.h>
int main()
{
	
	int a=2000;
	printf("%d\n",check(a));
	return 0;
	
	
}
