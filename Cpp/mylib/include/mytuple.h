#pragma once

namespace mylib {

template <typename... Ts> class tuple;

template <> class tuple<> { tuple(){} };

template <typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
  typedef tuple<Tail...> inherited;

public:
  constexpr tuple() {}
  tuple(const Head &head, const Tail &...tail)
      : inherited(tail...), m_head(head) {}

  template <typename... VValues>
  tuple(const tuple<VValues...> &other)
      : inherited(other.tail()), m_head(other.head()) {}

  template <typename... VValues>
  tuple &operator=(const tuple<VValues...> &other) {
    m_head = other.head();
    tail() = other.tail();
    return *this;
  }

protected:
  Head m_head;

private:
  Head &head() { return head; }
  const Head &head() const { return head; }

  inherited &tail() { return *this; }
  const inherited &tail() const { return *this; }
};

template <typename Ret, int N>
struct getNth {
  template <typename... Ts>
  static Ret &get(tuple<Ts...> &t) {
    return getNth<Ret, N - 1>::get(t.tail());
  }

  template <typename... Ts>
  static const Ret &get(const tuple<Ts...> &t) {
    return getNth<Ret, N - 1>::get(t.tail());
  }
};

template <typename Ret>
struct getNth<Ret, 0> {
  template <typename... Ts>
  static Ret &get(tuple<Ts...> &t) {
    return t.head();
  }

  template <typename... Ts>
  static const Ret &get(const tuple<Ts...> &t) {
    return t.head();
  }
};

} // namespace mylib
