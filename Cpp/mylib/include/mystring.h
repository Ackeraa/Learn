#pragma once
namespace mylib {
class string {
public:
  string(const char *s = "") : str(s) {}

private:
  const char *str;
};
} // namespace mylib
