#include<stdio.h>

double plus(double a,double b)
{
	a=a+b;
	return a;
	
	
}
double mul(double a,double b)
{
	a=a*b;
	return a;
	
}
double minus(double a,double b)
{
	a=a-b;
	return a;
	
}
double devide(double a,double b)
{
	double c;
	c=a/b;
	return c;
}



int main() 
{
	printf("������1�����мӷ�\n������2�����м���\n������3�����г˷�\n������4�����г���\n");
	
	int a;
	double x,y;
	double ans;
	scanf("%d",&a);
	
	typedef double (*CALTYPE)(double,double);
	
	
	CALTYPE calf;

	int check;
	
	switch (a) {
	case 1:
		calf=plus;
				
		break;
	case 2:
		calf=mul;
		break;
	case 3:
		calf=minus;
		break;
	case 4:
		calf=devide;
		break;
	default:
		printf("����Ƿ�\n"); 
		check=1;
		break;
	}
	
	
	
	
	
	
	do{
		check=0;
		printf("������������������");
		scanf("%lf%lf",&x,&y);
		
		ans=(*calf)(x,y);
	
	}
	
	
	
	while(check==1);
	
	printf("%lf",ans);
	
	
	
	return 0;
}
