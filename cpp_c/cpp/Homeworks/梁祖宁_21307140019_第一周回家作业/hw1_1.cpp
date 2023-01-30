//梁祖宁 21307140019

#include <algorithm>
#include <iostream>
#include <ios>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

int main() 
{ 
	cout<<"please enter your name";
	string name;
	cin>>name;
	cout<<"Hello "+name<<endl;
	cout<<"Please enter you midterm and final exam grades:";

	double midterm,final_exam;
	cin>>midterm;
	cin>>final_exam;

	cout<<"Enter all your homework grades, followed by end-of-file:"<<endl;
	vector<double> homework;
	vector<double>::size_type size;
	double x;
	while(cin>>x)
		homework.push_back(x);

	size=homework.size();
	if(size==0)
	{
		cout<<"you must enter your grades."<<endl;
		cout<<"please restart the program"<<endl;
		return 1;

	}
	sort(homework.begin(),homework.end());
	int mid;
	mid=size/2;
	double mid_score;
	mid_score=(size%2==0)?((homework[mid]+homework[mid-1])/2):homework[mid];

	streamsize prec =cout.precision();
	setprecision(3);
	double score;
	score=0.4*final_exam+0.2*midterm+0.4*mid_score;
	cout<<"Your final grade is"<<score<<endl;
	cout<<"Press any key to continue";

	return 0; 
} 
