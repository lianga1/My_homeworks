#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std;

list<Student_info> extract_fails(list<Student_info> & students)
{
	list<Student_info> fails;

	list<Student_info>::iterator iter= students.begin();

	if(fgrade(*iter))
	{
		fails.push_back(*iter);
		iter=students.erase(iter);
	}
	else ++iter;

	return fails;	
}


int main() 
{ 

	cout<<"please enter the the names and the grades."<<endl;
	
	
	list<Student_info> students;
	list<Student_info>::iterator iter_s;
	for(iter_s=students.begin();iter_s!=students.end();++iter_s)
		read(cin,*iter_s);

	
	list<Student_info> fails;
	fails=extract_fails(students);
	
	sort(fails.begin(),fails.end(),compare);

	list<Student_info>::iterator iter;

	for(iter=fails.begin();iter!=fails.end();++iter)
	{

		cout<<iter->name<<"Your final grade is "<<grade(*iter)<<endl;
	}

	return 0; 
}

