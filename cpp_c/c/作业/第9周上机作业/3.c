#include<stdio.h>

/*算法解释：
	classmul函数是阶乘函数，没有难度；
	SUM函数是一个讲所有数字的全排列除以（数字1的全排列与数字2的全排列的积） 
	从而sum得出不同数目的1和2能产生的排列情况。
	最终ans将每种情况加在一起 
*/

int classmul(int a)
{
	if(a<=1)
		return 1;
	else
	{
		int mul=1;
		for(;a>=1;a--)
		{
			mul=mul*a;
			
		}
		return mul;
	}
}

int SUM(int a,int b)
{
	int ans;
	int sum1,sum2;
	sum1=classmul(a+b);
	sum2=classmul(a)*classmul(b);
	
	ans=sum1/sum2;
	
	return ans;
} 

int main()
{
	int a,ans1,ans=0,i;
	printf("请输入台阶数\n");
	scanf("%d",&a);
	
	
		for(i=0;i<=a/2;i++)
		{
			ans1=SUM(i,a-2*i);
			ans=ans+ans1;
		
			
		}
	

	
	printf("有%d种方法",ans);
	
	return 0;
}
