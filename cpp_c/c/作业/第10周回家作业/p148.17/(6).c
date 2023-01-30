#include<stdio.h>
#include<string.h>

void strans(char *se,char *st)
{
	for(;*se==' '||*se=='\t';se++);
	for(;*se!='\0';)
	{
		if(*se==' ')
		{
			for(;*++se==' ';);
			*st++=' ';
			*st++=*se++;
			
		}
		else
		{
			*st++=*se++;
			
		}
	}
	*st='\0';
}

int main()
{
	char se[100],st[100];
	
	printf("ÇëÊäÈë×Ö·û´®\n");
	gets(se);
	
	strans(se,st);
	
	puts(st);
	return 0;
	
}
