#include<stdio.h>
#include<stdlib.h>

struct gather
{
	int num;
	struct gather *next;
};

struct gather* together(struct gather* guard1,struct gather* guard2)
{
	int check;
	struct gather *m,*n,*p1;
	n=guard1->next;
	m=guard2->next;
	while(m!=NULL)
	{
		check=1;
		while(n!=NULL)
		{
			//printf("%d %d\n",n->num,m->num);
			if(m->num==n->num)
			check=0;
			n=n->next;
		}
		if(check==1)
		{
			n=guard1->next;
			while(n->next!=NULL)
				n=n->next;
			p1=(struct gather*)malloc(sizeof(struct gather));
			n->next=p1;
			p1->next=NULL;
			p1->num=m->num;
		}
		n=guard1->next;
		m=m->next;
	}
	
	return guard1;
}
struct gather* minus(struct gather* guard1,struct gather* guard2)
{
	struct gather *m,*n,*n1;
	n=guard1;
	m=guard2->next;
	while(m!=NULL)
	{
		while(n->next!=NULL)
		{
			n1=n->next;
			if(n1->num==m->num)
			{
				n->next=n1->next;
			}
			if(n1->next!=NULL)
			n=n->next;
			else
			break;
		}
		
		n=guard1;
		m=m->next;
	}
	
	return guard1;
}
struct gather* cross(struct gather* guard1,struct gather* guard2,int a)
{
	int *b;
	int i=0;
	b=(int *)malloc(a*sizeof(int));
	struct gather *m,*n,*n1;
	n=guard1->next;
	m=guard2->next;
	while(m!=NULL)
	{
		while(n!=NULL)
		{
			if(m->num==n->num)
			{	*(b+i)=n->num;
				i++;
			}	
			n=n->next;
		}
		
		m=m->next;
		n=guard1->next;
	}
	for(int k=0;k<=i-1;k++)
	{
		n->num=*(b+k);
		if(k<i-1)
		n=n->next;
		else
		break;
	}	
	n->next=NULL;
	free(b);
	return guard1;
}

int main()
{
	int n,m;
	int i;
	printf("请输入第一个集合s1的元素数n\n");
	scanf("%d",&n);
	//定义链表s1
	printf("请输入s1的元素\n");
	struct gather *head1=NULL,*guard1=NULL,*p=NULL,*p1=NULL,*p2; 
	
	head1=NULL;
	p=(struct gather*)malloc(sizeof(struct gather));
	head1=(struct gather*)malloc(sizeof(struct gather));
	
	guard1=p;
	head1->next=guard1;
	
	for(i=0;i<=n-1;i++)
	{
		p1=(struct gather*)malloc(sizeof(struct gather));
		p1->next=NULL;
		p->next=p1;
		p=p->next;
	}
	p2=guard1->next;
	do
	{
		scanf("%d",&p2->num);
		p2=p2->next;
	}
	while(p2!=NULL);
	
	printf("请输入第二个集合s2的元素数m\n");
	scanf("%d",&m);
	struct gather *head2=NULL,*guard2=NULL,*pp=NULL,*pp1=NULL,*pp2; 
	
	pp=(struct gather*)malloc(sizeof(struct gather));
	head2=(struct gather*)malloc(sizeof(struct gather));
	
	head2->next=guard2;
	guard2=pp;
	for(i=0;i<=m-1;i++)
	{
		pp1=(struct gather*)malloc(sizeof(struct gather));
		pp1->next=NULL;
		pp->next=pp1;
		pp=pp->next;
	}
	printf("请输入s2的元素\n");
		pp2=guard2->next;
	do
		{
			scanf("%d",&pp2->num);
			pp2=pp2->next;
		}
		while(pp2!=NULL);
	
	int f;

	 
	do{
		printf("请选择功能:\n1.集合并集\n2.集合差\n3.集合交集\n");
		scanf("%d",&f);
	switch (f) {
		case 1:
			guard1=together(guard1,guard2);
			break;
		case 2:
			guard1=minus(guard1,guard2);
			break;
		case 3:
			guard1=cross(guard1,guard2,n);
			break;
		case 4:
			break;
		default:
			printf("选择错误\n");
			break;
			
	}
	}
	while(f!=1&&f!=2&&f!=3&&f!=4);
	printf("结果是:\n");
	struct gather *d;
	d=guard1->next;
	while(d!=NULL)
	{
		printf("%d\n",d->num);
		d=d->next;
	}
	
	
	return 0;
}
