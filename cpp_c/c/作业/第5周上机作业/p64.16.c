#include<stdio.h>
#include<math.h>

int main()
{
	int b;
	double a,pi=0;
	for (b=1;b<=1000000;b++)
	{
		a = pow(-1,b+1)*4/(2*b-1);
		
		pi= pi + a;
	}
	printf("%lf",pi);
	
	return 0;
}
