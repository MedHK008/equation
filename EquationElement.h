#ifndef EQUATIONELEMENT_H
#define EQUATIONELEMENT_H

class EquationElement {
public:
    virtual ~EquationElement() = default;
    virtual bool isValid() const = 0;
};

#endif // EQUATIONELEMENT_H