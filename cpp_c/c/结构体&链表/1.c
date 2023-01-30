#include<stdio.h>



int main()
{
	
	struct student
	{
		int number;
		char name[20];
		char sex;
		char address[40];
		
		
	}*stp;
	
	
	
	struct student st1 ;
	st1 = (struct student){1,"LI HUA",'b',"NAN JING"};
	struct student st2;
	st2=st1;
	printf("%d%s%c%s\n",st1.number,&st1.name,st1.sex,&st1.address);
	stp=&st1;
	printf("%d%s%c%s\n",stp->number,stp->name,stp->sex,stp->address);
	

	
		
	return 0;
}
