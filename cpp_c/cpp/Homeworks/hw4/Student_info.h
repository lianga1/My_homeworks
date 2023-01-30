#ifndef GUARD_Student_info
#define GUARD_Student_info
#include <iostream>
#include <vector>
#include <string>



class Student_info{
	public:
	std::istream & read(std::istream &);
	std::string name() const{return n;}
	double grade() const;
	bool valid() const {return homework.empty();}
	
	private:
	std::string n;
	std::vector<double> homework;
	double midterm, final;


};
bool compare (const Student_info &x, const Student_info &y);





#endif
