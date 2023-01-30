#include<stdio.h>
int main()
{
	int i=1,j=1,k;
	k = j+i++;
	printf("%d,%d\,%d",i,j,k);
	return 0;
}
