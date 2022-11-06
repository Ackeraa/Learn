#include <gtest/gtest.h>
#include <complex1.h>

TEST(mylib, add) {
    Complex<double> c1 = Complex<double>(1, 2);
    Complex<double> c2 = Complex<double>(3, 4);
    const Complex<double> c3 = c1 + c2;
    EXPECT_EQ(c3.get_real(), 4) << "should be 4";
}
