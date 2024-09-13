#pragma once
#include <SFML/Graphics.hpp>
#include <Primitives.h>
#include <cstdint>

class MandelbrotSetRender {
public:
    explicit MandelbrotSetRender(const Box &start_view_box, const std::uint32_t &width = 800, const std::uint32_t &height = 800);

    void startRender();

private:
    sf::RenderWindow* window = nullptr;
    Box* curr_box = nullptr;
};
