#define max(x,y,z) (int)((x>y?x:y)>z?(x>y?x:y):z)
#include<stdio.h>

int main()
{
	int x=3,y=2,z=1;
	printf("%d",max(x,y,z));
	
	return 0;
}
