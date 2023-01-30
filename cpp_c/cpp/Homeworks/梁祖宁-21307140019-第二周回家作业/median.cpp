#include <vector>
#include <algorithm>
#include "median.h"
using namespace std;

double median(vector<double> vec)
{
    sort(vec.begin(),vec.end());
    int median=vec.size()/2;
    if (vec.size()%2==0)
        return (vec[median/2]+vec[(median/2)+1])/2;
    else
        return vec[(median/2)+1];
}
double average(const vector<double> &vec)
{
    int i;
    int count=0;
    double sum=0.0;
    for(i=0;i<vec.size();i++)
    {
        sum+=vec[i];
        count ++;
    }
    return sum/count;
}