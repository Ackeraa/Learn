#pragma once
#include <cstring>
#include <iostream>

namespace mylib {

class string {
public:
  string();
  string(const char *s);
  string(const string &s) { copy_from(s); }
  string(string &&s) { move_from(s); }
  string &operator=(const string &s);
  string &operator=(string &&s);

  ~string() {
    if (sz > short_max)
      delete[] str;
  }

  bool operator==(const string &s) const;
  bool operator!=(const string &s) const;
  bool operator<(const string &s) const;
  bool operator>(const string &s) const;
  bool operator<=(const string &s) const;
  bool operator>=(const string &s) const;

  string operator+(char c) const;
  string &operator+=(char c);
  string operator+(const string &s) const;
  string &operator+=(const string &s);

  friend std::ostream &operator<<(std::ostream &os, const string &s);
  friend std::istream &operator>>(std::istream &is, string &s);

  char &operator[](int i) { return str[i]; }
  const char &operator[](int i) const { return str[i]; }

  char &at(int i) {
    check(i);
    return str[i];
  }
  const char &at(int i) const {
    check(i);
    return str[i];
  }

  char *c_str() { return str; }
  const char *c_str() const { return str; }
  int size() const { return sz; }
  void check(int i) const;
  bool empty() const { return sz == 0; }
  int capacity() const { return sz <= short_max ? short_max : sz + space; }

  char *expand(const char *str, int n);
  void copy_from(const string &s);
  void move_from(string &s);
  char *begin() { return str; }
  char *end() { return str + sz; }
  const char *begin() const { return str; }
  const char *end() const { return str + sz; }

private:
  static const int short_max = 15;
  int sz;
  char *str;
  union {
    int space;
    char ch[short_max + 1];
  };
};

inline string::string() : sz{0}, str{ch} { ch[0] = 0; }

inline string::string(const char *s)
    : sz{static_cast<int>(strlen(s))},
      str{(sz <= short_max) ? ch : new char[sz + 1]}, space{0} {
  strcpy(str, s);
}

inline string &string::operator=(const string &s) {
  if (this == &s)
    return *this;
  char *p = sz <= short_max ? nullptr : str;
  copy_from(s);
  delete[] p;

  return *this;
}

inline string &string::operator=(string &&s) {
  if (this == &s)
    return *this;
  if (sz > short_max)
    delete[] str;
  move_from(s);

  return *this;
}

inline bool string::operator==(const string &s) const {
  return sz == s.sz && strcmp(str, s.str) == 0;
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

inline string &string::operator+=(char c) {
  if (short_max == sz) {
    int n = sz + sz + 2;
    str = expand(str, n);
    space = n - sz - 2;
  } else if (short_max < sz) {
    if (space == 0) {
      int n = sz + sz + 2;
      char *p = expand(str, n);
      delete[] str;
      str = p;
      space = n - sz - 2;
    } else {
      --space;
    }
  }

  str[sz] = c;
  str[++sz] = 0;

  return *this;
}

inline string string::operator+(char c) const {
  string tmp = *this;
  tmp += c;

  return tmp;
}

inline string &string::operator+=(const string &s) {
  for (auto c : s)
    *this += c;
  return *this;
}

inline string string::operator+(const string &s) const {
  string tmp = *this;
  tmp += s;

  return tmp;
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

inline void string::check(int i) const {
  if (i < 0 || i >= size()) {
    throw std::out_of_range("string::at()");
  }
}

inline char *string::expand(const char *str, int n) {
  char *p = new char[n];
  strcpy(p, str);

  return p;
}

inline void string::copy_from(const string &s) {
  if (s.sz <= short_max) {
    memcpy(this, &s, sizeof(s));
    str = ch;
  } else {
    str = expand(s.str, s.sz + 1);
    sz = s.sz;
    space = 0;
  }
}

inline void string::move_from(string &s) {
  if (s.sz <= short_max) {
    memcpy(this, &s, sizeof(s));
    str = ch;
  } else {
    str = s.str;
    sz = s.sz;
    space = s.space;
    s.str = s.ch;
    s.sz = 0;
    s.ch[0] = 0;
  }
}

} // namespace mylib
