#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <vector>
#include "grade.h"
#include "Student_info.h"
using namespace std;


int main() 
{ 	
	vector<Student_info> students;
	Student_info record;
	while(record.read(cin))
	{
		students.push_back(record);
	}



	//sort 
	sort(students.begin(),students.end(),compare);
	
	//output
	for(auto iter=students.begin();iter!=students.end();iter++)
	{
		cout<<setprecision(3)<<(*iter).name()<<"'s final grade is"<<(*iter).grade()<<endl;
	}
	return 0; 
}
