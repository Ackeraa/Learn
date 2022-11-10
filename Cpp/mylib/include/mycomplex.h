#pragma once
#include <iostream>

namespace mylib {
template <typename T> class complex {
public:
  using value_type = T;

  complex(const T &r = T(), const T &i = T()) : re(r), im(i) {}
  complex(const complex &c) : re{c.re}, im{c.im} {}
  template <typename X>
  complex(const complex<X> &c) : re{c.real()}, im{c.imag()} {}

  T real() const { return re; }
  T imag() const { return im; }
  void real(T r) { re = r; }
  void imag(T i) { im = i; }

  complex &operator=(const T &x);
  complex &operator+=(const T &x);
  complex &operator-=(const T &x);
  complex &operator*=(const T &x);
  complex &operator/=(const T &x);

  template <typename X> complex &operator=(const complex<X> &x);
  template <typename X> complex &operator+=(const complex<X> &x);
  template <typename X> complex &operator-=(const complex<X> &x);
  template <typename X> complex &operator*=(const complex<X> &x);
  template <typename X> complex &operator/=(const complex<X> &x);

  template <typename X>
  friend complex<X> operator+(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend complex<X> operator-(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend complex<X> operator*(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend complex<X> operator/(const complex<X> &x, const complex<X> &y);

  template <typename X>
  friend bool operator==(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend bool operator!=(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend bool operator<(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend bool operator<=(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend bool operator>(const complex<X> &x, const complex<X> &y);
  template <typename X>
  friend bool operator>=(const complex<X> &x, const complex<X> &y);

  // overload operator << for complex
  template <typename X>
  friend std::ostream &operator<<(std::ostream &os, const complex<X> &c);
  template <typename X>
  friend std::istream &operator>>(std::istream &is, complex<X> &c);

private:
  T re, im;
};

template <typename T> inline complex<T> &complex<T>::operator=(const T &x) {
  re = x;
  im = 0;
  return *this;
}

template <typename T> inline complex<T> &complex<T>::operator+=(const T &x) {
  re += x;
  return *this;
}

template <typename T> inline complex<T> &complex<T>::operator-=(const T &x) {
  re -= x;
  return *this;
}

template <typename T> inline complex<T> &complex<T>::operator*=(const T &x) {
  re *= x;
  im *= x;
  return *this;
}

template <typename T> inline complex<T> &complex<T>::operator/=(const T &x) {
  re /= x;
  im /= x;
  return *this;
}

template <typename T>
template <typename X>
inline complex<T> &complex<T>::operator=(const complex<X> &x) {
  re = x.real();
  im = x.imag();
  return *this;
}

template <typename T>
template <typename X>
inline complex<T> &complex<T>::operator+=(const complex<X> &x) {
  re += x.real();
  im += x.imag();
  return *this;
}

template <typename T>
template <typename X>
inline complex<T> &complex<T>::operator-=(const complex<X> &x) {
  re -= x.real();
  im -= x.imag();
  return *this;
}

template <typename T>
template <typename X>
inline complex<T> &complex<T>::operator*=(const complex<X> &x) {
  T tmp = re * x.real() - im * x.imag();
  im = re * x.imag() + im * x.real();
  re = tmp;
  return *this;
}

template <typename T>
template <typename X>
inline complex<T> &complex<T>::operator/=(const complex<X> &x) {
  T tmp = re * x.real() + im * x.imag();
  im = im * x.real() - re * x.imag();
  re = tmp;
  return *this;
}

template <typename X>
inline complex<X> operator+(const complex<X> &x, const complex<X> &y) {
  complex<X> tmp = x;
  return tmp += y;
}

template <typename X>
inline complex<X> operator-(const complex<X> &x, const complex<X> &y) {
  complex<X> tmp = x;
  return tmp -= y;
}

template <typename X>
inline complex<X> operator*(const complex<X> &x, const complex<X> &y) {
  complex<X> tmp = x;
  return tmp *= y;
}

template <typename X>
inline complex<X> operator/(const complex<X> &x, const complex<X> &y) {
  complex<X> tmp = x;
  return tmp /= y;
}

template <typename X>
inline bool operator==(const complex<X> &x, const complex<X> &y) {
  return x.real() == y.real() && x.imag() == y.imag();
}

template <typename X>
inline bool operator!=(const complex<X> &x, const complex<X> &y) {
  return !(x == y);
}

template <typename X>
inline bool operator<(const complex<X> &x, const complex<X> &y) {
  return x.real() < y.real() || (x.real() == y.real() && x.imag() < y.imag());
}

template <typename X>
inline bool operator<=(const complex<X> &x, const complex<X> &y) {
  return !(y < x);
}

template <typename X>
inline bool operator>=(const complex<X> &x, const complex<X> &y) {
  return !(x < y);
}

template <typename X>
inline bool operator>(const complex<X> &x, const complex<X> &y) {
  return y < x;
}

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const complex<T> &c) {
  return os << c.real() << " " << c.imag();
}

template <typename T>
inline std::istream &operator>>(std::istream &is, complex<T> &c) {
  T r, i;
  is >> r >> i;
  c.real(r);
  c.imag(i);
  return is;
}

complex<double> operator"" _i(long double d) {
  return {0, double(d)};
}

} // namespace mylib
