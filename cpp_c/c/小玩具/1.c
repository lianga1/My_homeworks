#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,m,n;
	char *a[10];
	char *temp;
	char 
	for(i=0;i<=9;i++)
	{
		printf("Enter 10 names,No.%d:",i+1);
		
		scanf("%s",a[i]);
	}
	
	for(j=0;j<=9;j++)
	{
		m=j;
		for(n=j+1;n<=9;n++)
		{
			if(strcmp(a[m],a[n])>0)
				m=n;
		}
		if(m!=j)
		{
			temp=a[j];
			a[j]=a[m];
			a[m]=temp;
		}

	}
	for(i=0;i<=9;i++)
	{
		printf("%s",a[i]);
	}
	
	return 0;
}
