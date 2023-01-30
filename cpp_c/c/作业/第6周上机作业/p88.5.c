#include <stdio.h>

int main()
{
	int a[40],i,b,count=1,countn=0;
	for(i=0;i<=39;i++)
	{
		printf("请输入第%d个数,或以字母n结束输入\n",i+1);
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
	printf("最长平台是%d",countn);
	
	
	return 0;
} 
