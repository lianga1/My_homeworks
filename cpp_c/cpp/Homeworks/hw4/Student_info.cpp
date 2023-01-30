#include "Student_info.h"
#include "grade.h"
#include <vector>
using namespace std;

//TODO
std::istream & read_hw(istream & in,vector<double> & hw)
{
    if(in)
    {
        hw.clear();
        double x;
        while(cin>>x){
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}
std::istream & Student_info::read(std::istream &in)
{
	in>>n>>midterm>>final;
	read_hw(in,homework);
	return in;
}


bool compare (const Student_info &x, const Student_info &y)
{
	return x.name()<y.name();
}

double Student_info::grade() const
{
    return ::grade(midterm,final,homework);
}