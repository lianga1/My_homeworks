#include<stdio.h>
#include<string.h>

int main()
{
	char str[100],ch;
	int i,k,count[26];
	gets(str);
	strlwr(str);
	for(i=0;i<=25;i++)
	{
		count[i]=0;
	}
	for(i=97;i<=122;i++)
	{
		ch=i;
		for(k=0;k<=99;k++)
		{
			if(str[k]=='\0')
			{
				break;
			}
			if(str[k]==ch)
				count[i-97]++;
		}
	}
	for(i=97;i<=122;i++)
	{
		ch=i;
		printf("%cÓĞ%d¸ö\n",ch,count[i-97]);
		
	}
	
	return 0;
}
