#include<stdio.h>
#include<stdlib.h>

struct Link
{
	int a;
	struct Link *next;
};

struct Link * del(struct Link *head)
{
	struct Link *m,*n;
	int i=0,k=0;
	m=head;
	n=m->next;
	while(n!=NULL)
	{
		if(m->a>n->a)
			k=i+1;
		
		n=n->next;
		m=m->next;
		i++;
	}
	m=head;
	n=m->next;
	for(i=0;i<=k-2;i++)
	{
		n=n->next;
		m=m->next;		
	}
	m->next=n->next;
	return head;
}

int main()
{
	struct Link *head=NULL,*p=NULL,*p1=NULL,*m=NULL;
	p=(struct Link*)malloc(sizeof(struct Link));
	head=p;
	head->next=NULL;
	int n;
	printf("请输入元素数\n");
	scanf("%d",&n);
	
	for(int i=0;i<=n-2;i++)
	{
		p1=(struct Link*)malloc(sizeof(struct Link));
		p1->next=NULL;
		p->next=p1;
		p=p->next;
	}	
	printf("请输入元素\n");
	m=head;
	while(m!=NULL)
	{
		scanf("%d",&m->a);
		m=m->next;
	}
	head=del(head);
	m=head;
	printf("结果是\n");
	while(m!=NULL)
	{
		printf("%d\n",m->a);
		m=m->next;
	}
	
	
	return 0;
}

/*
5
5
3
7
2
1



*/
