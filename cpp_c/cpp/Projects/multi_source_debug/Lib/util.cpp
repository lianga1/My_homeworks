#include "util.h"
// You can include any std header file here.
#include <regex>

using namespace std;

/**
 * @brief split a string by the delimiter space aka ` ` and append the result to the back of the vector `ret`.
 * 
 * @param s the string to be splitted
 * @param ret result vector. In this lab, argument `ret` is a global variable 
 *            and is used to store the words according to the appearance order.
 */
void split_string(const string& s, vector<string>& ret) {
    // hint: you can use function `substr` to get a substring of the string `s`
    //       if you know what regular expression is, you can use `regex` to easily split the string `s`
    //       stringstream may be useful, too
    /* Your code here */

        string::size_type i=0,j=0;
    while(i!=s.size())
    {
        while(i!=s.size()&&isspace(s[i]))
            i++;
        j=i;
        while(j!=s.size()&&!isspace(s[j]))
            j++;
        if(i!=j)
            ret.push_back(s.substr(i,j-i));
        i=j;
    }
    return;
}
