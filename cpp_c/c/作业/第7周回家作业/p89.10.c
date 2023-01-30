#include<stdio.h>

int main()
{
	int a[10];
	int i,check=1,bigger,mid;
	for (i=0;i<=9;i++)
	{
		while(1)
		{
			printf("请输入第%d个数字",i+1);
			scanf("%d",&a[i]);
			if(a[i]<=9&&a[i]>=0)
			break;
			else
			{
				printf("输入非法,重新输入\n");
				 continue;
			}
		}
	}
	
	for(i=0;i<=8;i++)
	{
		if(a[i]>=a[i+1])
		{
			check++;
		}
	}
	if(check==9)
		printf("这已经是最大的了");
	else
	{
		i=check;
		for(;i<=8;i++)
		{
			if(a[i]<a[i+1])
			{
				bigger=i;
			}
		}
		mid=a[bigger];
		a[bigger]=a[bigger+1];
		a[bigger+1]=mid;
		
	} 
	printf("变换后的整数是：");
	for(i=0;i<=9;i++)
	{
		printf("%d",a[i]);
	}
	
		
	return 0;
}
