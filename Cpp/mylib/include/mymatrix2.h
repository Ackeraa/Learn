#pragma once
#include <iostream>
#include <vector>
#include <array>

namespace mylib {
template <typename T, size_t N> class matrix {
public:
  static constexpr size_t order = N;
  using value_type = T;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  matrix() = default;
  matrix(matrix &&) = default;
  matrix &operator=(matrix &&) = default;
  matrix(const matrix &) = default;
  matrix &operator=(const matrix &) = default;
  ~matrix() = default;

  // template <typename U> matrix(const matrix_ref<U, N> &);

  // template <typename U> matrix &operator=(const matrix_ref<U, N> &);

  template <typename... Exts> explicit matrix(Exts... exts);

  // matrix(matrix_initializer<T, N>);
  // matrix &operator=(matrix_initializer<T, N>);

  // template <typename U> matrix(initializer_list<U>)=delete;
  // template <typename U> matrix &operator=(initializer_list<U>)=delete;

  // static constexpr size_t order() { return N; }
  size_t extent(size_t n) const { return desc.extents[n]; }
  size_t size() const { return elems.size(); }
  const matrix_slice<N> &descriptor() const { return desc; }

  T *data() { return elems.data(); }
  const T *data() const { return elems.data(); }

private:
  matrix_slice<N> desc;
  vector<T> elems;
};

template <size_t N> struct matrix_slice {
  matrix_slice() = default;

  matrix_slice(size_t s, std::initializer_list<size_t> exts);
  matrix_slice(size_t s, std::initializer_list<size_t> exts,
               std::initializer_list<size_t> strs);

  template<typename... Dims> matrix_slice(Dims... dims);

  template<typename... Dims, typename = std::enable_if<std::all(std::is_convertible<size_t, Dims...)>()>>
    size_t operator()(Dims... dims) const;

  size_t size;
  size_t start;
  std::array<size_t, N> extents;
  std::array<size_t, N> strides;
};

template<typename T, size_t N>
class matrix_ref {
  public:

};

} // namespace mylib
