#pragma once

namespace mylib {

template <typename... Ts> class tuple;

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

} // namespace mylib
