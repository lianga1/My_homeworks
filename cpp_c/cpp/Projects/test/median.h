#ifndef __MEDIAN_H__
#define __MEDIAN_H__

#include<algorithm>
#include<vector>
#include<algorithm>
using namespace std;

int median(vector<int> &a);

template <class T>
T myplus (T a,T b)
{
    T c=a+b;
    
}

class A{
    public:
    A (){};
    A (int a1,int a2,char c,string s):a(a1),a2(a2),b(c),c(s){}
    A (istream& is){
        is>>a;
        is>>a2;
    }
    int showint1 ();
    int showint2 (){return a2;}
    void setnum (int n){a=n;}
    
    private:
    int a;
    int a2;
    char b;
    string c;
};


#endif