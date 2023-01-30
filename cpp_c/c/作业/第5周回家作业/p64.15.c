#include<stdio.h>
#include<math.h>
int main()
{
	int x,i;
	double ans=0,each=1;
	printf("ÇëÊäÈëxµÄÖµ\n");
	scanf("%d",&x);
	
	for (i=1;i<=1000000;i++)
	
	{
		ans=ans+each;
		each=each*x/i;
		
	}
	printf("%lf",ans);
	 
	return 0;
}
