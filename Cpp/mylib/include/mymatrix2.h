#pragma once
#include <array>
#include <iostream>
#include <vector>

namespace mylib {

template <typename T, size_t N> class matrix_base;
template <typename T, size_t N> struct matrix_init;
template <size_t N> struct matrix_slice;
template <typename T, size_t N> class matrix_ref;
template <typename T, size_t N>
using matrix_initializer = typename matrix_init<T, N>::type;

template <typename T, size_t N> class matrix {
public:
  static constexpr size_t m_order = N;
  using value_type = T;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  matrix() = default;
  matrix(matrix &&) = default;
  matrix &operator=(matrix &&) = default;
  matrix(const matrix &) = default;
  matrix &operator=(const matrix &) = default;
  ~matrix() = default;

  template <typename U> matrix(const matrix_ref<U, N> &);

  template <typename U> matrix &operator=(const matrix_ref<U, N> &);

  template <typename... Exts> explicit matrix(Exts... exts);

  matrix(matrix_initializer<T, N>);
  matrix &operator=(matrix_initializer<T, N>);

  template <typename U> matrix(std::initializer_list<U>)=delete;
  template <typename U> matrix &operator=(std::initializer_list<U>)=delete;

  static constexpr size_t order() { return N; }
  size_t extent(size_t n) const { return desc.extents[n]; }
  size_t size() const { return elems.size(); }
  const matrix_slice<N> &descriptor() const { return desc; }

  T *data() { return elems.data(); }
  const T *data() const { return elems.data(); }

private:
  matrix_slice<N> desc;
  std::vector<T> elems;
};

template <typename T, size_t N> class matrix_base {};

template <size_t N> struct matrix_slice {
  matrix_slice() = default;

  matrix_slice(size_t s, std::initializer_list<size_t> exts);
  matrix_slice(size_t s, std::initializer_list<size_t> exts,
               std::initializer_list<size_t> strs);

  template <typename... Dims> matrix_slice(Dims... dims);

  template <typename... Dims>
  // typename =
  // std::enable_if<std::is_convertible<size_t, Dims...>> size_t
  size_t operator()(Dims... dims) const;

  size_t size;
  size_t start;
  std::array<size_t, N> extents;
  std::array<size_t, N> strides;
};

template <typename T, size_t N> class matrix_ref {
public:
  matrix_ref(const matrix_slice<N> &s, T *p) : desc{s}, ptr{p} {}

private:
  matrix_slice<N> desc;
  T *ptr;
};

template <typename T, size_t N> struct matrix_init {
  using type = std::initializer_list<typename matrix_init<T, N - 1>::type>;
};

template <typename T> struct matrix_init<T, 1> {
  using type = std::initializer_list<T>;
};

template <typename T> struct matrix_init<T, 0>; // undefined on purpose

} // namespace mylib
