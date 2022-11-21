#include <concepts>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;
using namespace std::ranges;

template <typename T, typename U = T>
concept Number = requires(T x, U y) {
                   x + y;
                   x - y;
                   x *y;
                   x / y;
                   x += y;
                   x -= y;
                   x *= y;
                   x /= y;
                   x = x;
                   x = 0;
                 };

template <typename T, typename U = T>
concept Arithmetic = Number<T, U> && Number<U, T>;

template <typename S>
concept Sequence = requires(S a) {
                     typename range_value_t<S>;
                     typename iterator_t<S>;

                     { a.begin() } -> same_as<iterator_t<S>>;
                     { a.end() } -> same_as<iterator_t<S>>;

                     requires input_iterator<iterator_t<S>>;
                     requires same_as<range_value_t<S>, iter_value_t<S>>;
                   };

/*
template <typename S>
concept Sequence = input_range<S>;
*/

template <Sequence Seq, Number Num>
  requires Arithmetic<range_value_t<Seq>, Num>
Num sum(Seq seq, Num init) {
  for (auto x : seq) {
    init += x;
  }
  return init;
}

template <forward_iterator Iter, Arithmetic<iter_value_t<Iter>> Val>
Val accumulate(Iter first, Iter last, Val res) {
  for (auto p = first; p != last; ++p)
    res += *p;

  return res;
}

template <typename T>
concept Printable = requires(T t) { cout << t; };

template <Printable T, Printable... Ts> void print(T head, Ts... tail) {
  cout << head << ' ';
  if constexpr (sizeof...(tail) > 0)
    print(tail...);
}

template <Number... T> int sumr(T... t) { return (t + ... + 0); }

template <Number... T> int suml(T... t) { return (0 + ... + t); }

int main() {

  vector<int> a = {1, 2, 3};

  auto b = accumulate(a.begin(), a.end(), 0);

  cout << b << endl;

  cout << sum(a, 0) << endl;

  print(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  cout << endl;

  cout << sumr(1, 2, 3) << endl;
  cout << suml(1, 2, 3) << endl;

  return 0;
}
