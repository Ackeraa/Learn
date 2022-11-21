#include <iostream>
#include <vector>
#include <map>
#include <concepts>

using namespace std;

auto sqrt(double x) -> double {
  return x * x;
}

int main() {
  vector a = {1, 2, 3};

  enum class Color { red, green, blue };
  enum Traffic_light { red, yellow, green };
  
  Color col = Color::red;
  int color = green;

  map<string, int> m;
  m["hello"] = 1;
  m["world"] = 2;

  for (auto &x : a) {
    cout << x << endl;
  }

  for (const auto [key, value] : m) {
    cout << key << " " << value << endl;
  }
  
  cout << "col: " << sqrt(10) << endl;
}
