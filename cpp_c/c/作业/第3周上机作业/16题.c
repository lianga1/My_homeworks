#include<stdio.h>

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if (a>b)
	{
		if(a%b==0)
			printf("����������");
		else
			printf("���ڲ�����"); 
	}
	else if(a<b)
	{
		printf("С�ڲ�����");
		 
	}
	
	return 0;
	
}
