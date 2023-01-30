#include<stdio.h>
int main()
{
	float x=1.2545,y;
	int i;
	i=x*1000;
	if(x*1000-i>=0.5)
		i+=1;
	y =i/1000.0;
	printf("%f\n",y);
	
	return 0;
}
