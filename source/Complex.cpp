#include <Complex.h>

Complex operator+(const Complex &first, const Complex &second) {
    return Complex(
        first.real + second.real,
        first.imaginary + second.imaginary
        );
}

Complex operator-(const Complex &first, const Complex &second) {
    return Complex(
        first.real - second.real,
        first.imaginary - second.imaginary
        );
}

Complex operator*(const Complex &first, const Complex &second) {
    return Complex(
        first.real * second.real - first.imaginary * second.imaginary,
        first.real * second.imaginary + first.imaginary * second.real
        );
}

Complex operator*(const Complex &number, const float &coefficient) {
    return Complex(
        number.real * coefficient,
        number.imaginary * coefficient
        );
}

Complex operator*(const float &coefficient, const Complex &number) {
    return Complex(
        number.real * coefficient,
        number.imaginary * coefficient
        );
}


Complex operator-(const Complex &number) {
    return Complex(
        -number.real,
        -number.imaginary
        );
}


std::ostream& operator<<(std::ostream &os, const Complex &number) {
    return os << number.real << (number.imaginary > 0 ? "+" : "-") << (number.imaginary > 0 ? number.imaginary : -number.imaginary) << 'i';
}


float Complex::abs() const {
    return std::sqrt(real * real + imaginary * imaginary);
}