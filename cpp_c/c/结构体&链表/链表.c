#include<stdio.h>
#include<stdlib.h>

int main()
{
	
	struct Link
	{
		int number;
		struct Link *next;
	}*head,*p1,*p2,*m;
	
	head = NULL;
	p1=(struct Link*)malloc(sizeof(struct Link));
	p1->next=NULL;
	head=p1;
	int i;
	
	for(i=0;i<=10;i++)
	{
		p2=(struct Link*)malloc(sizeof(struct Link));
		p2->next=NULL;
		p1->next=p2;
		p1=p1->next;
	}
	m=head;
	for(i=0;i<=10;i++)
	{
		m->number=i;
		m=m->next;
	}
	m=head;
	
	for(i=0;i<=10;i++)	
	{
		printf("%d\n",m->number);
		m=m->next;
	}
	
	//��������������ϰ
	
	//������ϰ����Ĳ���
		//�����ױ�Ԫ֮ǰ���
	
	for(i=0;i<=5;i++)
	{
		p2=(struct Link*)malloc(sizeof(struct Link));
		p2->next = head;
		head = p2;
		
		
	}
	m=head;
	for(i=0;i<=5;i++)
	{
		m->number=i;	
		m=m->next;
			
	}
	m=head;
		
	for(i=0;i<=15;i++)	
	{
		printf("%d\n",m->number);
		m=m->next;
	}
	
	return 0;
}
