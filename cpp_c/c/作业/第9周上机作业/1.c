#include<stdio.h>
#define N 100

static int count = 0;

int exchange1(int k,int i)
{
	count++;
	
	int mid;
	mid = k;
	k = i;
	i = mid;

	
	return k;
}
int exchange2(int k,int i)
{
	
	int mid;
	mid = k;
	k = i;
	i = mid;
	return i;
	

	return 0;
}


int main()
{

	
	 int a[N];
	
	int i,k,num,check,mid;
	for(i=0;i<=N;i++)// start clean module
	{
		a[i]=0;
	}
	for(i=0;i<=N;i++)// input module
	{
		check = scanf("%d",&a[i]);
		if(check==0)
		{
			num =i-1;
			break;
			
		}
	}

	
	for(i=0;i<=num;i++)//bubble module
	{
		for(k=1;k<=num-i;k++)
		{
			if(a[k-1]>a[k])
			{
				mid=exchange1(a[k-1],a[k]);
				a[k]=exchange2(a[k-1],a[k]);
				a[k-1]=mid;
			}
		}
		
		
	}
	printf("the ordered numbers is\n");
	
	for(i=0;i<=num;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("the function 'exchange' is used for %d times",count);
	
	
	return 0;
}
