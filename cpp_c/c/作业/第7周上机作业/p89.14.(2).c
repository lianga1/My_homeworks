#include<stdio.h>

int main()
{
	int a[256],b[15][15];
	int n,i,k=0;
	int col=0,row=0;
	printf("���������");
	scanf("%d",&n); 
	
	for(i=0;i<=n*n-1;i++)//��ʼ��ֵ 
	{
		a[i]=i+1;
		
	}	
	for(i=0;i<=n-1;i++)//b�ĳ�ʼ��ֵ 
	{
		for(k=0;k<=n-1;k++)
		{
			b[i][k]=0;		
		}

	}
	k=0;//����k
	 
	while(k<=n*n-2)//����Ĵ�ѭ��������תȦ 
	{

	for(i=col;i<=n-col-1;i++)//b�и�ֵ 
	{
/**		if(b[row][i]!=0)//����Ҫ��ֵ������λ���Ѿ���ռ�� 
		{
		check++;
		break;
		}*/
		
		b[row][i]=a[k];
		k++; 
		
	}

	for(i=row+1;i<=n-row-1;i++)//b���и�ֵ ,k��a���ܻ��� 
	{
/*		if(b[i][n-col-1]!=0)
			{
				check++;
				break;
			}*/
		b[i][n-col-1]=a[k];
		k++;
	}

	for(i=n-col-2;i>=col;i--)//b���з���ֵ
	{
/*		if(b[n-row][i]!=0)
			{
				check++;
				break;
			}*/
		b[n-row-1][i]=a[k];
		k++;
	} 
	for(i=n-row-2;i>=row+1;i--)//b���з���ֵ 
	{
/*		if(b[i][col-1]!=0)
			{
				check++;
				break;
			}*/
		b[i][col]=a[k];
		k++;
	}
	/*if(check==4)
		break;*/
		
		row++;
		col++;
	}
	if (n%2==1)
	{
		b[(n)/2][(n)/2]=n*n;
		
		
	}
	for(i=0;i<=n-1;i++)
	{
		for(k=0;k<=n-1;k++)
		{
			printf("%d\t",b[i][k]);
			
		}
		printf("\n");
		
	}
	
	 
		
	
	return 0;
}
