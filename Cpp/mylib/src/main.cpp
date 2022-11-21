#include <iostream>
#include <vector>
#include <map>
#include <concepts>
#include <filesystem>

using namespace std;

auto sqrt(double x) -> double {
  return x * x;
}

// print names of all files in directory dir
void print_files(filesystem::path dir) {
  try {
    for (auto& p : filesystem::directory_iterator(dir)) {
      cout << p.path() << '\n';
    }
  }
  catch (filesystem::filesystem_error& e) {
    cerr << e.what() << '\n';
  }
}

int main() {
  // regular expressio to match a C++ identifier
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

  print_files(".");

}
