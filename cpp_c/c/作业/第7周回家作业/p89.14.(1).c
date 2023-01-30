#include<stdio.h> 

int main()
{
	int a[256],b[15][15];
	int i,k,u=2,n;
	int col=0,row=0; 
	for(i=0;i<=255;i++)//初始化a，使其变成顺序数组 
		a[i]=i+1;
	for(i=0;i<=14;i++)//初始化b，使其变成全1数组 
	{
		for(k=0;k<=14;k++)
		b[i][k]=1;
	}
	printf("请输入阶数,大于1小于15\n");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++) //对b进行二次初始化，使其有效范围变成0 
	{
		for(k=0;k<=n-1;k++)
		b[i][k]=0;
	}
	b[0][0]=1;
	b[1][0]=2;
	col++;
	while(u<=n*n-2) //整体大循环 
	{
		for(i=row,k=col;i>=0&&k>=0&&b[i][k]==0;i--,k++)//斜向上 
		{
			b[i][k]=a[u] ;
			u++;
		}
		// 换向 
		if(b[0][k]==0)//这个是正常换向 
		{
			b[0][k]=a[u];
			u++;
			row=1;
			col=k-1;
		}
		else//这个是对出了有效范围的情况 
		{
			b[i+2][k-1]=a[u];
			u++;
			row=i+3;
			col=k-2;
			
		}
		
		for(i=row,k=col;i>=0&&k>=0&&b[i][k]==0;i++,k--)//斜向下 
		{
			b[i][k]=a[u];
			u++;
			
		}
		//换向 
		if(b[i][0]==0)//这个是正常换向 
		{
			b[i][0]=a[u];
			u++;
			row= i-1;
			col= 1;
		}
		else//这个是出了有效范围的情况 
		{
			b[i-1][k+2]=a[u];
			u++;
			row=i-2;
			col=k+3;
		}
		
	}
	
	
	for(i=0;i<=n-1;i++)//输出 
	{
		for(k=0;k<=n-1;k++)
			printf("%d\t",b[i][k]);
		printf("\n");
	}
	return 0;
}
