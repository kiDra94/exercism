#pragma once
#include <cmath>

namespace complex_numbers {

class Complex {
public:
    Complex() = default;
    Complex(double a, double b) : a_{a}, b_{b} {};
    double real() const {return a_;};
    double imag() const {return b_;};
    Complex operator+(const Complex& c) const;
    Complex operator+(double d) const { return Complex{a_ + d, b_}; }
    Complex operator-(double d) const { return Complex{a_ - d, b_}; }
    Complex operator*(double d) const { return Complex{a_ * d, d * b_}; }
    Complex operator/(double d) const { return Complex{a_ / d, b_ / d}; }
    Complex conj() const;
    double absolute_square() const;
    Complex reciprocal() const;
    double abs() const;
    Complex exp() const;
private:
    double a_ {0.0};
    double b_ {0.0};
};
Complex operator+(double d, const Complex& c);
Complex operator-(double d, const Complex& c);
Complex operator*(double d, const Complex& c);
Complex operator/(double d, const Complex& c);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

}  // namespace complex_numbers
