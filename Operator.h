#ifndef OPERATOR_H
#define OPERATOR_H

#include "EquationElement.h"


class Operator : public EquationElement {
private:
    char op;
public:
    Operator(char oper);
    virtual ~Operator(); // Add virtual destructor
    char getOperator() const;
    bool isValid() const override;
    int getPrecedence() const;
    bool isLeftAssociative() const;
};

#endif // OPERATOR_H