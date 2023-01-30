#include<time.h>
#include<stdio.h>
#include<stdlib.h>



struct Link { // Define the Link
	struct Link *pre;
	int a;
	struct Link *next;
};

struct Link* trans(struct Link *head, FILE *fp) {
	rewind(fp);
	struct Link *p, *p1, *m;
	p = head;

	while (!feof(fp)) {
		fscanf(fp, "%d\n", &p->a);
		int a = p->a;

		//define the Link and give value
		p1 = (struct Link*)malloc(sizeof(struct Link));
		p1->pre = p;
		p1->next = NULL;
		p->next = p1;
		p = p->next;

	}


	return head;
}

struct Link * connect(struct Link *head1, struct Link *head2) {

	struct Link *head3;
	
	struct Link *p,*p1,*p2;

	
	
	struct Link *m;
	m=head1;
	
	//connect the Links
	while(m->next->next!=NULL)
		m=m->next;
	m->next=head2;
	//connect over
	
	
	m=head1;
	
	while(m!=NULL)
	{
		p1=head3;
		p=(struct Link*)malloc(sizeof(struct Link));	
		p->next=NULL;
		p->a=m->a;
		
		while((p1!=NULL)&&(p->a<p1->a))
		{
			p2=p1;
			p1=p1->next;
			
		}
		if(p1==head3)
			head3=p;
		else
			p2->next=p;
 		p->next=p1;
		
		m=m->next;
	}
	
	
	return head3;
}

void output(struct Link *head, FILE *fp) {
	struct Link *m;
	m = head;
	while (m != NULL) {
		fprintf(fp, "%d\n", m->a);
		m = m->next;
	}

}

int main() {
	int i;
	FILE *fp, *fp1, *fp2;
	fp = fopen("test4_3.txt", "w+");
	fp1 = fopen("test4_1.txt", "w+");
	fp2 = fopen("test4_2.txt", "w+"); // Open the files

	srand(time(NULL));//set the seed

	/*
	开始向文件输入随机数
	*/
	for (i = 0; i <= 5; i++) { //6 elements
		fprintf(fp1, "%d\n", rand() % 100);
		fprintf(fp2, "%d\n", rand() % 100);
	}//give number to the files


	struct Link *head1 = NULL, *head2 = NULL, *p = NULL, *p1 = NULL, *m = NULL;

	p = (struct Link*)malloc(sizeof(struct Link));
	head1 = p;
	head1->next = NULL;
	head1->pre = NULL;

	trans(head1, fp1);




	p = (struct Link*)malloc(sizeof(struct Link));
	head2 = p;
	head2->next = NULL;
	head2->pre = NULL;

	trans(head2,fp2);


	head1 = connect(head1, head2); //connect

	m = head1->next;
	while(m->next!=NULL){
		if(m->a<=100)
		fprintf(fp,"%d\n",m->a);
		m=m->next->next;
	}
	fprintf(fp,"%d\n",m->a);
	

	return 0;
}
