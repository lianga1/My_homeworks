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
	printf("请输入要输入的学生数目(小于100)\n");
	scanf("%d",&num);
	}
	while(num>100);
	
	
	printf("请依次输入学生姓名（拼音），学号，语文成绩，数学成绩，英语成绩\n");
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
	{	printf("请输入求和科目\n");
			printf("1.语文\n2.数学\n3.英语\n4.平均分\n5.总分\n");
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
				printf("非法输入"); 
				break;
				
		}
		if(check==1)
		break;
	}	

	printf("总和是%d\n",sum);

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
		{	printf("请输入求平均科目\n");
				printf("1.语文\n2.数学\n3.英语\n4.平均分\n5.总分\n");
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
					printf("非法输入"); 
					break;
					
			}
			if(check==1)
			break;
		}	
	
		printf("平均分是%lf\n",ave);
}

void SearchNum()
{
	int i;
	
	int num;
	int check=0;
	printf("请输入学号\n");
	scanf("%d",&num);
	
	for(i=0;i<=99;i++)
	{
		if(stu[i].number==num)
		{
			printf("%d\n",stu[i].average);
				printf("姓名\t学号\t语文\t数学\t英语\t总分\t平均分\n");
				printf("%s",stu[i].name);
				printf("\t");
				printf("%d\t%d\t%d\t%d\t%d\t%lf\n",stu[i].number,stu[i].chinese,stu[i].math,stu[i].english,stu[i].sum,stu[i].average);	
				check=1;
				break;
		}
		
	}
	if(check!=1)
	printf("没有找到这个人\n");
}

void SearchName()
{
	int k;
	int i;

	int check=0;
	char name[20];
	printf("请输入姓名\n");
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
		printf("没有找到这个人\n");
	}
	if(check==1)
	{
		printf("姓名\t学号\t语文\t数学\t英语\t总分\t平均分\n");
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
	{	printf("请输入要排序的科目\n");
		printf("1.语文\n2.数学\n3.英语\n4.平均分\n5.总分\n");
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
					printf("非法输入"); 
					break;
					
			}
			if(check==1)
			break;
		}	
	

	
	printf("姓名\t学号\t语文\t数学\t英语\t总分\t平均分\n");
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
	printf("姓名\t学号\t语文\t数学\t英语\t总分\t平均分\n");
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
	//printf("请输入想要做的功能\n1.录入成绩\n2.求总分或平均分\n3.按学号查找\n4.按姓名查找\n5.按某一科分数排序显示名单\n6.按顺序输出整个名单\n7.退出\n");
	
	int i,j,check=0;

	while(1) 
	{
		printf("请输入想要做的功能\n1.录入成绩\n2.求总分或平均分\n3.按学号查找\n4.按姓名查找\n5.按某一科分数排序显示名单\n6.按顺序输出整个名单\n7.退出\n");
		
		scanf("%d",&i);
		switch (i) 
		{
			case 1:
				Input();
				
				break;
				
			case 2:
				printf("请输入想要的功能\n1.求总分\n2.求平均分\n");
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
						printf("输入非法\n");
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
				printf("输入非法\n"); 
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
