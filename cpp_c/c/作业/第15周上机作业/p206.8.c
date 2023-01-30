#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Link
{
	int value;
	int count;
	struct Link *next;
};
void insert(int val,struct Link* head)
{
	struct Link *p,*m,*n;
	m=head;
	n=head->next;
	p=(struct Link*)malloc(sizeof(struct Link));
	p->value=val;
	p->count=1;
	p->next=NULL;
	if(head->next==NULL)
	{
		head->next=p;
		return;
	}
	while(m->next!=NULL)
	{	
		if(m->value==p->value)
		{	m->count++;return;}
		else if((m->value<p->value)&&(n->value>p->value))
		{
			m->next=p;
			p->next=n;
			return;
		}

		else
		{
			m=m->next;
			n=n->next;
		}
		
	}
	if(m->next==NULL)
	{
		m->next=p;
		
	}
	
}
void write(struct Link *head)
{
	struct Link *m;
	m=head->next;
	
	while(m!=NULL)
	{
		printf("%d\t",m->value);
		printf("%d\n",m->count);
		m=m->next;
	}
	
}

int main()
{
	struct Link *head;
	head=(struct Link*)malloc(sizeof(struct Link));
	head->next =NULL;
	FILE *fp;
	srand(time(NULL));
	
	fp=fopen("test8.txt","w+");
		
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
	rewind(fp);
	char n[5];
	int  val;
	int ten;
	int one;
	
	for(i=0;i<=num-1;i++)
	{
		fgets(n,5,fp);
		ten=n[0]-48;
		one=n[1]-48;
		if(n[1]=='\n')
			one=0;
		val=ten*10+one;
		

		insert(val,head);
		
	}
	write(head);
	
	return 0;
	
}
