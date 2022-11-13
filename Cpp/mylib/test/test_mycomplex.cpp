#include <mycomplex.h>
#include <gtest/gtest.h>
using namespace mylib;

TEST(complex, constructor) {
  complex<double> c2{};
  complex<float> c3{1.0f};

  EXPECT_EQ(c2.real(), 0);
  EXPECT_EQ(c2.imag(), 0);

  EXPECT_EQ(c3.real(), 1);
  EXPECT_EQ(c3.imag(), 0);
}

TEST(complex, getter_setter) {
  complex<int> c1(1, 2);
  EXPECT_EQ(c1.real(), 1) << "should be 1";
  EXPECT_EQ(c1.imag(), 2) << "should be 2";
  c1.real(3);
  c1.imag(4);
  EXPECT_EQ(c1.real(), 3) << "should be 3";
  EXPECT_EQ(c1.imag(), 4) << "should be 4";
}

TEST(complex, copy) {
  complex<int> c1(1, 2);
  complex<int> c2 = c1;
  complex<int> c3(c2);

  EXPECT_EQ(c2.real(), c1.real()) << "should be same";
  EXPECT_EQ(c2.imag(), c1.imag()) << "should be same";
  EXPECT_EQ(c3.real(), c2.real()) << "should be same";
  EXPECT_EQ(c3.imag(), c2.imag()) << "should be same";
}

TEST(complex, arithmetic_with_basic_type) {
  complex<int> c1(1, 2);
  c1 += 2;
  EXPECT_EQ(c1.real(), 3) << "should be 3";
  EXPECT_EQ(c1.imag(), 2) << "should be 2";

  c1 *= 2;
  EXPECT_EQ(c1.real(), 6) << "should be 6";
  EXPECT_EQ(c1.imag(), 4) << "should be 4";

  c1 /= 2;
  EXPECT_EQ(c1.real(), 3) << "should be 3";
  EXPECT_EQ(c1.imag(), 2) << "should be 2";

  c1 -= 2;
  EXPECT_EQ(c1.real(), 1) << "should be 1";
  EXPECT_EQ(c1.imag(), 2) << "should be 2";
}

TEST(complex, arithmetic_with_complex) {
  complex<int> c1(2, 3);
  complex<int> c2(4, 5);

  c1 += c2;
  EXPECT_EQ(c1.real(), 6) << "should be 6";
  EXPECT_EQ(c1.imag(), 8) << "should be 8";

  c1 -= c2;
  EXPECT_EQ(c1.real(), 2) << "should be 2";
  EXPECT_EQ(c1.imag(), 3) << "should be 3";

  c1 *= c2;
  EXPECT_EQ(c1.real(), -7) << "should be -7";
  EXPECT_EQ(c1.imag(), 22) << "should be 22";

  c2.real(1);
  c2.imag(0);
  c1 /= c2;
  EXPECT_EQ(c1.real(), -7) << "should be -7";
  EXPECT_EQ(c1.imag(), 22) << "should be 22";

  c1 = complex<int>(2, 3);
  c2 = complex<int>(4, 5);
  complex<int> c3 = c1 + c2;
  EXPECT_EQ(c3.real(), 6) << "should be 6";
  EXPECT_EQ(c3.imag(), 8) << "should be 8";

  c3 = c1 - c2;
  EXPECT_EQ(c3.real(), -2) << "should be -2";
  EXPECT_EQ(c3.imag(), -2) << "should be -2";

  c3 = c1 * c2;
  EXPECT_EQ(c3.real(), -7) << "should be -7";
  EXPECT_EQ(c3.imag(), 22) << "should be 22";

  c2.real(1);
  c2.imag(0);
  c3 = c1 / c2;
  EXPECT_EQ(c3.real(), 2) << "should be 2";
  EXPECT_EQ(c3.imag(), 3) << "should be 3";
}

TEST(complex, compare) {
  complex<int> c1(1, 2);
  complex<int> c2(1, 2);
  complex<int> c3(2, 3);

  EXPECT_TRUE(c1 == c2) << "should be same";
  EXPECT_FALSE(c1 == c3) << "should be different";
  EXPECT_FALSE(c1 != c2) << "should be same";
  EXPECT_TRUE(c1 != c3) << "should be different";

  EXPECT_TRUE(c1 < c3) << "should be less";
  EXPECT_FALSE(c1 < c2) << "should be same";
  EXPECT_FALSE(c3 < c1) << "should be greater";

  EXPECT_TRUE(c1 <= c3) << "should be less";
  EXPECT_TRUE(c1 <= c2) << "should be same";
  EXPECT_FALSE(c3 <= c1) << "should be greater";

  EXPECT_FALSE(c1 > c3) << "should be less";
  EXPECT_FALSE(c1 > c2) << "should be same";
  EXPECT_TRUE(c3 > c1) << "should be greater";

  EXPECT_FALSE(c1 >= c3) << "should be less";
  EXPECT_TRUE(c1 >= c2) << "should be same";
  EXPECT_TRUE(c3 >= c1) << "should be greater";
}

TEST(complex, literals) {
  complex<double> c1 = 2.0_i;

  EXPECT_EQ(c1.real(), 0) << "should be 0";
  EXPECT_EQ(c1.imag(), 2) << "should be 2";
}

