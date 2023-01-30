#include<stdio.h>
#include<stdlib.h>

int main()

{
	int i;
	struct intNode
	{
		int value;
		int score;
		struct intNode * next;
	};
	struct intNode *p,*s,*d,*m;
	
	
	p=(struct intNode *)malloc(sizeof(struct intNode));
	p->next=NULL;
	s=p;
	for(i=1;i<=10;i++){
		d=(struct intNode *)malloc(sizeof(struct intNode)); 

		s->next=d;
		d->next=NULL;
		s=s->next;
	}
	m=p->next;
	for(i=1;i<=9;i++){
		scanf("%d",m->value);
		m=m->next;
	}
	
	
	
	
	
	
	return 0;
}
