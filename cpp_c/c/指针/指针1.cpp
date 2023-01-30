# include <stdio.h>

int main()
{
	int *p,b,a;
	a = 1;
	p = &a;
	b = *p++;
	printf("%d\n",b);
	printf("%d\n",a);
	printf("%d",*p);
	
	return 0;
} 
