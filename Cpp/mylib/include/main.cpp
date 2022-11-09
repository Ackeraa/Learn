#include <iostream>
#include <string>

using namespace std;

void f(std::initializer_list<int> lst) {
  for (int i = 0; i != lst.size(); ++i) {
    cout << lst.begin()[i] << endl;
  }

  cout << endl;

  for (auto p = lst.begin(); p != lst.end(); ++p) {
    cout << *p << endl;
  }

  cout << endl;

  for (auto x : lst) {
    cout << x << endl;
  }
}

int main() {
  f({1, 2, 3, 4, 5});

  return 0;
}
