#pragma once
#include <iostream>

namespace mylib {

template <typename T> class matrix;

template <typename T> class vector {
public:
  vector() : sz(0), elem(nullptr) {}
  explicit vector(size_t s, const T &v = T());
  vector(const vector &v);
  vector(std::initializer_list<T> lst);
  vector &operator=(const vector &v);

  ~vector() { delete[] elem; }

  T &operator[](size_t i) { return elem[i]; }
  const T &operator[](size_t i) const { return elem[i]; }

  size_t size() const { return sz; }

  bool operator==(const vector &v) const;

  vector &operator+=(const vector &v);
  vector &operator-=(const vector &v);

  template <class X>
  friend vector<X> operator+(const vector<X> &a, const vector<X> &b);

  template <class X>
  friend vector<X> operator-(const vector<X> &a, const vector<X> &b);

  template <class X>
  friend vector<X> operator*(const matrix<X> &m, const vector<X> &v);

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
inline vector<T>::vector(const vector &v) : sz(v.sz), elem(new T[v.sz]) {
  std::copy(v.elem, v.elem + v.sz, elem);
}

template <typename T>
inline vector<T>::vector(std::initializer_list<T> lst)
    : sz(lst.size()), elem(new T[sz]) {
  std::copy(lst.begin(), lst.end(), elem);
}

template <typename T>
inline bool vector<T>::operator==(const vector &v) const {
  if (sz != v.sz) {
    return false;
  }
  for (int i = 0; i < sz; ++i) {
    if (elem[i] != v.elem[i]) {
      return false;
    }
  }
  return true;
}

template <typename T> inline vector<T> &vector<T>::operator=(const vector &v) {
  if (this == &v) {
    return *this;
  }
  delete[] elem;
  sz = v.sz;
  elem = new T[sz];
  std::copy(v.elem, v.elem + sz, elem);

  return *this;
}

template <typename T> inline vector<T> &vector<T>::operator+=(const vector &v) {
  for (int i = 0; i < sz; ++i) {
    elem[i] += v.elem[i];
  }

  return *this;
}

template <typename T> inline vector<T> &vector<T>::operator-=(const vector &v) {
  for (int i = 0; i < sz; ++i) {
    elem[i] -= v.elem[i];
  }

  return *this;
}

template <typename T>
inline vector<T> operator+(const vector<T> &a, const vector<T> &b) {
  vector<T> tmp{a};
  tmp += b;

  return tmp;
}

template <typename T>
inline vector<T> operator-(const vector<T> &a, const vector<T> &b) {
  vector<T> tmp{a};
  tmp -= b;

  return tmp;
}

} // namespace mylib
