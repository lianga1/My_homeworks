#include <stdio.h>

int check(int x,int y)
{
	int a;
	a = x<=y;
	
	return a;
}

int main()
{
	int year,month,day,count=0,maximum,dayc;
	const int a=31,b=30,c1=28,c2=29;
	
	scanf("%d %d %d",&year,&month,&day);
	
	switch (month) {
		case 1:
			maximum=a;
			dayc=check(day,maximum);
			if (dayc==1)
				{count = day;}
			break;
		case 2:
			if(year%4==0)
				{maximum=c2;}
				
			else
				{maximum=c1;}
			dayc=check(day,maximum);
			if (dayc==1)
				{count = day+a;}
			
			break;
		case 3:
			maximum=a;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day + a + c1 ;}
			break;
		case 4:
			maximum=b;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a;}
			break;
		case 5:
			maximum=a;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a+b;}
			break;
		case 6: 
			maximum=b;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a+b+a;}
			break;
		case 7:
			maximum=a;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a+b+a+b;}
			break;
		case 8:
			maximum=a;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a+b+a+b+a;}
			break;
		case 9:
			maximum=b;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a+b+a+b+a+a;}
			break;
		case 10:
			maximum=a;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a+b+a+b+a+a+b;}
			break;
		case 11:
			maximum=b;
			dayc=check(day,maximum);
			if (dayc==1)
			{count = day+a+c1+a+b+a+b+a+a+b+a;}
			break;
		case 12:
			maximum=a;
			dayc=check(day,maximum);
			{count = day+a+c1+a+b+a+b+a+a+b+a+b;}
		default:
			printf("输入非法-月份不正确");
			maximum=0;
			break;
	}
		
		if (maximum!=0)
		{
			if(dayc !=0)
			{
				if(year%4==0&&month>2)
					count+=1;
			
			
				printf("%d-%d-%d是第%d年的第%d天",year,month,day,year,count);
			}
			else
				printf("日期非法");
				
		}	
	return 0;
} 
