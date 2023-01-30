#include "Student_info.h"

using namespace std;


bool compare(const Student_info &x, const Student_info &y)
{
    return x.name<y.name;   
}

istream & read(std::istream & is, Student_info &s)
{
    if(is)
    {
    is.clear();
    is>>s.name>>s.midterm>>s.final;

    is.clear();
    read_hw(is,s.homework);
    is.clear();
    }

    return is;
}
istream & read_hw(std::istream & in, std::vector<double> & hw)
{
    double x;
    if(in){
        hw.clear();

        while(in>>x)
            hw.push_back(x);
        in.clear();
    }
    return in;

}