#include <gtest/gtest.h>
#include <mystring.h>
#include <cstring>
using namespace mylib;

TEST(string, constructor) {
  string s1;
  string s2("hello");
  string s3(s2);
  string s4 = s3;
  string s5 = "1231231232131232121313";
  string s6(s5);
  string s7 = s5;

  EXPECT_TRUE(strcmp(s1.c_str(), "") == 0) << "should be empty";
  EXPECT_TRUE(strcmp(s2.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s3.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s4.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s5.c_str(), "1231231232131232121313") == 0) << "should be 1231231232131232121313";

  string s8 = string(std::move(s2));
  string s9 = string("asdadsa");
  s9 = std::move(s3);
  string s10 = string(std::move(s5));
  
  EXPECT_TRUE(strcmp(s8.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s9.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s10.c_str(), "1231231232131232121313") == 0) << "should be 1231231232131232121313";
  EXPECT_TRUE(strcmp(s2.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s3.c_str(), "hello") == 0) << "should be hello";
  EXPECT_TRUE(strcmp(s5.c_str(), "") == 0) << "should be empty";
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
  string s5 =  s1 + 'a';
  s5 += 'b';

  EXPECT_TRUE(strcmp(s3.c_str(), "abcdef") == 0) << "should be abcdef";
  EXPECT_TRUE(strcmp(s4.c_str(), "abcdef") == 0) << "should be abcdef";
  EXPECT_TRUE(strcmp(s5.c_str(), "abcab") == 0) << "should be abcab";
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

  EXPECT_THROW(s1.at(7), std::out_of_range) << "should throw out_of_range";
  EXPECT_THROW(s1.at(-1), std::out_of_range) << "should throw out_of_range";

  s1[0] = 'b';
  s1[1] = 'd';
  EXPECT_EQ(s1[0], 'b') << "should be b";
  EXPECT_EQ(s1[1], 'd') << "should be d";
}

TEST(string, size) {
  string s1 = "abc";
  string s2 = "abcdefg";
  string s3 = "";
  // random string of length 15
  string s4 = "123123123213123";
  // random string of length 31
  string s5 = "1231231232131232121313123123123213123";


  EXPECT_EQ(s1.size(), 3) << "should be 3";
  EXPECT_EQ(s2.size(), 7) << "should be 7";
  EXPECT_EQ(s3.size(), 0) << "should be 0";
  EXPECT_EQ(s4.size(), 15) << "should be 15";
  EXPECT_EQ(s5.size(), 37) << "should be 37";

  EXPECT_EQ(s1.capacity(), 15) << "should be 15";
  EXPECT_EQ(s4.capacity(), 15) << "should be 15";

  s4 += "123";
  EXPECT_EQ(s4.size(), 18) << "should be 18";
  EXPECT_EQ(s4.capacity(), 31) << "should be 31";

  string s6 = "123123123123";
  s6 += "123";
  EXPECT_EQ(s6.size(), 15) << "should be 15";
  EXPECT_EQ(s6.capacity(), 15) << "should be 15";
}

TEST(string, iterator) {
  string s1 = "111111111";

  for (auto x : s1) {
    EXPECT_EQ(x, '1') << "should be 1";
  }
}
