#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,j,ans;
	
	scanf("%d %d",&i,&j);
	
	ans = i +j;
	printf("%d\n",ans);
	ans = i - j;
	printf("%d\n",ans);
	ans = i * j;
	printf("%d\n",ans);
	ans = i/j;
	printf("%d\n",ans);
	ans = i % j;
	printf("%d\n",ans);
	return 0;
} 
