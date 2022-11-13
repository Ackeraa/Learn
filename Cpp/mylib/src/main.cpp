#include <mymatrix.h>
#include <mystring.h>
#include <myvector.h>
#include <iostream>

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
  public:
    int b;
    Base() : b(0) {}
    explicit Base(int b) : b(b) {}

    virtual void print() const {
      std::cout << "b=" << b << std::endl;
    }
};

class Derived : public Base {
  public:
    int d;
    Derived(int d) : d{d} {}

    void print() const override {
      Base::print();
      std::cout << "d=" << d << std::endl;
    }
};

class Test {
  public:
    int *p;
    int x, y;
    Test(int x, int y) : x{x}, y{y} {}
    Test(const Test& t) : x{t.x}, y{t.y} {}
};

void print(const Base& b) {
  b.print();
}

int main() {
  vector<int> v{1, 2, 3};
  matrix<int> m1{{1, 2, 3}, {4, 5, 6}};

  vector<int> m1v = m1 * v;

  std::cout << m1v.size() << std::endl;

  for (int i = 0; i != m1v.size(); ++i) {
    std::cout << m1v[i] << std::endl;
  }

  //std::cout << s4.c_str() << std::endl;

  return 0;
}
