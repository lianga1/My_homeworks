#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"

using namespace std;

double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


double grade(double midterm, double final, const std::vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("student has no home work");
    double hw_;

    hw_=median(hw);

	return grade(midterm, final, hw_);
}

//TODO

