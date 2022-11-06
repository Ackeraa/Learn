#include "complex1.h"

template<>
Complex<double> Complex<double>::operator+(const Complex<double>& c) const
{
    return Complex<double>(real + c.real, imag + c.imag);
}
