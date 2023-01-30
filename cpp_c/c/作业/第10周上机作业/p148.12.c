#include<stdio.h>
#include<string.h>


void single(char *s,char *c)
{
	int i,k,j=0;
	
	while(s[j]!='\0')
	{
		k=1;
		for(i=0;i<j;i++)
		{
			if(s[i]==s[j])
			{
				j++;
				k=0;
				break;
			}
			
		}
		if(k==1)
		*c++=s[j++];
		
		
	}
	
}


int main()
{
	char s[100],c[100]={0};
	
	gets(s);
	single(s,c);
	puts(c);
	
	return 0;
} 
