#include "Equation.h"

Equation::Equation(const string& expression) : elements() {
    parseExpression(expression);
}

Equation::~Equation() {
    for (auto element : elements) {
        delete element;
    }
}

void Equation::parseExpression(const string& expression) {
    istringstream stream(expression);
    char c;
    while (stream >> c) {
        if (isdigit(c) || (c == '.' && stream.peek() != EOF && isdigit(stream.peek()))) {
            stream.putback(c);
            double number;
            stream >> number;
            elements.push_back(new Number(number));
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            elements.push_back(new Operator(c));
        } else if (c == '(' || c == ')') {
            elements.push_back(new Parenthesis(c));
        } else if (!isspace(c)) {
            throw invalid_argument("Invalid character in equation");
        }
    }
}

bool Equation::isValid() const {
    int balance = 0;
    bool lastWasOperator = true;

    for (const auto &element : elements) {
        if (dynamic_cast<Number*>(element)) {
            lastWasOperator = false;
        } else if (auto op = dynamic_cast<Operator*>(element)) {
            if (lastWasOperator) return false;
            lastWasOperator = true;
        } else if (auto paren = dynamic_cast<Parenthesis*>(element)) {
            if (paren->type == '(') {
                balance++;
            } else {
                balance--;
                if (balance < 0) return false;
            }
        }
    }
    return balance == 0 && !lastWasOperator;
}

double Equation::evaluate() const {
    stack<double> values;
    stack<char> ops;

    auto applyOp = [](double a, double b, char op) -> double {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: throw invalid_argument("Invalid operator");
        }
    };

    for (const auto &element : elements) {
        if (auto num = dynamic_cast<Number*>(element)) {
            values.push(num->value);
        } else if (auto op = dynamic_cast<Operator*>(element)) {
            while (!ops.empty() && ops.top() != '(' && 
                   (op->getPrecedence() < Operator(ops.top()).getPrecedence() ||
                   (op->getPrecedence() == Operator(ops.top()).getPrecedence() && op->isLeftAssociative()))) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char oper = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, oper));
            }
            ops.push(op->getOperator());
        } else if (auto paren = dynamic_cast<Parenthesis*>(element)) {
            if (paren->type == '(') {
                ops.push('(');
            } else {
                while (!ops.empty() && ops.top() != '(') {
                    double val2 = values.top(); values.pop();
                    double val1 = values.top(); values.pop();
                    char oper = ops.top(); ops.pop();
                    values.push(applyOp(val1, val2, oper));
                }
                ops.pop();
            }
        }
    }

    while (!ops.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char oper = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, oper));
    }

    return values.top();
}
