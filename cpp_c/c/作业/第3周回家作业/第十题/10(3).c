#include<stdio.h>
int main()
{
	int i=1,j=1;
	j -= --i;
	printf("%d,%d",i,j);
	return 0;
}
