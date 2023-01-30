/*
本题是用迭代法求x^3-x-1 在1.5附近的根，首先化为形式x=g(x),即x=(x+1)^(1/3) 
然后每次求出新的根，和epsilon=0.000005比较，反复这个过程，最终求得符合要求的根。 
注意：要求g(x)的绝对值在根的附近小于1，否则不会收敛 
*/


#include<stdio.h>
#include<math.h>

typedef double (*fpt)(double);

int rootfx (fpt g, double initRoot,double Epsilon,double *root)
{
	double x1,x0=initRoot;
	int n=0;
	do
	{
		printf("x%d=%.5f\n",n,x0);
		x1=x0;
		x0=(*g)(x1);
		n++;
	}while(fabs(x0-x1)>=Epsilon);
	*root=x0;
	printf("x%d=%.5f\n",n,x0);
	
	
	return n;
}
double f(double x)
{
	return pow(x+1,1.0/3.0);
}
int main()
{
	double x;
	int m=rootfx(f,1.5,0.000005,&x);
	printf("迭代%d次，根是%.5f\n",m,x);
	
	
	return 0;
}
