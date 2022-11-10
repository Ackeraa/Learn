#include "mymatrix.h"
#include "mystring.h"
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
    int* get() { return p; }
    const int* get() const { return p; }
    virtual void print() const {
      std::cout << "Base: " << *p << std::endl;
    }

};

int main() {
  string s4 = "123123123213123";
  s4 += 'a';

  //std::cout << s4.c_str() << std::endl;

  return 0;
}
