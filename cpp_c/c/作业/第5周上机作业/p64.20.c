#include<stdio.h>
#include<math.h>
int main()
{
	int a,i,num,i2,check,b;
	scanf("%d",&a);
	num = a;
	b=a;
	for (i=1;;i++)
	{
		num = num/10;
		if (num==0)
			break;
			
	}
	int c[50];
	for (i2=0;i2<=50;i2++)
	c[i2]=0;
	for(i2=0;i2<=i;i2++)
		{c[i2] = b/pow(10,i2+1);
			}
	for(i2=0;i2<=i-1;i2++)
	{
		if(c[i2]==c[i-i2-1])
			
			{
				check =0;
				continue;
			}
		else 
			{
				check =1;
				break;
			}
	}
	if (check == 1)
		printf("NO");
	else
		printf("YES");
	
	return 0;
}
