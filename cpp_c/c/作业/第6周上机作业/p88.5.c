#include <stdio.h>

int main()
{
	int a[40],i,b,count=1,countn=0;
	for(i=0;i<=39;i++)
	{
		printf("�������%d����,������ĸn��������\n",i+1);
		b=scanf("%d",&a[i]);
		if(b==0)
			{
				break;
				i=i-1;
			}
	}
	for(;i>=0;i--)
	{
		b=i-1;
		if (b>=0)
		{
			if(a[i]==a[b])
			{
				count++;
			}
			else
				count=1; 
			if(count>=countn)
				countn = count;
		}
		
	}
	printf("�ƽ̨��%d",countn);
	
	
	return 0;
} 
