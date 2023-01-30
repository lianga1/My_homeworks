#include<iostream>
#include<fstream>
#include<vector>
#include<utility>

/*
21.	若两个素数之差为2，则称这两个素数为双胞胎数。例如，5和7就是双胞胎数，编程求出[200，1000]之间有多少对双胞胎数。
请将所有满足条件的数依次显示在屏幕上，并统计一共有多少个符合条件的数，同时将所有结果和总数存入名为“学号-f21.txt”的文本文件中
*/
using namespace std;

bool is_prime (int number);


int main()
{
    ofstream file;
    file.open("3021001404-f21.txt");//open the output file
    
    int number1,number2;
    vector<pair<int,int>> pairs;

    for(number1=number2=200;number1<=1000&&number2<=1000;number1++)//
    {
        if(is_prime(number1)){
            number2=number1+2;
            if(is_prime(number2)){
                pairs.push_back(make_pair(number1,number2));
            }
        }
    }// scan the numbers to get the vector of pair
       
    //output the numbers to the txt
    for(auto iter=pairs.begin();iter!=pairs.end();iter++)
    {
        file<<iter->first<<' '<<iter->second<<endl;
        cout<<iter->first<<' '<<iter->second<<endl;
    }
    if(pairs.empty())
        cout<<"there isn't a pair"<<endl;
}

bool is_prime (int number)
{
    int i;
    if(number<=1)
        return false;
    else if(number==2)
        return true;
    else
    {
        for(i=2;i<number;i++){
            if(number%i==0)
            return false;
        }

    }
    return true;
}