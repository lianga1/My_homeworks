#include<stdio.h>
#define N 4


int main()
{
	int i,j,k=1;
	int a[N][N];
	int *b[N][N];
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			a[i][j]=k++;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			b[i][j]=&a[j][i];
		}
	}	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\t",*b[i][j]);
		}
		printf("\n");
	}	
	
	return 0;
	
}
