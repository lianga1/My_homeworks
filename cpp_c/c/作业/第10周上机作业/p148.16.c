#include<stdio.h>

int nin(int *a[],int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",a[i]);
		
	}
	
	return 0;
	
}


int nout(int *a[],int n)

{
	for(int i=0;i<n;i++)
	{
		printf("%d\n",*a[i]);
		
	}
	
	return 0;
}

int norder(int *a[],int n)
{
	int temp,i,k;
	for(i=0;i<=n;i++)
	{
		for(k=n-1;k>i;k--)
		{
			if(*a[k]<=*a[k-1])
			{
				temp=*a[k];
				*a[k]=*a[k-1];
				*a[k-1]=temp;
				
			}
		}
		
	}
	
	
	return 0;
}

int main()
{
	int a,b,c,d,e,f,g;
	
	int *p[7]={&a,&b,&c,&d,&e,&f,&g};
	
	
	nin(p,7);
	printf("\n");
	nout(p,7);	
	printf("\n");
	norder(p,7);
	nout(p,7);
	
	
}
