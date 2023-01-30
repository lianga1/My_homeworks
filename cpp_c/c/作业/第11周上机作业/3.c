#include<stdio.h>
#include<string.h>

void  exchange(char (**a)[10],char (**b)[10])

{
	char (*mid)[10];

	mid=*a;
	*a=*b;
	*b=mid;
	
	

}


int main()
{
	int mid;
	char (*p[10])[10];
	char s[10][10];
	
	int i;
	for(i=0;i<=9;i++)
	p[i]=&s[i];
	for(i=0;i<=9;i++)
	gets(s[i]);

	for(i=0;i<=8;i+=2)
	
	{
	exchange(&p[i],&p[i+1]);
		
		
		
	}
	printf("输出结果是\n");
	
	for(i=0;i<=9;i++)
	puts(*p[i]);
	
	
	return 0;
}
