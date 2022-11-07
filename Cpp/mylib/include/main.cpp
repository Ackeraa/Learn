#include "complex.h"
#include <iostream>

using namespace std;
using namespace mylib;

int main() {
  complex<double> c1(2, 2);
  complex<double> c2(3, 4);

  c1 += 2;
  cout << c1 << endl;

  return 0;
}
