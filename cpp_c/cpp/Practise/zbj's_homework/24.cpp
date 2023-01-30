#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int step=0;
    int first=1;
    int result=1;
    vector<int> sequence;

    for(first=0;first<=6;first++){
        if((26-4*first)%6!=0)
            continue;
        step=(26-4*first)/6;
        if(first*(first+step)*(first+step*2)*(first+step*3)==880)
            break;

    }
    ofstream file("3021001404-f24.txt");
    int q;
   // cout<<first<<' '<<step<<endl;
    for(q=0;q<6;q++)
    {
        int num=first+q*step;
       // cout<<num<<endl;
        sequence.push_back(num); 
    }
    for(q=0;q<6;q++)
    {
        result*=sequence[q];
       // cout<<sequence[q]<<endl;
    }

    file<<result<<endl;
    cout<<result<<endl;

    return 0;
}