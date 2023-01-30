#include "Grad.h"
#include "grade.h"
#include <algorithm>

using namespace std;
//TODO
istream& Grad::read (istream& in)
{
    read_common (in);
    in>>thesis;
    read_hw (in, homework);
    return in;
}

double Grad::grade() const
{
    return min(Core::grade(),thesis);
}