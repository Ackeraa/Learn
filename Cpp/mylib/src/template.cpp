#include <algorithm>
#include <iostream>

using namespace std;

template <typename T, bool (*cmp)(const T &, const T &)> class Array {
public:
  vector<T> data;
  Array() {}
  Array(vector<T> data) : data(data) {}
  void sort() { ::sort(data.begin(), data.end(), cmp); }
};

bool cmp(const int &a, const int &b) { return a > b; }

template <typename T, typename Cmp = std::less<T>> class Array2 {
public:
  vector<T> data;
  Cmp cmp {};

  Array2() {}
  Array2(vector<T> data) : data(data) {}
  Array2(vector<T> data, Cmp cmp) : data{data}, cmp{cmp} {}
  void sort() { ::sort(data.begin(), data.end(), cmp); }
};

template <int N>
struct Fac {
  static const int value = N * Fac<N - 1>::value;
};

template<>
struct Fac<1> {
  static const int value = 1;
};

void printff(const char *s) {
  if (s == nullptr) return;

  while (*s) {
    if (*s == '%' && *++s != '%') {
      throw runtime_error("invalid format string: missing arguments");
    }
    std::cout << *s++;
  }
}

template <typename T, typename...Args>
void printff(const char *s, T value, Args...args) {
  while (s && *s) {
    if (*s == '%' && *++s != '%') {
      std::cout << value;
      return printff(++s, args...);
    }
    std::cout << *s++;
  }
  throw runtime_error("extra arguments provided to printf");
}

int main() {

  vector<int> data = {1, 2, 3, 4, 5};
  Array<int, cmp> a{data};
  a.sort();

  Array2<int> a2{data};
  Array2<int, std::greater<int>> a3{data};

  using Cmp = bool(*)(const int&, const int&);
  Array2<int, Cmp> a4{data, cmp};

  auto cmp = [](const int &a, const int &b) { return a > b; };
  Array2<int, decltype(cmp)> a5{data, cmp};


  a2.sort();
  a3.sort();
  a4.sort();

  constexpr int n = Fac<5>::value;
  cout << n << endl;

  printff("hello %s", "world");

  return 0;
}
