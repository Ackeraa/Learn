#include <mymatrix2.h>

using namespace mylib;

template <typename T, size_t N>
template <typename... Exts>
matrix<T, N>::matrix(Exts... exts) : desc{exts...}, elems(desc.size()) {}

template <typename T, size_t N>
matrix<T, N>::matrix(matrix_initializer<T, N> init) {
  derive_extents(init, desc.extents);
  elems.reserve(desc.size);
  insert_flat(init.elems);
  assert(elems.size() == desc.size());
}

template <typename T, size_t N>
template <typename U>
matrix<T, N>::matrix(const matrix_ref<U, N> &x)
    : desc{x.desc}, elems{x.begin(), x.end()} {
  static_assert(convertible<U, T>(),
                "mstrix constructor: incompatible element types");

template<typename T, size_t N>
template<typename U>
matrix<T, N> &matrix<T, N>::operator=(const matrix_ref<U, N> &x) {
  static_assert(convertible<U, T>(),
                "matrix assignment: incompatible element types");
  desc = x.desc;
  elems.assign(x.begin(), x.end());
  return *this;
}


int main() { return 0; }
