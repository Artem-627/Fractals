#pragma once

#include <iostream>
#include <valarray>

class Complex {
public:
    float real;
    float imaginary;

    [[nodiscard]]
    float abs() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }


    friend Complex operator+(const Complex &first, const Complex &second);
    friend Complex operator-(const Complex &first, const Complex &second);
    friend Complex operator*(const Complex &first, const Complex &second);
    friend Complex operator*(const Complex &number, const float &coefficient);
    friend Complex operator*(const float &coefficient, const Complex &number);

    friend Complex operator-(const Complex &number);

    friend std::ostream& operator<<(std::ostream &os, const Complex &number);
};
