#pragma once
#include <iostream>

namespace mylib {
template <typename Scalar> class complex {
public:
  using value_type = Scalar;

  complex() : re{0}, im{0} {}
  template <typename T>
  complex(const T &r, const T &i = 0) : re{r}, im{i} {}
  complex(const complex &c) = default;
  template <typename T>
  complex(const complex<T> &c) : re{c.real()}, im{c.imag()} {}

  Scalar real() const { return re; }
  Scalar imag() const { return im; }
  template <typename T> void real(T r) { re = r; }
  template <typename T> void imag(T i) { im = i; }

  template <typename T> complex &operator=(const T &x);
  template <typename T> complex &operator+=(const T &x);
  template <typename T> complex &operator-=(const T &x);
  template <typename T> complex &operator*=(const T &x);
  template <typename T> complex &operator/=(const T &x);

  template <typename T> complex &operator=(const complex<T> &x);
  template <typename T> complex &operator+=(const complex<T> &x);
  template <typename T> complex &operator-=(const complex<T> &x);
  template <typename T> complex &operator*=(const complex<T> &x);
  template <typename T> complex &operator/=(const complex<T> &x);

  template <typename T>
  friend complex<T> operator+(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend complex<T> operator-(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend complex<T> operator*(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend complex<T> operator/(const complex<T> &x, const complex<T> &y);

  template <typename T>
  friend bool operator==(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend bool operator!=(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend bool operator<(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend bool operator<=(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend bool operator>(const complex<T> &x, const complex<T> &y);
  template <typename T>
  friend bool operator>=(const complex<T> &x, const complex<T> &y);

  // overload operator << for complex
  template <typename T>
  friend std::ostream &operator<<(std::ostream &os, const complex<T> &c);
  template <typename T>
  friend std::istream &operator>>(std::istream &is, complex<T> &c);

private:
  Scalar re, im;
};

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator=(const T &x) {
  re = x;
  im = 0;
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator+=(const T &x) {
  re += x;
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator-=(const T &x) {
  re -= x;
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator*=(const T &x) {
  re *= x;
  im *= x;
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator/=(const T &x) {
  re /= x;
  im /= x;
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator=(const complex<T> &x) {
  re = x.real();
  im = x.imag();
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator+=(const complex<T> &x) {
  re += x.real();
  im += x.imag();
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator-=(const complex<T> &x) {
  re -= x.real();
  im -= x.imag();
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator*=(const complex<T> &x) {
  Scalar tmp = re * x.real() - im * x.imag();
  im = re * x.imag() + im * x.real();
  re = tmp;
  return *this;
}

template <typename Scalar>
template <typename T>
inline complex<Scalar> &complex<Scalar>::operator/=(const complex<T> &x) {
  Scalar tmp = re * x.real() + im * x.imag();
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

inline complex<double> operator"" _i(long double d) { return {0.0, double(d)}; }

} // namespace mylib
