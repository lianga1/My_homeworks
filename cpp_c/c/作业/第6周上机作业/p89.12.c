#include<stdio.h>
int main()
{
	int a[40],m,i1;
	int i,b,mid,k;
	
	
		printf("���������û���λ��\n");
		scanf("%d",&m);
		
	for(i=0;i<=39;i++)
		{
			printf("�������%d����,������ĸn��������\n",i+1);
			b=scanf("%d",&a[i]);
			if(b==0)
				{
					i1=i-1;
					break;
					
				}
		}



		
		for(i=m-1,b=0;i>=0;i--,b++)
		{
			for(k=i+1;k<=i1-b;k++)
			{
				mid=a[k];
				a[k]=a[k-1];
				a[k-1]=mid;
			}
		}
		for (i=0;i<=i1;i++)
		{
			printf("%d\t",a[i]);
			
		}
	return 0;
}
