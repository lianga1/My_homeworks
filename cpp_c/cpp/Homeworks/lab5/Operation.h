#ifndef OPERATION_H
#define OPERATION_H
#include "BaseExpr.h"


BaseExpr* constant(double value);
BaseExpr* sin(BaseExpr* op);
BaseExpr* cos(BaseExpr* op);
BaseExpr* tan(BaseExpr* op);
BaseExpr* ln(BaseExpr* op);
BaseExpr* exp(BaseExpr* op);
BaseExpr* minus(BaseExpr* op);
BaseExpr* add(BaseExpr* left, BaseExpr* right);
BaseExpr* sub(BaseExpr* left, BaseExpr* right);
BaseExpr* mul(BaseExpr* left, BaseExpr* right);
BaseExpr* div(BaseExpr* left, BaseExpr* right);
BaseExpr* power(BaseExpr* left, BaseExpr* right);
BaseExpr* log(BaseExpr* left, BaseExpr* right);
#endif

