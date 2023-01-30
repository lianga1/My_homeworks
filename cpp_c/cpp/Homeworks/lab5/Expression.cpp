#include "Expression.h"
#include "Operation.h"

Expression::Expression(double value) : ptr(new Constant(value)) {}

Expression::Expression(BaseExpr *ptr) : ptr(ptr) {}

std::string Expression::toString() const { return ptr->toString(); }

double Expression::evaluate() const { return ptr->evaluate(); }

double Expression::evaluate(double x) const { return ptr->evaluate(x); }

Expression Expression::getDerivative() const {
    return Expression(ptr->getDerivative());
}

Expression X() { return Expression(new Variable()); }
Expression sin(Expression operand) { return Expression(new Sin(operand.ptr->clone())); }
Expression cos(Expression operand) {
    return Expression((new Cos(operand.ptr->clone())));
}
Expression tan(Expression operand){
    return Expression((new Tan(operand.ptr->clone())));
}
Expression ln(Expression operand){
    return Expression((new Ln(operand.ptr->clone())));
}
Expression exp(Expression operand){
    return Expression((new Exp(operand.ptr->clone())));
}
Expression operator-(Expression operand) {
    return Expression(new Minus(operand.ptr->clone()));
}
Expression operator+(Expression left, Expression right) {
    return Expression(add(left.ptr, right.ptr));
}
Expression operator-(Expression left, Expression right) {
    return Expression(sub(left.ptr, right.ptr));
}
Expression operator*(Expression left, Expression right) {
    return Expression(mul(left.ptr, right.ptr));
}
Expression operator/(Expression left, Expression right) {
    return Expression(div(left.ptr, right.ptr));
}
Expression operator^(Expression left, Expression right){
    return Expression(power(left.ptr,right.ptr));
}
Expression log(Expression left, Expression right){
    return Expression(log(left.ptr,right.ptr));
}