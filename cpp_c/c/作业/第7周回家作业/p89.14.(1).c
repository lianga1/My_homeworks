#include<stdio.h> 

int main()
{
	int a[256],b[15][15];
	int i,k,u=2,n;
	int col=0,row=0; 
	for(i=0;i<=255;i++)//��ʼ��a��ʹ����˳������ 
		a[i]=i+1;
	for(i=0;i<=14;i++)//��ʼ��b��ʹ����ȫ1���� 
	{
		for(k=0;k<=14;k++)
		b[i][k]=1;
	}
	printf("���������,����1С��15\n");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++) //��b���ж��γ�ʼ����ʹ����Ч��Χ���0 
	{
		for(k=0;k<=n-1;k++)
		b[i][k]=0;
	}
	b[0][0]=1;
	b[1][0]=2;
	col++;
	while(u<=n*n-2) //�����ѭ�� 
	{
		for(i=row,k=col;i>=0&&k>=0&&b[i][k]==0;i--,k++)//б���� 
		{
			b[i][k]=a[u] ;
			u++;
		}
		// ���� 
		if(b[0][k]==0)//������������� 
		{
			b[0][k]=a[u];
			u++;
			row=1;
			col=k-1;
		}
		else//����ǶԳ�����Ч��Χ����� 
		{
			b[i+2][k-1]=a[u];
			u++;
			row=i+3;
			col=k-2;
			
		}
		
		for(i=row,k=col;i>=0&&k>=0&&b[i][k]==0;i++,k--)//б���� 
		{
			b[i][k]=a[u];
			u++;
			
		}
		//���� 
		if(b[i][0]==0)//������������� 
		{
			b[i][0]=a[u];
			u++;
			row= i-1;
			col= 1;
		}
		else//����ǳ�����Ч��Χ����� 
		{
			b[i-1][k+2]=a[u];
			u++;
			row=i-2;
			col=k+3;
		}
		
	}
	
	
	for(i=0;i<=n-1;i++)//��� 
	{
		for(k=0;k<=n-1;k++)
			printf("%d\t",b[i][k]);
		printf("\n");
	}
	return 0;
}
