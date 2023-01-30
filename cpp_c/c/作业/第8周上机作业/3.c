#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int k,ans1;
	srand(time(NULL));
	k=1+rand()%99;
	printf("Çë²Â²âÕâ¸öÊý×Ö\n");
	do
	{
	
	scanf("%d",&ans1);
	if(ans1==k)
	printf("Correct!") ;
	else if(ans1>k)
	printf("Maybe a little smaller\n");
	else if(ans1<k)
	printf("Maybe a little bigger\n");
	
	
	}
	while(k!=ans1);

	return 0;
	
}
