#pragma once
#include <array>
#include <memory>

namespace mylib {
template <typename T> class matrix {
public:
  matrix(int d1, int d2) : dim{d1, d2}, elem{new T[d1 * d2]} {}
  matrix(const matrix &m);
  matrix &operator=(const matrix &m);
  matrix(matrix &&m);
  matrix &operator=(matrix &&m);
  matrix(std::initializer_list<std::initializer_list<T>> lst);
  ~matrix() { delete[] elem; }

  int size() const { return dim[0] * dim[1]; }
  T &operator()(int i, int j) { return elem[i * dim[1] + j]; }
  int rows() const { return dim[0]; }
  int cols() const { return dim[1]; }

private:
  std::array<int, 2> dim;
  T *elem;
};

template <typename T>
inline matrix<T>::matrix(const matrix<T> &m)
    : dim{m.dim}, elem{new T[m.size()]} {
  std::uninitialized_copy(m.elem, m.elem + m.size(), elem);
}

template <typename T>
inline matrix<T> &matrix<T>::operator=(const matrix<T> &m) {
  matrix<T> tmp{m};
  std::swap(tmp, *this);

  return *this;
}

template <typename T>
matrix<T>::matrix(std::initializer_list<std::initializer_list<T>> lst)
    : dim{static_cast<int>(lst.size()), static_cast<int>(lst.begin()->size())},
      elem{new T[dim[0] * dim[1]]} {
  int i = 0;
  for (auto &row : lst) {
    std::uninitialized_copy(row.begin(), row.end(), elem + i * dim[1]);
    ++i;
  }
}

} // namespace mylib
