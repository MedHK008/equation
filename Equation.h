#ifndef EQUATION_H
#define EQUATION_H

#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "EquationElement.h"
#include "Number.h"
#include "Operator.h"
#include "Parenthesis.h"

using namespace std;

class Equation {
private:
    vector<EquationElement*> elements;
public:
    Equation(const string& expression);

    ~Equation();

    void parseExpression(const string& expression);

    bool isValid() const;

    double evaluate() const;

    double applyOp(double a, double b, char op) const;

};

#endif // EQUATION_H