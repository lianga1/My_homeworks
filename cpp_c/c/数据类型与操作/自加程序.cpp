#include <stdio.h>

int main()
{
	int x = 0;
	printf("x = %d\n", x++);
	printf("x = %d\n", ++x);// 自加符号与变量的位置决定先返回值还是先运算 
	
	return 0;
}
