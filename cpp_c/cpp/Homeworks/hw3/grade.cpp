#include <vector>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include "grade.h"
#include "algorithm.h"
#include "Student_info.h"

using std::cout;
using std::endl;
using std::back_inserter;
using std::vector;
using std::domain_error;
using MySpace::remove_copy;
using MySpace::median;
using MySpace::average;

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double> & hw)
{
	if(hw.size()==0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(const Student_info & s){
	return grade(s.midterm,s.final,s.homework);
}

//grade_aux
double grade_aux(const Student_info & s)
{
	try{
		return grade(s);
	}
	catch(domain_error)
	{
		return grade(s.midterm,s.final,0);
	}
   
	
}

//average_grade
double average_grade(const Student_info & s)
{
	
	return grade(s.midterm,s.final,average(s.homework));

    
}

//optimistic_median
double optimistic_median(const Student_info & s)
{
	vector<double> op_hw;
	remove_copy(s.homework.begin(),s.homework.end(),back_inserter(op_hw),0.0);
	return grade(s.midterm,s.final,median(op_hw));
}

/*int main()
{
	using std::cin;
	Student_info s1;
	s1.name="aaa";
	s1.midterm=70.0;
	s1.final =80.0;
	s1.homework={90.0,90.0,90.0,80.0};
	cin>>s1.midterm;
	cout<<optimistic_median(s1)<<endl;
}*/