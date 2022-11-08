#include <gtest/gtest.h>
#include <myvector.h>
using namespace mylib;

TEST(vector, constructor) {
  vector<int> v1;
  vector<int> v2(10);
  vector<int> v3(10, 1);
  vector<int> v4(v3);
  vector<int> v5{1, 2, 3, 4, 5};
  vector<int> v6 = v5;
  
  EXPECT_EQ(v1.size(), 0);
  EXPECT_EQ(v2.size(), 10);
  EXPECT_EQ(v3.size(), 10);
  EXPECT_EQ(v4.size(), 10);
  EXPECT_EQ(v5.size(), 5);
  EXPECT_EQ(v6.size(), 5);

  EXPECT_EQ(v1[0], 0);
  EXPECT_EQ(v2[0], 0);
  EXPECT_EQ(v3[0], 1);
  EXPECT_EQ(v4[0], 1);
  EXPECT_EQ(v5[0], 1);
  EXPECT_EQ(v5[1], 2);
  EXPECT_EQ(v5[2], 3);
  EXPECT_EQ(v6[3], 4);
  EXPECT_EQ(v6[4], 5);
}
