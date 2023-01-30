//delta==32
#include<stdio.h>
#include<string.h>

void strans(char *slwr,char *supr)
{
	int a;
	
	for(;*slwr!='\0';)
	{
		a = *slwr;
		if(a>=97&&a<=122)
		{
			a-=32;
			*slwr=a;
			*supr++=*slwr++;
			
		}
		else
		{
			*supr++=*slwr++;
		}
	}
	*supr='\0';
}

int main()
{
	char slwr[100],supr[100];
	
	printf("ÇëÊäÈë×Ö·û´®\n");
	gets(slwr);
	
	strans (slwr,supr);
	
	puts(supr);
	
	return 0;
}
