#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<string> StrVec;



int main()
{
    StrVec strs;
    vector<int> sizeofstr;
    string str;

    int n,k;
    cin>>n;
    cin>>k;

    int num;

    for(num=0;num<n;num++)
    {
        cin>>str;

        strs.push_back(str);

        int sz=str.size();
        int i,check=0;

        for(i=0;i<sizeofstr.size();i++)
        {
            if(sizeofstr[i]==sz)
            {
                check=1;
                break;
            }
        }
        if(check==0)
            sizeofstr.push_back(sz);
    }
    sort(sizeofstr.begin(),sizeofstr.end());
    if(k>sizeofstr.size())
        return 1;
    else
    {
        int sze=sizeofstr[k-1];
        for(num=0;num<n;num++)
        {
            if(strs[num].size()==sze)
                cout<<strs[num]<<endl;
        }
    }    
    
    return 0;
}