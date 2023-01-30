#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Poker//定义结构体 
	{
		char decors[20];
		int number;
		
	};
	
//洗牌函数 Roll
void Roll(struct Poker p[52],struct Poker rp[52])
{
	srand(time(NULL));
	
	int i;
	for(int k=0;k<=51;k++)
	{
		rp[k].number=0;
		
	}
	
	for(int k=0;k<=51;k++)
	{
		i=rand()%52;
		if(rp[i].number!=0)
		{	
		k--;
		
		continue;}
		rp[i]=p[k];
		
	}
	
/**	for(int k=0;k<=51;k++) //this is a try of the poker
		{
			if(rp[k].number>=2&&rp[k].number<=10)
			printf("%s %d\n",&rp[k].decors,rp[k].number);
			else switch (rp[k].number) {
				case 1:
					printf("%s Ace\n",&rp[k].decors);
					break;
				case 11:
					printf("%s Jack\n",&rp[k].decors);
					break;
				case 12:
					printf("%s Queen\n",&rp[k].decors);
					break;
				case 13:
					printf("%s King\n",&rp[k].decors);
					break;
			}
		}
		*/
		
}
void TREAT(struct Poker rp[52])//发牌函数 
{
	int tr=0;
	
	printf("1号玩家的牌是\n");
	
		for(int k=0;k<=51;k++,tr++) //this is a try of the poker
			{
				
				if((k+1)%13==0&&(k+1)!=52)
				{
					int j = (k+1)/13 +1;
					tr=0;
					printf("\n%d号玩家的牌是\n",j);
					
				}
				
				if(rp[k].number>=2&&rp[k].number<=10)
				printf("%s %d\t",&rp[k].decors,rp[k].number);
				
				else switch (rp[k].number) {
					case 1:
						printf("%s Ace",&rp[k].decors);
						break;
					case 11:
						printf("%s Jack",&rp[k].decors);
						break;
					case 12:
						printf("%s Queen",&rp[k].decors);
						break;
					case 13:
						printf("%s King",&rp[k].decors);
						break;
				}
				if(tr%4==0)
				printf("\n");
				
			}
			
}
void compare(struct Poker a,struct Poker b)//比大小函数 
{
	if(a.number>b.number)
	printf("前面的大"); 
	else if(a.number<b.number) 
	printf("后面的大");
	 else printf("一样大");
} 


int main()
{
	
	struct Poker p[52];
	for(int i=0;i<=3;i++)
	{
		for(int k=0;k<=12;k++)//初始化整副扑克 
		{
			switch (i) {
				case 0:
					p[13*i+k]=(struct Poker){"spade",k+1};
					break;
				case 1:
					p[13*i+k]=(struct Poker){"heart",k+1};
					break;
				case 2:
					p[13*i+k]=(struct Poker){"club",k+1};
					break;
				case 3:
					p[13*i+k]=(struct Poker){"diamond",k+1};
					break;
					
			}
			
			
		}

		
	}
	

	
		
		struct Poker *dec[4][13] ;
		int j=0;
		for(int i=0;i<=3;i++)//此后，黑桃是1，红桃是2，梅花是3，方块是4； 
		{
			for(int k=0;k<=12;k++)
			{
				*dec[i][k]=p[j];
				j++;
				
			} 
		}
		
			 
		// reroll
		
		struct Poker rp[52];//这是洗牌后的数组； 
		Roll(p,rp);
		//发牌函数
		printf("发牌结果是\n");
		TREAT(rp); 
		printf("\nspade A 和 spade K 的比较结果是") ;
		compare(p[0],p[12]); 
		
		
	
	return 0;
} 
