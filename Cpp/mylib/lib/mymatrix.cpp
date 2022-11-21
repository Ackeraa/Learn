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
  //static_assert(convertible<U, T>(),
   //             "mstrix constructor: incompatible element types");

  template <typename T, size_t N>
  template <typename U>
  matrix<T, N> &matrix<T, N>::operator=(const matrix_ref<U, N> &x) {
    //static_assert(convertible<U, T>(),
    //              "matrix assignment: incompatible element types");
    desc = x.desc;
    elems.assign(x.begin(), x.end());
    return *this;
  }
}

template <size_t N, typename l, typename List>
std::enable_if<(N > 1), void> add_extents(l &first, const List &list) {
  assert(check_non_jagged(list));
  *first = list.size();
  add_extents<N - 1>(++first, list.begin()->elems);
}

template <size_t N, typename l, typename List>
std::enable_if<(N == 1), void> add_extents(l &first, const List &list) {
  *first++ = list.size();
}

template <typename List> bool check_non_jagged(const List &list) {
  auto i = list.begin();
  for (auto j = i + 1; j != list.end(); ++j)
    if (i->size() != j->size())
      return false;
  return true;
}

template <typename T, typename Vec>
void add_list(const std::initializer_list<T> *first, const std::initializer_list<T> *last,
              Vec &v) {
  for (; first != last; ++first)
    add_list(first->begin(), first->end(), v);
}

template <typename T, typename Vec>
void insert_flat(std::initializer_list<T> list, Vec &vec) {
  add_list(list.begin(), list.end(), vec);
}

template <size_t N, typename List>
std::array<size_t, N> derive_extents(const List &list) {
  std::array<size_t, N> a;
  auto f = a.begin();
  add_extents<N>(f, list);
  return a;
}
