#include <gtest/gtest.h>
#include <mystring.h>
#include <cstring>
using namespace mylib;

TEST(string, constructor) {
  string s1;
  string s2("hello");
  string s3(s2);
  string s4 = s3;

  EXPECT_TRUE(strcmp(s1.c_str(), "") == 0) << "should be empty";
  EXPECT_TRUE(strcmp(s2.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s3.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s4.c_str(), "hello") == 0) << "should be hello";
}

TEST(string, compare) {
  string s1 = "abcdefg";
  string s2 = "abcdefg";
  string s3 = "abcdef";
  string s4 = "abcdefh";

  EXPECT_TRUE(s1 == s2) << "should be equal";
  EXPECT_TRUE(s1 != s3) << "should be not equal";
  EXPECT_TRUE(s1 > s3) << "should be greater";
  EXPECT_TRUE(s1 < s4) << "should be less";
  EXPECT_TRUE(s1 >= s2) << "should be greater or equal";
  EXPECT_TRUE(s1 <= s2) << "should be less or equal";
}

TEST(string, concat) {
  string s1 = "abc";
  string s2 = "def";
  string s3 = s1 + s2;
  string s4 = s1;
  s4 += s2;

  EXPECT_TRUE(strcmp(s3.c_str(), "abcdef") == 0) << "should be abcdef";
  EXPECT_TRUE(strcmp(s4.c_str(), "abcdef") == 0) << "should be abcdef";
}

TEST(string, subscript) {
  string s1 = "ackeraa";
  EXPECT_EQ(s1[0], 'a') << "should be a";
  EXPECT_EQ(s1[1], 'c') << "should be c";
  EXPECT_EQ(s1[2], 'k') << "should be k";
  EXPECT_EQ(s1[3], 'e') << "should be e";
  EXPECT_EQ(s1[4], 'r') << "should be r";
  EXPECT_EQ(s1[5], 'a') << "should be a";
  EXPECT_EQ(s1[6], 'a') << "should be a";

  s1[0] = 'b';
  s1[1] = 'd';
  EXPECT_EQ(s1[0], 'b') << "should be b";
  EXPECT_EQ(s1[1], 'd') << "should be d";
}

TEST(string, length) {
  string s1 = "abc";
  string s2 = "abcdefg";
  string s3 = "";

  EXPECT_EQ(s1.length(), 3) << "should be 3";
  EXPECT_EQ(s2.length(), 7) << "should be 7";
  EXPECT_EQ(s3.length(), 0) << "should be 0";
}

TEST(string, swap) {
  string s1 = "abc";
  string s2 = "def";
  s1.swap(s2);

  EXPECT_TRUE(strcmp(s1.c_str(), "def") == 0) << "should be def";
  EXPECT_TRUE(strcmp(s2.c_str(), "abc") == 0) << "should be abc";
}
