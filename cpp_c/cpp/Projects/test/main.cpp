#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;




bool compare (A a){
    return a.showint1()>a.showint2();
}



struct S{
    int a;
    char b;
    string c;
    private:
    int aa;

};


class C{
    public:
    int a;
    char b;
    string c;
    private:
    int aa;
    char bb;
    string cc;
};

class Bird{

    public:
    void jump(){vy=1;}
    
    void tick(){
        x+=vx;
        y+=vy;      
    }

    void show();


    private:
    double x,y;
    double vx,vy;
};

int main()
{
    // A a;
    // A a1(1,2,'c',"Hello");
    A a2(cin);
    S s;
    C c;

    cout<<a2.showint1()<<endl;
    return 0;

}