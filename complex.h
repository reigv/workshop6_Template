#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

template <typename T>
class Complex {
private:
    T real_;
    T imag_;

public:
    // Constructors
    Complex();
    Complex(T real, T imag);

    // Complex with Complex
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;

    // Complex with scalar
    Complex operator+(const T& scalar) const;
    Complex operator-(const T& scalar) const;
    Complex operator*(const T& scalar) const;

    // Scalar on left
    friend Complex operator+(const T& scalar, const Complex& z) {
        return Complex(scalar + z.real_, z.imag_);
    }

    friend Complex operator-(const T& scalar, const Complex& z) {
        return Complex(scalar - z.real_, T{} - z.imag_);
    }

    friend Complex operator*(const T& scalar, const Complex& z) {
        return Complex(scalar * z.real_, scalar * z.imag_);
    }

    // Output
    friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
        os << z.real_;

        if (z.imag_ < T{})
            os << " - " << (T{} - z.imag_) << "i";
        else
            os << " + " << z.imag_ << "i";

        return os;
    }
};

#include "complex.cpp"   // VERY IMPORTANT for templates

#endif
