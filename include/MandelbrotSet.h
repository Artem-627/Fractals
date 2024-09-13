#pragma once
#include <atomic>
#include <Complex.h>

class MandelbrotSet {
public:
    static std::int16_t checkPoint(const Complex &point, const std::uint8_t &maxIterations = 10) {
        Complex z(0, 0);
        std::int8_t iterations = 0;

        while (z.abs() < 2) {
            z = z * z + point;
            iterations++;
            if (iterations == maxIterations) {
                return -1;
            }
        }

        return iterations;
    }
};
