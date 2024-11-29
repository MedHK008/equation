#include "Operator.h"

Operator::Operator(char oper) : op(oper) {}

Operator::~Operator() {} // Implement destructor

char Operator::getOperator() const { return op; }

bool Operator::isValid() const {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int Operator::getPrecedence() const {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool Operator::isLeftAssociative() const {
    return op != '/';
}