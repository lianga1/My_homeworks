#ifndef _STRING_H
#define _STRING_H

#include <algorithm>
#include <iostream>
#include <cstring>
#include "Vec.h"

//TODO
class Str{
    // input
    friend std::istream& operator>>(std::istream&, Str&);

    public:
    typedef Vec<char>::size_type size_type;


    
    //size
    size_type size() const {return data.size();}


    //construction function
    Str(){}
    Str(size_type n, char c):data (n,c){}
    Str(const char* cp)
    {
        std::copy(cp,cp+strlen(cp),std::back_inserter(data));

    }
    template <class In>Str (In b, In e){
        std::copy(b,e,std::back_inserter(data));
    }
    //operations
    char& operator[] (size_type i){ return data[i];}
    const char& operator[] (size_type i) const { return data[i];}
    Str& operator += (const Str&s)
    {
        std::copy(s.data.begin(),s.data.end(),std::back_inserter(data));
        return *this;
    }

    private:
    Vec<char> data;
};
std::ostream& operator<<(std::ostream& , const Str& );

Str operator + (const Str&, const Str&);
#endif
