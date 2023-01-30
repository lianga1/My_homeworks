#include<stdio.h>
#include<math.h>
#define true 1
#define false 0
#define N 2

int main()
{
	double a,i,check=0;
	scanf("%lf",&a);
	
	
	for (i=1;i<=32;i++)
	{
		if(a ==pow(2,i))
		
		{
			printf("%d",true);
			check=1;
			break;
		}
	}
	if(check ==0)
	printf("%d",false);
	
	return 0;
}
