#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void out(int (*a)[5],int n)
{
	printf("ѧ��\t����\t��ѧ\tӢ��\t����\n");
	int i;
	for(i=0;i<=4;i++)
	{
		printf("%d\t",*(*(a+n-1)+i));		
	}
	
}

void show(int (*a)[5])
{
	printf("ѧ��\t����\t��ѧ\tӢ��\t����\n");
	int i=0;
	int k=0;
	for(i=0;i<=99;i++)
	{
		for(k=0;k<=4;k++)
		{
			printf("%d\t",*(*(a+i)+k));
			
		}
		printf("\n");
		
	}
	
	
} 

int main()
{
	/*���ɳɼ�*/
		int chart[100][5];
		int i,k;
		for(i=0;i<=99;i++)
		{
			chart[i][0]=i+1;
		}
		srand(time(NULL));
		for(i=0;i<=99;i++)
		{
			for(k=1;k<=4;k++)
			{
				chart[i][k]=50+rand()%51;
				
			}
		}
/**			for(i=0;i<=99;i++)
			{
				for(k=0;k<=4;k++)
				{
					printf("%d\t",chart[i][k]);
				
				}
				printf("\n");
			}*/
	
	
	printf("��������Ҫ�Ĺ���\n����1Ϊ��ѯѧ���ɼ�\n����2Ϊ��������ɼ���\n") ;
	int check;
	scanf("%d",&check);
	if(check==1)
	{
		printf("������ѧ��\n");
		int id;
		scanf("%d",&id);
		out(chart,id);
		
	}
	else if(check==2)
	{
		show(chart);
	}
	else
	{printf("����Ƿ�\n");
	}
	
	return 0;
}
