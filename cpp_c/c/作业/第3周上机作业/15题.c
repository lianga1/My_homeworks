#include<stdio.h>
int main()
{
	int a,b,c,ans1,max,min;
	float average;
	scanf("%d %d %d",&a,&b,&c);
	
	ans1 = a+b+c;
	printf("%d\n",ans1);
	
	max=a>b?a:b;
	max=max>c?max:c;
	printf("%d\n",max);
	
	min = a>b?b:a;
	min = min>c?c:min;
	printf("%d\n",min);
	
	average = ans1 / 3;
	printf("%f\n",average);
	
	return 0;
}
