#include<stdio.h>

void ninput(int *a)
{
	int i=0;
	for(i=0;i<=9;i++)
	{
		scanf("%d",a++);
		
	}
	
	
}

void ntrans(int *a)
{
	int mem=0,mid;
	
	for(int i=1;i<=9;i++)
	{
		if(*(a+i)<=*(a+mem))
		{
		mem=i;
		}
	}
	{
		mid=*(a+mem);
		*(a+mem)=*a;
		*a=mid;
		
	}
		for(int i=1;i<=9;i++)
		{
			if(*(a+i)>=*(a+mem))
			{
			mem=i;
			}
			
		}
			{
				mid=*(a+mem);
				*(a+mem)=*(a+9);
				*(a+9)=mid;
				
			}
}


void noutput(int *a)

{

	int i=0;
	for(i=0;i<=9;i++)
	{
		printf("%d\n",*a++);
		
	}	
	
}

int main()
{
	int a[10];

	
	ninput(a);
	
	ntrans(a);
	
	printf("Êä³ö½á¹û\n");
	noutput(a);
	
	return 0;
	
}
