#ifndef GUARD_CORE
#define GUARD_CORE

#include <string>
#include <istream>
#include <iostream>
#include "Vec.h"


class Core{

    friend class Student_info;
    //TODO
    public:

    virtual ~Core() {};
    Core():midterm(0),final(0) {}
    Core (std::istream& is) { read( is);}
    std::string name() const ;
    virtual std::istream& read(std::istream&);
    virtual double grade() const;


    protected:
    std::istream & read_hw(std::istream & in, Vec<double> & hw);
    std::istream& read_common(std::istream&); 
    double midterm, final;
    Vec<double> homework;
    virtual Core* clone() const {return new Core(*this);}
    private:

    std::string n;



};

bool compare(const Core &x, const Core &y);
bool compare_grade(const Core &x, const Core &y);
bool compare_grade_ptr(const Core *x, const Core *y);
std::istream & read_hw(std::istream & in, Vec<double> & hw);

#endif
