#include <iostream>
#include <memory>
#include <memory_resource>
#include <list>

using namespace std;

pmr::synchronized_pool_resource pool;

struct Event {
  pmr::vector<int> data = pmr::vector<int>{512, &pool};
};

pmr::list<shared_ptr<Event>> q{&pool};

void producer() {
  for (int i = 0; i < 10000; i++) {
    auto e = make_shared<Event>();
    q.push_back(e);
  }
}

int main() {
  auto t1 = chrono::high_resolution_clock::now();
  producer();
  auto t2 = chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;
}
