#include<stdio.h>

void exchange(char **s1,char **s2)
{
	char *mid;
	
	mid=*s1;
	*s1=*s2;
	*s2=mid;
	
	
}

int main()
{
	
	char cs1[]="ShangHai";
	char cs2[]="BeiJing";
	printf("���ڵ�s1��%s��s2��%s\n",cs1,cs2);
	char *s1;
	s1=cs1;
	char *s2;
	s2=cs2;
	
	exchange(&s1,&s2);
	int i;
	printf("���ڵ�s1��");
	 
	for(;*s1!='\0';s1++)
	printf("%c",*s1);
	printf("���ڵ�s2��");
	 
	for(;*s2!='\0';s2++)
	printf("%c",*s2);	
	
	return 0;
}
