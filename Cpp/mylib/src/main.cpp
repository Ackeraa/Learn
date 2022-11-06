#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex<double> c1 = Complex<double>(2, 2);
    Complex<double> c2 = Complex<double>(3, 4);
    Complex<double> c3 = c1 + c2;

    cout << c3.get_real() << endl;

    return 0;
}
