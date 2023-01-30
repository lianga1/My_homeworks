#include<stdio.h>
#include<stdlib.h>
int main ()
{
	int i = 1, j = 2, k = 3, u = 47215;
	float x = 2.2 , y = 3.4, z = -5.6;
	char c1 = 'a', c2 = 'b';
	printf("i = %-4dj = %-4dk = %-4d\n",i,j,k); 
	printf("x = %.5fy = %.5fz = %.5f\n",x,y,z);
	printf("x+y = %-6.2fy+z = %-6.2fz+x = %-6.2f\n",x+y,y+z,z+x);
	printf("u = %d\n",u);
	printf("c1 = '%c' or %d(ASCII)  c2 = '%c' or %d(ASCII)\n",c1,c1,c2,c2);
	system("pause");
	return 0;
	
}
