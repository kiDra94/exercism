#include "complex_numbers.h"
#include <cmath>
namespace complex_numbers {

Complex Complex::operator+(const Complex& c) const {
  return Complex{a_ + c.real(), b_ + c.imag()};
}
Complex operator+(double d, const Complex& c) {
  return c + d;
}
Complex operator-(double d, const Complex& c) {
  return Complex(d - c.real(), -c.imag());
}

Complex operator*(double d, const Complex& c){
    return c * d;
}

Complex operator/(double d, const Complex& c){
    return c.reciprocal() * d;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    double real_part = lhs.real()* rhs.real() - lhs.imag()*rhs.imag();
    double imag_part = lhs.imag()* rhs.real() + lhs.real()*rhs.imag();
    return Complex(real_part, imag_part);
};

Complex operator-(const Complex& lhs, const Complex& rhs){
    return Complex(lhs.real() - rhs.real(), lhs.imag() - rhs.imag());
}

Complex Complex::conj() const {
    return Complex(a_, -b_);
    }

double Complex::absolute_square() const {
    Complex helper = *this * conj();
    return helper.real();
    }

double Complex::abs() const {
    return std::sqrt(absolute_square());
    }

Complex Complex::reciprocal() const {
    return Complex(a_/absolute_square(), -(b_/absolute_square()));
    };

Complex Complex::exp() const {
    return Complex(std::exp(a_) * std::cos(b_), std::exp(a_) * sin(b_));
    }

Complex operator/(const Complex& lhs, const Complex& rhs){
    Complex helper = lhs * rhs.reciprocal();
    return helper;
}

}  // namespace complex_numbers
