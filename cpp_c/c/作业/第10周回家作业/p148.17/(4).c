#include<stdio.h>
#include<string.h>

void chain(char *s1,char *s2)
{
	for(;*s1!='\0';s1++);
	
	for(;*s2!='\0';)
	{
		*s1++=*s2++;
	}
	*s1='\0';
}

int main()
{
	char s1[100],s2[100];
	
	printf("请输入前面的字符串\n");
	gets(s1);
	
	printf("请输入后面的字符串\n");
	gets(s2);
	
	chain(s1,s2);
	
	puts(s1);
	
	return 0;
}
