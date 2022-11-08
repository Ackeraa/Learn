#pragma once
#include <cstring>
#include <iostream>

namespace mylib {

class string {
public:
  string(const char *s = 0);
  string(const string &s);
  string &operator=(const string &s);
  ~string();

  const char *c_str() const { return str; }
  size_t size() const { return strlen(str); }
  void swap(string &s);
  
  bool operator==(const string &s) const;
  bool operator!=(const string &s) const;
  bool operator<(const string &s) const;
  bool operator>(const string &s) const;
  bool operator<=(const string &s) const;
  bool operator>=(const string &s) const;

  string operator+(const string &s) const;
  string &operator+=(const string &s);

  friend std::ostream &operator<<(std::ostream &os, const string &s);
  friend std::istream &operator>>(std::istream &is, string &s);

  char &operator[](size_t i) { return str[i]; }


private:
  char *str;
};

inline string::string(const char *s) {
  if (s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
  } else {
    str = new char[1];
    *str = '\0';
  }
}

inline string::~string() { delete[] str; }

inline string::string(const string &s) {
  str = new char[strlen(s.str) + 1];
  strcpy(str, s.str);
}

inline void string::swap(string &s) {
  char *tmp = str;
  str = s.str;
  s.str = tmp;
}

inline string &string::operator=(const string &s) {
  if (this == &s)
    return *this;
  delete[] str;
  str = new char[strlen(s.str) + 1];
  strcpy(str, s.str);

  return *this;
}

inline bool string::operator==(const string &s) const {
  return strcmp(str, s.str) == 0;
}

inline bool string::operator!=(const string &s) const {
  return strcmp(str, s.str) != 0;
}

inline bool string::operator<(const string &s) const {
  return strcmp(str, s.str) < 0;
}

inline bool string::operator<=(const string &s) const {
  return strcmp(str, s.str) <= 0;
}

inline bool string::operator>(const string &s) const {
  return strcmp(str, s.str) > 0;
}

inline bool string::operator>=(const string &s) const {
  return strcmp(str, s.str) >= 0;
}

inline string string::operator+(const string &s) const {
  string tmp;
  delete[] tmp.str;
  tmp.str = new char[strlen(str) + strlen(s.str) + 1];
  strcpy(tmp.str, str);
  strcat(tmp.str, s.str);

  return tmp;
}

inline string &string::operator+=(const string &s) {
  *this = *this + s;
  return *this;
}

inline std::ostream &operator<<(std::ostream &os, const string &s) {
  os << s.str;
  return os;
}

inline std::istream &operator>>(std::istream &is, string &s) {
  char buf[1024];
  is >> buf;
  s = string(buf);
  return is;
}

} // namespace mylib
