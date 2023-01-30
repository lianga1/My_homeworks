#include<stdio.h>
#include<string.h>

int main()
{
	char str[1000],ch,str1[128];
	int i,k,count[128];
	gets(str);	
	for(i=0;i<=127;i++)
	{
		count[i]=0;
		str1[i]=0;
	}
	for(i=0;i<=127;i++)
	{
		ch=i;
		for(k=0;k<=999;k++)
		{
			if(str[k]=='\0')
			{
				break;
			}
			if(str[k]==ch)
				count[i]++;
		}
	}
	for(i=0,k=i;i<=127;i++)
	{
		ch=i;
		if(count[i]>=1)
		{
			str1[k]=ch;
			k++;
		}
	}
	for(i=0;i<=127;i++)
	{
		printf("%c\t",str1[i]);
	}
	
	
	return 0;
}
