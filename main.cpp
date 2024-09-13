#include <Complex.h>
#include <Primitives.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "MandelbrotSet.h"
#include "Render.h"

Complex firstZ(const Complex &point) {
  return Complex{0, 0};
  // return point;
}

Complex step (const Complex &z, const Complex &point) {
  return z * z + point;
  // return z * z + Complex(0.5, 0.2);
}

bool exitCondition (const Complex &z) {
  return z.abs() >= 2;
  // return z.abs() < 0.3;
}

int main() {
  MandelbrotSetRender mandelbrot_set_render({{-2, -2}, {2, 2}}, firstZ, step, exitCondition, 800, 800);
  mandelbrot_set_render.startRender();

  return 0;
}
