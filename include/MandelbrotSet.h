#pragma once
#include <atomic>
#include <Complex.h>
#include <functional>

class MandelbrotSet {
public:
    static std::int16_t checkPoint(
        const Complex &point,
        const std::uint8_t &maxIterations,
        const std::function<Complex(const Complex &point)> &getFirstZ,
        const std::function<Complex(const Complex &z, const Complex &point)> &function,
        const std::function<bool(const Complex &z)> &exitCondition) {
        Complex z = getFirstZ(point);
        std::int8_t iterations = 0;

        while (!exitCondition(z)) {
            // z = z * z + point;
            z = function(z, point);
            iterations++;
            if (iterations == maxIterations) {
                return -1;
            }
        }

        return iterations;
    }
};
