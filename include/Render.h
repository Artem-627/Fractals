#pragma once
#include <SFML/Graphics.hpp>
#include <Primitives.h>
#include <Complex.h>
#include <cstdint>
#include <stack>
#include <functional>

class MandelbrotSetRender {
public:
    explicit MandelbrotSetRender(
        const Box &start_view_box,
        const std::function<Complex(const Complex &point)> &getFirstZ_,
        const std::function<Complex(const Complex &z, const Complex &point)> &function_,
        const std::function<bool(const Complex &z)> &exitCondition_,
        const std::uint32_t &width = 800,
        const std::uint32_t &height = 800
        );

    void startRender();

private:
    sf::RenderWindow* window = nullptr;
    std::function<Complex(const Complex &point)> getFirstZ;
    std::function<Complex(const Complex &z, const Complex &point)> function;
    std::function<bool(const Complex &z)> exitCondition;
    std::stack<Box> curr_box;
};
