#include<stdio.h>

int main()
{
	float r,r1,r2;
	scanf("%f %f",&r1,&r2);
	
	r = 1/(1/r1 + 1/r2);
	
	printf("%f",r);
	
	return 0;
}
