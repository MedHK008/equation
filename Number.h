#ifndef NUMBER_H
#define NUMBER_H

#include "EquationElement.h"

class Number : public EquationElement {
public:
    double value;

    Number(double val);

    bool isValid() const override;
};

#endif // NUMBER_H