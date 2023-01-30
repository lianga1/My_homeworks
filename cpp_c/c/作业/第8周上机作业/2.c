#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int k1,k2,ans,ans1;
	srand(time(NULL));
	k1=1+rand()%9;
	k2=1+rand()%9;
	printf("请计算%d和%d的积\n",k1,k2);
	ans=k1*k2;
	do
	{
	
	scanf("%d",&ans1);
	
	if(ans1==ans)
	{
		switch (k1) {
			case 1:
				printf("Excellent");
				break;
			case 2:
				printf("Very good");
				break;
			case 3:
				printf("Excellent");
				break;
			case 4:
				printf("Very good");
				break;				
			case 5:
				printf("Keep up the good work");
				break;				
			case 6:
				printf("Keep up the good work");
				break;
			case 7:
				printf("Excellent");
				break;				
			case 8:
				printf("Very good");
				break;				
			case 9:
				printf("Keep up the good work");
				break;								
	}
	
	}
	else
	{
		switch (ans1%9+1) {
					case 1:
						printf("NO,keep trying\n");
						break;
					case 2:
						printf("Wrong,try once more\n");
						break;
					case 3:
						printf("No,keep trying\n");
						break;
					case 4:
						printf("NO,keep trying\n");
						break;				
					case 5:
						printf("Wrong,try once more\n");
						break;				
					case 6:
						printf("NO,keep trying\n");
						break;
					case 7:
						printf("No,keep trying\n");
						break;				
					case 8:
						printf("NO,keep trying\n");
						break;				
					case 9:
						printf("Wrong,try once more\n");
						break;
	}
	}
	}
	while(ans!=ans1);

	return 0;
	
}
