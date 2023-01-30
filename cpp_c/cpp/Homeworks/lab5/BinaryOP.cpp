#include "UnaryOP.h"
#include "BinaryOP.h"
#include "Operation.h"
#include <cmath>

double Addition::evaluate() const {
    return left->evaluate() + right->evaluate();
}

double Addition::evaluate(double x) const {
    return left->evaluate(x) + right->evaluate(x);
}

BaseExpr *Addition::getDerivative() const {
    return add(left->getDerivative(), right->getDerivative());
}

std::string Addition::toString() const {
    return "("+left->toString()+"+"+right->toString()+")";
}
BaseExpr *Addition::clone() const {
    return new Addition(left->clone(), right->clone());
}

double Subtraction::evaluate() const {
    return left->evaluate() - right->evaluate();
}

double Subtraction::evaluate(double x) const {
    return left->evaluate(x) - right->evaluate(x);
}

BaseExpr *Subtraction::getDerivative() const {
    return sub(left->getDerivative(),right->getDerivative());
}

std::string Subtraction::toString() const {
    return "("+left->toString()+"-"+right->toString()+")";
}
BaseExpr *Subtraction::clone() const {
    return new Subtraction(left->clone(), right->clone());
}

double Multiplication::evaluate() const {
    return left->evaluate() * right->evaluate();
}

double Multiplication::evaluate(double x) const {
    return left->evaluate(x) * right->evaluate(x);
}

BaseExpr *Multiplication::getDerivative() const {
    auto l = mul(left->getDerivative(),right);
    auto r = mul(left,right->getDerivative());
    return add(l,r);
}

std::string Multiplication::toString() const {
    return "("+left->toString()+"*"+right->toString()+")";
}

BaseExpr *Multiplication::clone() const {
    return new Multiplication(left->clone(), right->clone());
}

double Division::evaluate() const {
    if(right->alwaysZero()){
        throw std::runtime_error("Divided by zero error");
    }
    return left->evaluate() / right->evaluate();
}

double Division::evaluate(double x) const {
    if(right->evaluate(x) == 0){
        throw std::runtime_error("Divided by zero error");
    }
    return left->evaluate(x) / right->evaluate(x);
}

BaseExpr *Division::getDerivative() const {
    auto numerator = new Subtraction(new Multiplication(left->getDerivative(),right), new Multiplication(left, right->getDerivative()));
    auto denominator = new Multiplication(right,right);
    return div(numerator, denominator);
}

std::string Division::toString() const {
    if(right->alwaysZero()){
        throw std::runtime_error("Divided by zero error");
    }
    return "("+left->toString()+"/"+right->toString()+")";
}

BaseExpr *Division::clone() const {
    return new Division(left->clone(), right->clone());
}

double Power::evaluate() const{
    if(right->alwaysZero() && left->alwaysZero()){
        throw std::runtime_error("Power 0 by 0 error");
    }
    return pow(left->evaluate(),right->evaluate());
}

double Power::evaluate(double x) const{
    if(right->alwaysZero() && left->alwaysZero()){
        throw std::runtime_error("Power 0 by 0 error");
    }
    return pow(left->evaluate(x),right->evaluate(x));
}

BaseExpr* Power::getDerivative() const {
    if(right->alwaysZero() && left->alwaysZero()){
        throw std::runtime_error("Power 0 by 0 error");
    }    
    
    if(left->hasVariable() && !right->hasVariable())
    {
        if(right->evaluate()==2){
            return mul(right,left);
        }
        return mul(right,power(left,sub(right,constant(1))));
    }    
    if(!left->hasVariable() && !right->hasVariable())
    {
        return constant(0);
    }
    if(left->hasVariable() && right->hasVariable())
    {
        throw std::runtime_error("We cannot handle the function with both bottom and top are variables");
    }

        return mul(ln(left),power(left,right));
    

}
std::string Power::toString() const{
    return left->toString()+"^"+right->toString();
}
BaseExpr *Power::clone() const {
    return new Power(left->clone(), right->clone());
}


//about the log(a,x)
double Log::evaluate() const{
    if(left->hasVariable()){
        throw std::runtime_error("the bottom cannot be variable");
    }
    if(!right->hasVariable()){
        if(right->evaluate()<=0.0)
        {
            throw std::runtime_error("out of domain of definition");

        }
        


    }
    return log(left->evaluate())/log(right->evaluate());
}
double Log::evaluate(double x) const{
        if(left->hasVariable()){
        throw std::runtime_error("the bottom cannot be variable");
    }
    if(!right->hasVariable()){
        if(right->evaluate()<=0.0)
        {
            throw std::runtime_error("out of domain of definition");

        }
        


    }
    return log(left->evaluate(x))/log(right->evaluate(x));
}

BaseExpr* Log::getDerivative() const{
    return mul(div(constant(1),mul(ln(left),right)),right->getDerivative());
}
std::string Log::toString() const{
    return "log("+left->toString()+","+right->toString()+")";
}
BaseExpr* Log::clone() const{
    return new Log(left->clone(), right->clone());
}