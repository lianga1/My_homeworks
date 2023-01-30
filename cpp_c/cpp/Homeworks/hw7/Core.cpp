#include "Core.h"
#include "grade.h"

using namespace std;
//TODO

string Core::name() const {return n;}

double Core::grade() const{
    return ::grade(midterm,final,homework);
}

std::istream& Core::read_common (std::istream& in)
{
    in>>n>>midterm>>final;
    return in;
}

istream& Core::read(std::istream& in) 
{
    read_common(in);
    read_hw (in, homework);
    return in;

}
istream & Core::read_hw(istream & in, Vec<double> & hw)
{
	if(in){
		hw.clear();
		double x;//a variable into which to read
		while(cin >> x){
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}
