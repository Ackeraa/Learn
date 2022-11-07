#include <gtest/gtest.h>
#include <complex.h>
using namespace mylib;

TEST(complex, add) {
    Complex<double> c1 = Complex<double>(1, 2);
    Complex<double> c2 = Complex<double>(3, 4);
    const Complex<double> c3 = c1 + c2;
    EXPECT_EQ(c3.get_real(), 5) << "should be 4";
}
