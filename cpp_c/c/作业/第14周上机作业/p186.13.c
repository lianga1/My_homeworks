#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct CODE 
{
	char code;
	int check;
	struct CODE *next;
	
}*head, *p,*p1,*m;

void encode(int key,char a[],int n)
{
	int i,k;
	m=head;
	
	for(k=0;k<=n-1;k++)
	{
		for(i=0;i<=key-1;i++)
		{	
			m=m->next;
			while(m->check==1)
			{
			
				m=m->next;
			}
		}
		m->code=a[k];
		m->check=1;
	}
}

int main() {
	printf("请输入字符串长度n\n");
	int n;
	scanf("%d", &n);
	char s[100];
	
	printf("请输入字符串\n");
	scanf("%s",s);
	int i;
	head=NULL;
	p=(struct CODE*)malloc(sizeof(struct CODE));
	p->next=NULL;
	head=p;
	for (i = 0; i <= n - 2; i++) 
	{
		p1=(struct CODE*)malloc(sizeof(struct CODE));
		p1->next=NULL;
		p->next=p1;
		p=p->next;
	}
	p1->next=head;
	
	m=head;
	for(i=0;i<=n-1;i++)
	{
		m->check=0;
		m=m->next;
	}

	printf("请输入key\n");
	int key;
	scanf("%d", &key);
	

	encode(key,s,n);
	printf("加密结果是\n");
	m = head;

	for (i = 0; i <= n-1; i++)
	{
		printf("%c", m->code);
		m = m->next;
	}

	return 0;
}
