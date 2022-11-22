#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <span>

using namespace std;
using namespace std::ranges;

template <ranges::forward_range R>
  requires sortable<ranges::iterator_t<R>>
void my_sort(R &r) {
  return std::sort(r.begin(), r.end());
}

void user(ranges::forward_range auto &r) {
  filter_view fv{r, [](auto x) { return x % 2 == 0; }};

  for (auto i :
       fv | views::filter([](auto x) { return x % 3 == 0; }) | views::take(3)) {
    cout << i << endl;
  }
}

template <class Iter>
class Sentinel {
  public:
    Sentinel(int ee) : end(ee) {}
    Sentinel() : end(0) {}

    friend bool operator==(const Iter &i, const Sentinel &s) {
      return (*i) == s.end;
    }
    friend bool operator!=(const Iter &i, const Sentinel &s) {
      return !(i == s);
    }
  private:
    iter_value_t<Iter> end;
};

void fs(span<int> p) {
  for (auto i : p) {
    cout << i << endl;
  }
}

int sum(optional<int> a, optional<int> b) {
  int res = 0;
  if (a) res += *a;
  if (b) res += *b;
  return res;
}

int main() {
  // create a vector of size 100, with random values
  auto v = iota_view{0, 100};
  user(v);

  const char aa[] = "Hello, world!\nBye for now!\n";

  ranges::for_each(aa, Sentinel<const char *>('\n'), [](const char x) { cout << x; });

  int a[100] = {};
  //fs({a, 100});
  int x = sum(17, {});
  cout << x << endl;

}
