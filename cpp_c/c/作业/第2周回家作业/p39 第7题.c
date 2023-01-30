#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char c;
	long k;
	float f;
	double x;
	
	scanf("i=%d c=%c",&i,&c);
	scanf("k=%ld",&k);
	scanf("f=%f x=%lf",&f,&x);//输入对应的值 
	
	printf("i = %d c = '%c'",i,c);
	printf("k = %ld",k);
	printf("f = %f x = %lf",f,x);
	
	system("pause");
	
	return 0;
}
