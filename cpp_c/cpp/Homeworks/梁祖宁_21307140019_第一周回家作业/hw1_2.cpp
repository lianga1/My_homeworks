//梁祖宁 21307140019
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{ 
	cout<<"Please enter the names and end it with EOF"<<endl;
	vector<string> names;
	string name;
	while(cin>>name)
		names.push_back(name);
	vector<string> longests;
	vector<string> shortests;

	longests.push_back(names[0]);
	shortests.push_back(names[0]);
	int i;
	for(i=0;i<=names.size()-1;i++)
	{
		if(names[i].size()==longests[0].size()&& (i>0))
			longests.push_back(names[i]);		
		if(names[i].size()>longests[0].size())
		{
			longests.clear();
			longests.push_back(names[i]);
		}
		if(names[i].size()==shortests[0].size()&& (i>0))
			shortests.push_back(names[i]);
		if(names[i].size()<shortests[0].size())
		{
			shortests.clear();
			shortests.push_back(names[i]);
		}

		
	}
	cout<<"Longest:";
	for(i=0;i<longests.size();i++)
		cout<<longests[i]<<" ";
	cout<<endl;
	cout<<"Shortest:";
	for(i=0;i<shortests.size();i++)
		cout<<shortests[i]<<" ";
	cout<<endl;

	//TODO

	return 0; 
}
