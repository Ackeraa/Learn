#include <functional>
#include <iostream>
#include <memory>

using namespace std;

int f1(int a, int b) {
  return a + b;
}
function<int(int, int)> fct1 {f1};
function fct2 = [](int a, int b) { return a + b; };

template <typename T>
concept Arithmetic = is_arithmetic_v<T>;

template <typename T>
concept Class = is_class_v<T> || is_union_v<T>;

template <typename T>
class Smart_pointer {
  T &operator*() const;
  T *operator->() const requires Class<T>;
  // enable_if<is_class_v<T>, T&> operator->() const;
};

template <typename T, typename ... Args>
unique_ptr<T> make_unique(Args &&... args) {
  return unique_ptr<T>(new T(forward<Args>(args)...));
}

int main() {
  cout << fct1(1, 2) << endl;
  cout << fct2(1, 2) << endl;

  double val = 7.2;
  auto x = bit_cast<uint64_t>(val);
  auto y = bit_cast<uint64_t>(&val);

}
