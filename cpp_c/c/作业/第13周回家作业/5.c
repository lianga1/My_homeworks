#include<stdio.h>
#include<string.h>

struct Archives
{
	char name[20];
	long int number;
	int chinese;
	int math;
	int english;
	int sum;
	double average;
}stu[100];

int total=0;


void Input()
{
	int num;
	int i;
	int k;
	do{
	printf("������Ҫ�����ѧ����Ŀ(С��100)\n");
	scanf("%d",&num);
	}
	while(num>100);
	
	
	printf("����������ѧ��������ƴ������ѧ�ţ����ĳɼ�����ѧ�ɼ���Ӣ��ɼ�\n");
		for(k=0;;k++)
		{
			if(stu[k].name[0]=='N'&&stu[k].name[1]=='U'&&stu[k].name[2]=='L'&&stu[k].name[3]=='L'&&stu[k].name[4]=='\0') break;
		}
			
	for(i=0;i<=k+num-1;i++)
	{
		scanf("%s",stu[i].name);
		scanf("%ld",&stu[i].number);
		scanf("%d",&stu[i].chinese);
		scanf("%d",&stu[i].math);
		scanf("%d",&stu[i].english);
	}
	for(k=0;k<=99;k++)
	{
		stu[k].sum=stu[k].chinese+stu[k].math+stu[k].english;
		stu[k].average=(stu[k].chinese+stu[k].math+stu[k].english)/3.0;
		
	}
	

	total = i;
}

void Sum()
{
	
	
	int k;
	int check=0;
	int sum=0;
	while(1)
	{	printf("��������Ϳ�Ŀ\n");
			printf("1.����\n2.��ѧ\n3.Ӣ��\n4.ƽ����\n5.�ܷ�\n");
		scanf("%d",&k);
		switch (k) {
			case 1://Chinese 
					for(int i=1;i<=99;i++)
					{
						sum+=stu[i].chinese;
					}
				check=1;
				break;
				
			case 2://Maths
				for(int i=1;i<=99;i++)
				{
					sum+=stu[i].math;
					
				}
				check=1;
				break;
				
			case 3://English
				for(int i=1;i<=99;i++)
				{
					sum+=stu[i].english;
					
				}
				check=1;
				break;
				
			case 4://Average
				 	for(int i=1;i<=99;i++)
				 	{
				 		sum+=stu[i].average;
				 		
				 	}
				check=1;
				break;
			case 5://sum
			 	for(int i=1;i<=99;i++)
			 	{
			 		sum+=stu[i].sum;
			 	}
			 	check=1;
			 	break;
			default://wrong input
				printf("�Ƿ�����"); 
				break;
				
		}
		if(check==1)
		break;
	}	

	printf("�ܺ���%d\n",sum);

}

void Average()
{
		int i;
		 
		int k;
		int check=0;
		int sum=0;
		double ave=0;
		double t;
		t=total;
		while(1)
		{	printf("��������ƽ����Ŀ\n");
				printf("1.����\n2.��ѧ\n3.Ӣ��\n4.ƽ����\n5.�ܷ�\n");
			scanf("%d",&k);
			switch (k) {
				case 1://Chinese 
						for(i=1;i<=99;i++)
						{
							sum+=stu[i].chinese;
						}
						ave=sum/t; 
					check=1;
					break;
					
				case 2://Maths
					for(int i=1;i<=99;i++)
					{
						sum+=stu[i].math;
						
					}
					ave=sum/t; 
					check=1;
					break;
					
				case 3://English
					for(int i=1;i<=99;i++)
					{
						sum+=stu[i].english;
						
					}
					ave=sum/t; 
					check=1;
					break;
					
				case 4://Average
					 	for(int i=1;i<=99;i++)
					 	{
					 		sum+=stu[i].average;
					 		
					 	}
					 	ave=sum/t; 
					 	
					check=1;
					break;
				case 5://sum
				 	for(int i=1;i<=99;i++)
				 	{
				 		sum+=stu[i].sum;
				 	}
				 	
				 	ave=sum/t; 
				 	check=1;
				 	break;
				default://wrong input
					printf("�Ƿ�����"); 
					break;
					
			}
			if(check==1)
			break;
		}	
	
		printf("ƽ������%lf\n",ave);
}

void SearchNum()
{
	int i;
	
	int num;
	int check=0;
	printf("������ѧ��\n");
	scanf("%d",&num);
	
	for(i=0;i<=99;i++)
	{
		if(stu[i].number==num)
		{
			printf("%d\n",stu[i].average);
				printf("����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
				printf("%s",stu[i].name);
				printf("\t");
				printf("%d\t%d\t%d\t%d\t%d\t%lf\n",stu[i].number,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum,stu[i].average);	
				check=1;
				break;
		}
		
	}
	if(check!=1)
	printf("û���ҵ������\n");
}

void SearchName()
{
	int k;
	int i;

	int check=0;
	char name[20];
	printf("����������\n");
	scanf("%s",name);
	for(i=0;i<=total;i++)
	{
		for(k=0;k<=19;k++)
		{
			if(stu[i].name[k]||name[k])
			{
				if(stu[i].name[k]==name[k])
				check=1;
				else check=0;
			}
			else break;
		}
		if(check==1) break;
		
	}
	if(check==0)
	{
		printf("û���ҵ������\n");
	}
	if(check==1)
	{
		printf("����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
		printf("%s",stu[i].name);
		printf("\t");
		printf("%d\t%d\t%d\t%d\t%d\t%lf\n",stu[i].number,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum,stu[i].average);	
	}
}

void Rank()
{
	int i;
	int k;
	int j;
	int l;
	int checka=0;
	int r[100];
	int check=0;
	int mid;
	struct Archives *rank[100];
	for(i=0;i<=99;i++)
		rank[i]=&stu[i];
	
	for(i=0;i<=99;i++)
	{
		r[i]=i;
	}
	

	while(1)
	{	printf("������Ҫ����Ŀ�Ŀ\n");
		printf("1.����\n2.��ѧ\n3.Ӣ��\n4.ƽ����\n5.�ܷ�\n");
		scanf("%d",&k);
		switch (k) {
			case 1://Chinese 
			
				for(i=0;i<=total-2;i++)
				{
					for(k=total-1;k>=i&&k>=1;k--)
					{
						if(stu[k].chinese>=stu[k-1].chinese)
						{
							mid=r[k-1];
							r[k-1]=r[k];
							r[k]=mid;
						}
					}
				}
			
			/**	for(i=0;i<=total-1;i++)
				{
					
					for(j=0;j<=total-2;j++)
					{
						for(l=0;l<=i;l++)
						{
							if(r[l]==j)
							checka=1; 
						}
						if(stu[j].chinese>=stu[j+1].chinese&&checka!=1)
						{
							rank[i]=&stu[j];
							r[i]=j;
						}
						else if(stu[j].chinese<stu[j+1].chinese&&checka!=1)
						{
							rank[i]=&stu[j+1];
							r[i]=j+1;
							
						}
					}
					
				}*/
				check=1;
				break; 
			case 2://Maths
				for(i=0;i<=total-2;i++)
				{
					for(k=total-1;k>=i&&k>=1;k--)
					{
						if(stu[r[k]].math>=stu[r[k-1]].math)
						{
							mid=r[k-1];
							r[k-1]=r[k];
							r[k]=mid;
						}
					}
				}
				check=1;
					break;
					
			case 3://English
				for(i=0;i<=total-2;i++)
				{
					for(k=total-1;k>=i&&k>=1;k--)
					{
						if(stu[r[k]].english>=stu[r[k-1]].english)
						{
							mid=r[k-1];
							r[k-1]=r[k];
							r[k]=mid;
						}
					}
				}
				check=1;
					break;
					
			case 4://Average
				for(i=0;i<=total-2;i++)
				{
					for(k=total-1;k>=i&&k>=1;k--)
					{
						if(stu[r[k]].average>=stu[r[k-1]].average)
						{
							mid=r[k-1];
							r[k-1]=r[k];
							r[k]=mid;
						}
					}
				}
				check=1;
					break;
			case 5://sum
				for(i=0;i<=total-2;i++)
				{
					for(k=total-1;k>=i&&k>=1;k--)
					{
						if(stu[r[k]].sum>=stu[r[k-1]].sum)
						{
							mid=r[k-1];
							r[k-1]=r[k];
							r[k]=mid;
						}
					}
				}
				check=1;
				break;
			default://wrong input
					printf("�Ƿ�����"); 
					break;
					
			}
			if(check==1)
			break;
		}	
	

	
	printf("����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
	for(i=0;i<=total-1;i++)
	{
		printf("%s",rank[r[i]]->name);
		printf("\t");
		printf("%d\t%d\t%d\t%d\t%d\t%lf\n",rank[r[i]]->number,rank[r[i]]->chinese,rank[r[i]]->math,rank[r[i]]->english,rank[r[i]]->sum,rank[r[i]]->average);	
		
		}	
	
}

void Output()
{
	int i;
	printf("����\tѧ��\t����\t��ѧ\tӢ��\t�ܷ�\tƽ����\n");
	for(i=0;;i++)
	{
		if(stu[i].name[0]=='N'&&stu[i].name[1]=='U'&&stu[i].name[2]=='L'&&stu[i].name[3]=='L'&&stu[i].name[4]=='\0') break;
		printf("%s",stu[i].name);
		printf("\t");
		printf("%d\t%d\t%d\t%d\t%d\t%lf\n",stu[i].number,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum,stu[i].average);				
		}
	
}



int main()
{
	for(int k=0;k<=99;k++)
	{
		stu[k]=(struct Archives){"NULL",0,0,0,0,0,0.0};
	}
	//printf("��������Ҫ���Ĺ���\n1.¼��ɼ�\n2.���ֻܷ�ƽ����\n3.��ѧ�Ų���\n4.����������\n5.��ĳһ�Ʒ���������ʾ����\n6.��˳�������������\n7.�˳�\n");
	
	int i,j,check=0;

	while(1) 
	{
		printf("��������Ҫ���Ĺ���\n1.¼��ɼ�\n2.���ֻܷ�ƽ����\n3.��ѧ�Ų���\n4.����������\n5.��ĳһ�Ʒ���������ʾ����\n6.��˳�������������\n7.�˳�\n");
		
		scanf("%d",&i);
		switch (i) 
		{
			case 1:
				Input();
				
				break;
				
			case 2:
				printf("��������Ҫ�Ĺ���\n1.���ܷ�\n2.��ƽ����\n");
				scanf("%d",&j);
				switch (j) 
				{
					case 1:
						Sum();						
						break;
					case 2:
						Average();						
						break;
					default:
						printf("����Ƿ�\n");
						break;
				}
				break;
				
			case 3:
				SearchNum();				
				break;
				
			case 4:
				SearchName();				
				break;
				
			case 5:
				Rank();				
				break;
				
			case 6:
				Output();				
				break;
			case 7:
				check=1;
				break;
				
			default:
				printf("����Ƿ�\n"); 
				break;
		} 
		if(check==1)
		{
			break;
		}
		
	}
	
	return 0;
} 

/*

LiHong
1
100
60
10
LiHua
2
60
100
20
LiFang
3
10
10
100




*/
