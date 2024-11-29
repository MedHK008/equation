#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include "EquationElement.h"

class Parenthesis : public EquationElement {
public:
    char type;

    Parenthesis(char t);

    bool isValid() const override;
};

#endif // PARENTHESIS_H