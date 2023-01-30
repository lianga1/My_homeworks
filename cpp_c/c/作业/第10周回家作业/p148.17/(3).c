#include<stdio.h>
#include<string.h>

void scpy (char *s2,char *s1,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		*s1++=*s2++;
		
	}
	*s1='\0';
}

int main()
{
	int n;

	
	char s1[100],s2[100];
	
	printf("ÇëÊäÈë×Ö·û´®\n");
	gets(s2);
	
	printf("ÇëÊäÈë½»»»Î»Êý\n");
	scanf("%d",&n);
	
	scpy(s2,s1,n);
	
	puts(s1);
	
	return 0;
}
