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
	printf("���������鳤��n\n");
	scanf("%d",&n); 
	
	printf("������Ҫ������λ��\n");
	scanf("%d",&m); 
	
	printf("����������\n");
	for(i=0;i<=n-1;i++)
	scanf("%d",&a[i]);
	
	nexchange(a,n,m);
	
	printf("���Ϊ\n");
	for(i=0;i<=n-1;i++)
	printf("%d\n",a[i]);
	
	
	
	return 0;
	
}
