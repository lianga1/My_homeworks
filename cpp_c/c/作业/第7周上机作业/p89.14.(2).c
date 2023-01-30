#include<stdio.h>

int main()
{
	int a[256],b[15][15];
	int n,i,k=0;
	int col=0,row=0;
	printf("请输入阶数");
	scanf("%d",&n); 
	
	for(i=0;i<=n*n-1;i++)//初始赋值 
	{
		a[i]=i+1;
		
	}	
	for(i=0;i<=n-1;i++)//b的初始赋值 
	{
		for(k=0;k<=n-1;k++)
		{
			b[i][k]=0;		
		}

	}
	k=0;//重置k
	 
	while(k<=n*n-2)//整体的大循环，用于转圈 
	{

	for(i=col;i<=n-col-1;i++)//b行赋值 
	{
/**		if(b[row][i]!=0)//假如要赋值的数字位置已经被占了 
		{
		check++;
		break;
		}*/
		
		b[row][i]=a[k];
		k++; 
		
	}

	for(i=row+1;i<=n-row-1;i++)//b右列赋值 ,k是a的总积累 
	{
/*		if(b[i][n-col-1]!=0)
			{
				check++;
				break;
			}*/
		b[i][n-col-1]=a[k];
		k++;
	}

	for(i=n-col-2;i>=col;i--)//b底行反赋值
	{
/*		if(b[n-row][i]!=0)
			{
				check++;
				break;
			}*/
		b[n-row-1][i]=a[k];
		k++;
	} 
	for(i=n-row-2;i>=row+1;i--)//b左列反赋值 
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
