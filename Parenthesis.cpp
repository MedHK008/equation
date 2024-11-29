#include "Parenthesis.h"

Parenthesis::Parenthesis(char t) : type(t) {}

bool Parenthesis::isValid() const{
    return type == '(' || type == ')';
}