#include "mymatrix.h"
#include <iostream>
#include <string>

using namespace mylib;

void f(std::initializer_list<int> lst) {
  for (int i = 0; i != lst.size(); ++i) {
    std::cout << lst.begin()[i] << std::endl;
  }

  std::cout << std::endl;

  for (auto p = lst.begin(); p != lst.end(); ++p) {
    std::cout << *p << std::endl;
  }

  std::cout << std::endl;

  for (auto x : lst) {
    std::cout << x << std::endl;
  }
}

class Base {
  private:
    int *p;
  public:
    Base() = default;
    Base(int *p) : p{p}{}
    virtual void print() {
      std::cout << "Base: " << *p << std::endl;
    }

};

int main() {
  Base b = Base(new int{10});
  Base b1 = Base(b);

  b.print();

  return 0;
}
