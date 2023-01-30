#include<stdio.h>
#include<stdlib.h>

struct Link
{
	struct Link *pre;
	int a;
	struct Link *next;
};

struct Link * connect(struct Link *head1,struct Link *head2)
{
	struct Link *m,*n,*p;
	struct Link *m1,*n1;
	m=head1;
	while(m->next!=NULL)
	m=m->next;
	p=m;
	m=head1;
	while(m->next!=NULL)
		m=m->next;
	m->next=head2;
	head2->pre=m;
	//bubble
	m=head1;
	n=head1->next;
	
	if(m->a>n->a)
	{
		head1=n;
		m->next=n->next;
		n->next=m;
	}
	
	n1=head1;
	
	while(p!=head1)
	{
		m=head1;
		while(m!=NULL)
		{
			n=m->next;
			if(m->next==NULL)
			break;
			if(m->a>n->a)
			{
			m->next=n->next;
			n->next=m;
			m->pre->next=n;
			n->pre=m->pre; 
			m->pre=n;
			}
			m=m->next;
			
		}
		p=p->pre;
	}
	 
	return head1;
}

int main()
{
	int i;
	
	struct Link *head1=NULL,*head2=NULL,*p=NULL,*p1=NULL,*m=NULL;
	
	p=(struct Link*)malloc(sizeof(struct Link));
	head1=p;
	head1->next=NULL;
	head1->pre=NULL;
	for(i=0;i<=5;i++)
	{
		p1=(struct Link*)malloc(sizeof(struct Link));
		p1->pre=p;
		p1->next=NULL;
		p->next=p1;
		p=p->next;
	}
	p=NULL;
	p1=NULL;
	m=head1;
	i=0;
	while(m!=NULL)
	{
		m->a=i;
		m=m->next;
		i++;
	}
	
	p=(struct Link*)malloc(sizeof(struct Link));
	head2=p;
	head2->next=NULL;
	head2->pre=NULL;
	for(int k=0;k<=7;k++)
	{
		p1=(struct Link*)malloc(sizeof(struct Link));
		p1->pre=p;
		p1->next=NULL;
		p->next=p1;
		p=p->next;
	}
	m=head2;
	for(int k=0;k<=8;k++)
	{
		m->a=k;
		m=m->next;
	}
	head1=connect(head1,head2);
	
	m=head1;
	while(m!=NULL)
	{
		printf("%d\n",m->a);
		m=m->next;
	}
	
	return 0;
} 
