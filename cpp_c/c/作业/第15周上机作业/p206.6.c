#include <stdio.h>
#include <stdlib.h>
#include<time.h>


int main()
{
	
	FILE *fp;
	srand(time(NULL));
	
/**	printf("请输入文件名\n");
	char name[40];
	scanf("%s%*c",name);
	
	if((fp=fopen(name,"r"))==NULL)
		{
			printf("%s文件不能打开\n");
			return 1;
		}
*/
		
	fp=fopen("test6.txt","w+");
		
	int num=rand()%100;
	while(num==0)
		num=rand()%100;
	int i;
	int inte;
	for(i=0;i<=num-1;i++)
	{
		inte=rand()%100;
		fprintf(fp,"%d\n",inte);
	}
	char n[5],m[5];
	char max[5],min[5];

	rewind(fp);
	
	fscanf(fp,"%c%c",&max[0],&max[1]);
	fscanf(fp,"%c%c",&min[0],&min[1]);	
	rewind(fp);
	
//	int maximum,minimum;
	
	
	for(i=0;i<=num-1;i++)
	{
		fgets(n,5,fp);
		if((n[0]>=max[0])&&(n[1]>max[1]))
			{max[0]=n[0];max[1]=n[1];}
		if((n[0]<=min[0])&&(min[1]<n[1]))
			{min[0]=n[0];min[1]=n[1];}
		
		printf("%s",n);
		
	}
	
	printf("共有%d个数字\n",num);
	printf("最大数是%s最小数是%s",max,min);
	
	
	return 0;
} 
