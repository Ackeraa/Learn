#include <iostream>
#pragma once

namespace mylib {

template <typename T> class vector {
public:
  vector() : sz(0), elem(nullptr) {}
  explicit vector(size_t s, const T &v = T());
  vector(const vector &v);
  vector(std::initializer_list<T> lst);
  vector &operator=(const vector &v);

  T &operator[](size_t i) { return elem[i]; }
  size_t size() const { return sz; }

private:
  size_t sz;
  T *elem;
};

template <typename T>
inline vector<T>::vector(size_t s, const T &v) : sz(s), elem(new T[s]) {
  for (int i = 0; i < s; ++i) {
    elem[i] = v;
  }
}

template <typename T>
inline vector<T>::vector(const vector<T> &v) : sz(v.sz), elem(new T[v.sz]) {
  std::copy(v.elem, v.elem + v.sz, elem);
}

template <typename T>
inline vector<T>::vector(std::initializer_list<T> lst)
    : sz(lst.size()), elem(new T[sz]) {
  std::copy(lst.begin(), lst.end(), elem);
}

template <typename T>
inline vector<T> &vector<T>::operator=(const vector<T> &v) {
  if (this == &v) {
    return *this;
  }
  delete[] elem;
  sz = v.sz;
  elem = new T[sz];
  std::copy(v.elem, v.elem + sz, elem);

  return *this;
}


} // namespace mylib
