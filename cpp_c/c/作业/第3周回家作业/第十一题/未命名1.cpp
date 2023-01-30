#include <stdio.h>

int main()
{
	int year,month,day,count,maximum;
	const int a=30,b=31,c1=28,c2=29;
	
	scanf("%d %d %d",&year,&month,&day);
	
	switch (month) {
		case 1:
			maximum=31;
			break;
		case 2:
			if(year%4==0)
				maximum=c2;
			else
				maximum=c1;
			break;
		case 3:
			maximum=a;
		case 4:
			maximum=b;
		case 5:
			maximum=a;
		case 6: 
			maximum=b;
		case 7:
			maximum=a;
		case 8:
			maximum=a;
		case 9:
			maximum=b;
		case 10:
			maximum=a;
		case 11:
			maximum=b;
		case 12:
			maximum=a;
		default:
			printf("输入非法");
			maximum=0;
			break;
	}
		if (maximum!=0)
			printf("%d-%d-%d是第%d年的第%d天",year,month,day,year,count);
	
	return 0;
} 
