#pragma once
#include <vector>
#include <SFML/Graphics/Color.hpp>

struct Point {
    float x;
    float y;
};

struct Box {
    Point min;
    Point max;
};

namespace Colors {
    const std::vector<sf::Color> gradient = {
        sf::Color(0, 0, 0),    // Black
        sf::Color(66, 30, 15),    // Brown
        sf::Color(25, 7, 26),     // Dark Purple
        sf::Color(9, 1, 47),      // Dark Blue
        sf::Color(4, 4, 73),      // Blue
        sf::Color(0, 7, 100),     // Light Blue
        sf::Color(12, 44, 138),   // Light Blue
        sf::Color(24, 82, 177),   // Light Blue
        sf::Color(57, 125, 209),  // Light Blue
        sf::Color(134, 181, 229), // Light Blue
        sf::Color(211, 236, 248), // Light Blue
        sf::Color(241, 233, 191), // Light Yellow
        sf::Color(248, 201, 95),  // Yellow
        sf::Color(255, 170, 0),   // Orange
        sf::Color(204, 128, 0),   // Dark Orange
        sf::Color(153, 87, 0),    // Brown
        sf::Color(106, 52, 3),    // Dark Brown
        sf::Color(66, 30, 15),    // Brown
        sf::Color(25, 7, 26),     // Dark Purple
        sf::Color(9, 1, 47),      // Dark Blue
        sf::Color(4, 4, 73),      // Blue
        sf::Color(0, 7, 100),     // Light Blue
        sf::Color(12, 44, 138),   // Light Blue
        sf::Color(24, 82, 177),   // Light Blue
        sf::Color(57, 125, 209),  // Light Blue
        sf::Color(134, 181, 229), // Light Blue
        sf::Color(211, 236, 248), // Light Blue
        sf::Color(241, 233, 191), // Light Yellow
        sf::Color(248, 201, 95),  // Yellow
        sf::Color(255, 170, 0),   // Orange
        sf::Color(204, 128, 0),   // Dark Orange
        sf::Color(153, 87, 0),    // Brown
        sf::Color(106, 52, 3),    // Dark Brown
        sf::Color(66, 30, 15),     // Brown
        sf::Color(66, 30, 15),    // Brown
        sf::Color(25, 7, 26),     // Dark Purple
        sf::Color(9, 1, 47),      // Dark Blue
        sf::Color(4, 4, 73),      // Blue
        sf::Color(0, 7, 100),     // Light Blue
        sf::Color(12, 44, 138),   // Light Blue
        sf::Color(24, 82, 177),   // Light Blue
        sf::Color(57, 125, 209),  // Light Blue
        sf::Color(134, 181, 229), // Light Blue
        sf::Color(211, 236, 248), // Light Blue
        sf::Color(241, 233, 191), // Light Yellow
        sf::Color(248, 201, 95),  // Yellow
        sf::Color(255, 170, 0),   // Orange
        sf::Color(204, 128, 0),   // Dark Orange
        sf::Color(153, 87, 0),    // Brown
        sf::Color(106, 52, 3),    // Dark Brown
        sf::Color(66, 30, 15),    // Brown
        sf::Color(25, 7, 26),     // Dark Purple
        sf::Color(9, 1, 47),      // Dark Blue
        sf::Color(4, 4, 73),      // Blue
        sf::Color(0, 7, 100),     // Light Blue
        sf::Color(12, 44, 138),   // Light Blue
        sf::Color(24, 82, 177),   // Light Blue
        sf::Color(57, 125, 209),  // Light Blue
        sf::Color(134, 181, 229), // Light Blue
        sf::Color(211, 236, 248), // Light Blue
        sf::Color(241, 233, 191), // Light Yellow
        sf::Color(248, 201, 95),  // Yellow
        sf::Color(255, 170, 0),   // Orange
        sf::Color(204, 128, 0),   // Dark Orange
        sf::Color(153, 87, 0),    // Brown
        sf::Color(106, 52, 3),    // Dark Brown
        sf::Color(66, 30, 15)     // Brown
    };
}
