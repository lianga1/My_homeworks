#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"

using namespace std;

double grade(double midterm,double final,double homework)
{
    
    return midterm*0.2+final*0.4+0.4*homework;
}
double grade(double midterm, double final, const std::vector<double> & hw)
{
    return midterm*0.2+final*0.4+0.4*median(hw);
}
double grade(const Student_info &s)
{
    return s.midterm*0.2+s.final*0.4+0.4*(average(s.homework)*0.6+median(s.homework)*0.4);
}

bool fgrade(const Student_info &s)
{
    return grade(s)>=60;
}