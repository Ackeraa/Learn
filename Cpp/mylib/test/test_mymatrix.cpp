#include <gtest/gtest.h>
#include <mymatrix.h>

using namespace mylib;

TEST(matrix, constructor) {
  matrix<int> m1(2, 3);
  matrix<int> m2(m1);
  matrix<int> m3 = m2;
  matrix<int> m4 = {{1, 2, 3}, {4, 5, 6}};

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
  EXPECT_EQ(m4(1, 2), 6) << "should be 6";
}

TEST(matrix, move) {
  matrix<int> m1(2, 3);
  matrix<int> m2 = std::move(m1);

  EXPECT_EQ(m1.size(), 0) << "should be 0";
  EXPECT_EQ(m2.size(), 6) << "should be 6";

  matrix<int> m3(4, 5);
  m3 = std::move(m2);

  EXPECT_EQ(m2.size(), 20) << "should be 20";
  EXPECT_EQ(m3.size(), 6) << "should be 6";
}

TEST(matrix, arithmetic) {
  matrix<int> m1 = {{1, 2, 3}, {4, 5, 6}};
  matrix<int> m2 = {{2, 3, 4}, {5, 6, 7}};
  matrix<int> m3 = {{3, 4, 5, 5}, {6, 7, 8, 9}};
  matrix<int> m1_plus_m2 = m1 + m2;

  EXPECT_EQ(m1_plus_m2(0, 0), 3) << "should be 3";
  EXPECT_EQ(m1_plus_m2(0, 1), 5) << "should be 5";
  EXPECT_EQ(m1_plus_m2(1, 2), 13) << "should be 13";

  EXPECT_THROW(m1 + m3, std::runtime_error);
}
