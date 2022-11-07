#include "complex.h"
using namespace mylib;

template<>
Complex<double> Complex<double>::operator+(const Complex<double>& c) const
{
    return Complex<double>(real + c.real, imag + c.imag);
}
