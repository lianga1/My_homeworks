#include<stdio.h>

int gcd(int a,int b)
{
	printf("%d %d\n",a,b);
	
	if(a==b)
	return a;
	
	if(a>b)
	return gcd(a-b,b);
	
	if (a<b)
	return gcd(a,b-a);
	
	
}

int main()
{
	int a,b,g;
	do
	{
		printf("��������������1��������");
	
		scanf("%d%d",&a,&b);
		if(a*b<=1)
		printf("����Ƿ�");
		
		 
	}
	while(a*b<=1);
	g=gcd(a,b);
	printf("���Լ����%d",g);
	
	return 0;
}
