#include<stdio.h>

void nexchange(int *a,int n,int m)
{
	int b[100];
	int i;
	
	for(i=0;i<=m-1;i++)
	{
		b[i]=*(a+n-m+i);
	}
	for(i=0;i<=n-m-1;i++)
	{
		*(a+n-1-i)=*(a+n-m-1-i);
	}
	for(i=0;i<=m-1;i++)
	{
		*(a+i)=b[i];
	}
	
}


int main()
{
	int a[100];
	int n,m;
	int i;
	printf("请输入数组长度n\n");
	scanf("%d",&n); 
	
	printf("请输入要调换的位数\n");
	scanf("%d",&m); 
	
	printf("请输入数组\n");
	for(i=0;i<=n-1;i++)
	scanf("%d",&a[i]);
	
	nexchange(a,n,m);
	
	printf("结果为\n");
	for(i=0;i<=n-1;i++)
	printf("%d\n",a[i]);
	
	
	
	return 0;
	
}
