#include <iostream>
#include "Expression.h"

int main() {
    auto expr = tan(5.23333 * X()) + 5 * X() * X() - cos(X()) + 1/X();
    auto expr1= ln(2.33 * X() * X());

    auto expr2= exp(X()*X()*2.33);
    auto expr3= X()^3;
    auto expr4= log(4,X()^2);
    std::cout << expr4.toString() << std::endl;
    auto diff = expr4.getDerivative();
    std::cout << diff.toString() << std::endl;
    std::cout << diff.evaluate(1.0) << std::endl;
}