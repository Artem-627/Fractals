#include <Complex.h>
#include <Primitives.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "MandelbrotSet.h"
#include "Render.h"

int main() {
  MandelbrotSetRender mandelbrot_set_render({{-2, -2}, {2, 2}}, 800, 800);
  mandelbrot_set_render.startRender();

  return 0;
}
