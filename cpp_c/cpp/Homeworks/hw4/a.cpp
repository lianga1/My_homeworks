#ifndef GUARD_Student_info
#define GUARD_Student_info
#include <iostream>
#include <vector>
#include <string>
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

double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	sort(vec.begin(),vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? ((vec[mid] + vec[mid - 1]) / 2) : vec[mid];
}



double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


double grade(double midterm, double final, const std::vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("student has no home work");
    double hw_;

    hw_=median(hw);

	return grade(midterm, final, hw_);
}
class Student_info{
	public:
	std::istream & read(std::istream &);
	std::string name() const{return n;}
	double grade() const;
	bool valid() const {return homework.empty();}
	
	private:
	std::string n;
	std::vector<double> homework;
	double midterm, final,midian ;


};
bool compare (const Student_info &x, const Student_info &y);





#endif
std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
	if (in) {
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear();
	}
	return in;
}


std::istream& Student_info::read(std::istream& is) {
	is >> n >> midterm>> final;
	::read_hw(is, homework);
	return is;
}



bool compare (const Student_info &x, const Student_info &y)
{
	return x.name()<y.name();
}

double Student_info::grade() const
{
    return ::grade(midterm,final,homework);
}
int main() 
{ 	
	vector<Student_info> students;
	Student_info record;
	while(record.read(cin))//read
	{
		cout<<"in"<<endl;
		if(record.valid())
		{
			cout<<"valid"<<endl;
			students.push_back(record);
		}	
		
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
