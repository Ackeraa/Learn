#pragma once
#include <array>
#include <iostream>
#include <memory>

namespace mylib {

template <typename T> class vector;

template <class T> class matrix {
public:
  matrix(int d1, int d2) : dim{d1, d2}, elem{new T[d1 * d2]} {}
  matrix(const matrix &m);
  matrix(matrix &&m);
  matrix(std::initializer_list<std::initializer_list<T>> lst);
  matrix &operator=(const matrix &m);
  matrix &operator=(matrix &&m);
  ~matrix() { delete[] elem; }

  int size() const { return dim[0] * dim[1]; }
  int rows() const { return dim[0]; }
  int cols() const { return dim[1]; }

  T &operator()(int i, int j) { return elem[i * dim[1] + j]; }
  const T operator()(int i, int j) const { return elem[i * dim[1] + j]; }
  matrix &operator+=(const matrix &m);
  matrix &operator-=(const matrix &m);
  matrix &operator*=(const matrix &m);
  matrix &operator*=(const T &v);
  matrix &operator/=(const T &v);

  template <class X>
  friend matrix<X> operator+(const matrix<X> &a, const matrix<X> &b);

  template <class X>
  friend matrix<X> operator-(const matrix<X> &a, const matrix<X> &b);

  template <class X>
  friend matrix<X> operator*(const matrix<X> &a, const matrix<X> &b);

  template <class X>
  friend matrix<X> operator*(const matrix<X> &m, const X &v);

  template <class X>
  friend matrix<X> operator*(const X &v, const matrix<X> &m);

  template <class X>
  friend matrix<X> operator/(const matrix<X> &m, const X &v);

  template <class X>
  friend vector<X> operator*(const matrix<X> &m, const vector<X> &v);

private:
  std::array<int, 2> dim;
  T *elem;
};

template <class T>
inline matrix<T>::matrix(const matrix &m) : dim{m.dim}, elem{new T[m.size()]} {
  std::cout << "copy constructor" << std::endl;
  std::uninitialized_copy(m.elem, m.elem + m.size(), elem);
}

template <class T>
inline matrix<T>::matrix(matrix &&m) : dim{m.dim}, elem{m.elem} {
  m.dim = {0, 0};
  m.elem = nullptr;
}

template <class T> inline matrix<T> &matrix<T>::operator=(const matrix &m) {
  std::cout << "copy assignment" << std::endl;
  matrix<T> tmp{m};
  std::swap(tmp, *this);

  return *this;
}

template <class T> inline matrix<T> &matrix<T>::operator=(matrix &&m) {
  std::swap(dim, m.dim);
  std::swap(elem, m.elem);

  return *this;
}

template <class T>
matrix<T>::matrix(std::initializer_list<std::initializer_list<T>> lst)
    : dim{static_cast<int>(lst.size()), static_cast<int>(lst.begin()->size())},
      elem{new T[dim[0] * dim[1]]} {
  int i = 0;
  for (auto &row : lst) {
    std::uninitialized_copy(row.begin(), row.end(), elem + i * dim[1]);
    ++i;
  }
}

template <class T> matrix<T> operator+(const matrix<T> &a, const matrix<T> &b) {
  if (a.dim != b.dim) {
    throw std::runtime_error("matrix dimensions do not match");
  }
  matrix<T> res{a.dim[0], a.dim[1]};
  const int n = a.size();
  for (int i = 0; i < n; ++i) {
    res.elem[i] = a.elem[i] + b.elem[i];
  }

  return res;
}

template <typename T>
vector<T> operator*(const matrix<T> &m, const vector<T> &v) {
  if (m.dim[1] != v.size()) {
    throw std::runtime_error("matrix and vector dimensions do not match");
  }
  vector<T> res(m.dim[0]);
  for (int i = 0; i < m.dim[0]; ++i) {
    for (int j = 0; j < m.dim[1]; ++j) {
      res[i] += m(i, j) * v[j];
    }
  }

  return res;
}


} // namespace mylib
