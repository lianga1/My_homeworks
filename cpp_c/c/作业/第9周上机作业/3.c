#include<stdio.h>

/*�㷨���ͣ�
	classmul�����ǽ׳˺�����û���Ѷȣ�
	SUM������һ�����������ֵ�ȫ���г��ԣ�����1��ȫ����������2��ȫ���еĻ��� 
	�Ӷ�sum�ó���ͬ��Ŀ��1��2�ܲ��������������
	����ans��ÿ���������һ�� 
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
	printf("������̨����\n");
	scanf("%d",&a);
	
	
		for(i=0;i<=a/2;i++)
		{
			ans1=SUM(i,a-2*i);
			ans=ans+ans1;
		
			
		}
	

	
	printf("��%d�ַ���",ans);
	
	return 0;
}
