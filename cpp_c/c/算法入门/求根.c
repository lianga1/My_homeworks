/*
�������õ�������x^3-x-1 ��1.5�����ĸ������Ȼ�Ϊ��ʽx=g(x),��x=(x+1)^(1/3) 
Ȼ��ÿ������µĸ�����epsilon=0.000005�Ƚϣ�����������̣�������÷���Ҫ��ĸ��� 
ע�⣺Ҫ��g(x)�ľ���ֵ�ڸ��ĸ���С��1�����򲻻����� 
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
	printf("����%d�Σ�����%.5f\n",m,x);
	
	
	return 0;
}
