#include <gtest/gtest.h>
#include <mymatrix.h>

using namespace mylib;

TEST(matrix, constructor) {
  matrix<int> m1(2, 3);
  matrix<int> m2(m1);
  matrix<int> m3 = m2;
  matrix<int> m4 = { {1, 2, 3}, {4, 5, 6} };

  EXPECT_EQ(m1.size(), 6) << "should be 6";
  EXPECT_EQ(m2.size(), 6) << "should be 6";
  EXPECT_EQ(m3.size(), 6) << "should be 6";
  EXPECT_EQ(m4.size(), 6) << "should be 6";

  EXPECT_EQ(m1.rows(), 2) << "should be 2";
  EXPECT_EQ(m2.rows(), 2) << "should be 2";
  EXPECT_EQ(m3.rows(), 2) << "should be 2";
  EXPECT_EQ(m4.rows(), 2) << "should be 2";

  EXPECT_EQ(m1.cols(), 3) << "should be 3";
  EXPECT_EQ(m2.cols(), 3) << "should be 3";
  EXPECT_EQ(m3.cols(), 3) << "should be 3";
  EXPECT_EQ(m4.cols(), 3) << "should be 3";

  EXPECT_EQ(m1(0, 0), 0) << "should be 0";
  EXPECT_EQ(m1(0, 1), 0) << "should be 0";

  EXPECT_EQ(m4(0, 0), 1) << "should be 1";
  EXPECT_EQ(m4(0, 1), 2) << "should be 2";
  EXPECT_EQ(m4(2, 2), 6) << "should be 6";
}

