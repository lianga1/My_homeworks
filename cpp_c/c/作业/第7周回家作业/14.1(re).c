//filename:p89.14.1.c(renewed)
#include<stdio.h>

int main()
{
	int a[256];
	int b[16][16];
	int n,i,k,sum;
	
	printf("�����������������15\n");
	scanf("%d",&n); 
	for(i=0;i<=255;i++)//һά�����ʼ���� 
	{
		a[i]=i+1;
	}
	for(i=0;i<=15;i++)//��ά�����ʼ�� 
	{
		for(k=0;k<=15;k++)
		{
			b[i][k]=0;
		}
	}
	k=0;// k reset
	
	for(sum=0;sum<=n*2-2;sum++)
	{
		if(sum>=n)//��벿�� 
		{
		if(sum%2==0)
		{
			for(i=sum-n+1;i<n;i++)
			{
				b[i][sum-i]=a[k];
				k++;
			}
		}
 		if(sum%2==1)
		{
			for(i=sum-n+1;i<n;i++)
			{
				b[sum-i][i]=a[k];
				k++;
			}
		}
			
		}
		else{//ǰ�벿�� 
			
		if(sum%2==0)//������ 
		{
			for(i=0;sum-i>=0;i++)
			{
				b[i][sum-i]=a[k];
				k++;
			}
		}
 		if(sum%2==1)//������ 
		{
			for(i=0;sum-i>=0;i++)
			{
				b[sum-i][i]=a[k];
				k++;
			}
		}	
		}
		
		
	} 
	for(i=0;i<=n-1;i++)//��� 
	{
		for(k=0;k<=n-1;k++)
		{
			printf("%d\t",b[i][k]);
			
		}
		printf("\n");
		
	}
	
	
	return 0;
}
