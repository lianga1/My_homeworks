#include "median.h"

int median(vector<int> & a)
{
    sort(a.begin(),a.end());
    
    size_t sz = a.size();

    int med = sz%2==0 ? (a[(sz/2)-1]+a[sz/2])/2 : a[sz/2];

    return med;
}

int A::showint1(){
    return a;
}