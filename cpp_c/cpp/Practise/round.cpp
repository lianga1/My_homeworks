#include<iostream>
#include<string>
/*
This is a cpp for training the "while" .
What I want to do is build a program to output a rectangle with a greeting in the middle of it.
*/
using namespace std;
int main()
{
    cout<<"please enter your name"<<endl;
    string name ;
    cin>>name;
    const int pad=1;
    const int cols=name.size()*2+3;
    const int rows=pad*2+3;

    int r,c;

    for(r=0;r<rows;r++)
    {
        for(c=0;c<cols;c++)
        {
            if(r==1||r==rows||c==1||c==cols)
                cout<<"*";
            
        }
    }
    
    return 0;
}