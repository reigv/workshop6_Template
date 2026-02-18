#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

template <typename T>
class Complex {
private:
    T real_;
    T imag_;

public:
    // 1) Default constructor: 0 + 0i (value-initialization)
    Complex() : real_(T{}), imag_(T{}) {}

    // 2) Overloaded constructor
    Complex(T real, T imag) : real_(real), imag_(imag) {}

    // (Optional) getters (not required, but useful)
    T real() const { return real_; }
    T imag() const { return imag_; }

    // 3) Complex with Complex
    Complex operator+(const Complex& other) const {
        return Complex(real_ + other.real_, imag_ + other.imag_);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real_ - other.real_, imag_ - other.imag_);
    }

    Complex operator*(const Complex& other) const {
        // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        return Complex(real_ * other.real_ - imag_ * other.imag_,
                       real_ * other.imag_ + imag_ * other.real_);
    }

    // 4) Complex with scalar T (member handles: Complex op T)
    Complex operator+(const T& scalar) const {
        return Complex(real_ + scalar, imag_);
    }

    Complex operator-(const T& scalar) const {
        return Complex(real_ - scalar, imag_);
    }

    Complex operator*(const T& scalar) const {
        return Complex(real_ * scalar, imag_ * scalar);
    }

    // 4) scalar on the left (T op Complex) -> friend/non-member
    friend Complex operator+(const T& scalar, const Complex& z) {
        return Complex(scalar + z.real_, z.imag_);
    }

    friend Complex operator-(const T& scalar, const Complex& z) {
        // scalar - (a + bi) = (scalar - a) + (0 - b)i
        return Complex(scalar - z.real_, T{} - z.imag_);
    }

    friend Complex operator*(const T& scalar, const Complex& z) {
        return Complex(scalar * z.real_, scalar * z.imag_);
    }

    // 5) Output
    friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
        os << z.real_;

        if (z.imag_ < T{}) {
            os << " - " << (T{} - z.imag_) << "i";
        } else {
            os << " + " << z.imag_ << "i";
        }

        return os;
    }
};

#endif
