#include <iostream>
#include <stdexcept>
#include "Equation.h"

using namespace std;

int main() {

    string equation = "3 + 5 * ( 2 - 8 ) / 2";
    Equation eq(equation);

    if (eq.isValid()){
        cout << "The equation is valid" << endl;
    } else {
        cout << "The equation is invalid" << endl;
    }

    try {
        cout << eq.evaluate() << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    return 0;
}
