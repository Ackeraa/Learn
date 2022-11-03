#include<iostream>
#include "complex.h"

using namespace std;
using namespace demo;

int main() {
    Complex c = Complex(1, 2);
    cout << c.get_real() << ' ' << c.get_imag() << endl;

    cout << __cplusplus << endl;


    return 0;
}
