#include <Complex.h>
#include <iostream>

int main() {
  constexpr Complex a(1, 1);
  constexpr Complex b(3, 5);

  std::cout << a + b << '\n';
  std::cout << a - b << '\n';
  std::cout << a * b << '\n';
  std::cout << a * 3 << '\n';
  std::cout << a.abs() << '\n';

  return 0;
}