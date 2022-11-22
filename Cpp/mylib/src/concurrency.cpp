#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <shared_mutex>

using namespace std;

mutex mtx;
int sh;

void f(int x){
  scoped_lock lock(mtx);
  sh += x;
};

struct F {
  F(int x) : x(x) {}
  void operator()(){
    cout << "Parrallel World" << endl;
  };
  int x;
};

void user() {
  thread t2 {F(1)}; // F()() executes in separate thread
  jthread t3 {f, 2}; // f() executes in separate thread

  t2.join(); // wait for t2 to finish
}

shared_mutex mx;

void reader() {
  shared_lock lock(mx);
  // read shared data
}

void writer() {
  unique_lock lock(mx);
  // modify shared data
}

auto main() -> int {
  user();
  cout << "Done!" << endl;

  return 0;
}
