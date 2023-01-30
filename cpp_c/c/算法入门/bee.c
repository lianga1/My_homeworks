#include<stdio.h>

int BPro(int gen)
{
	int a,b;
	
	a=1;b=0;
	for(int i=1;i<=gen-1;i++)
	{
		long c=b+1;
		b=a+b;
		a=c;
		
		printf("%d年后,有%d只a,%d只b\n",i,a,b);
		
	}
}

int main()
{
	int gen;
	scanf("%d",&gen);
	int num=BPro(gen);
	
	
	return 0;
} 
