#ifndef COMPLEX_CPP
#define COMPLEX_CPP

template <typename T>
Complex<T>::Complex() : real_(T{}), imag_(T{}) {}

template <typename T>
Complex<T>::Complex(T real, T imag)
    : real_(real), imag_(imag) {}

template <typename T>
Complex<T> Complex<T>::operator+(const Complex& other) const {
    return Complex(real_ + other.real_, imag_ + other.imag_);
}

template <typename T>
Complex<T> Complex<T>::operator-(const Complex& other) const {
    return Complex(real_ - other.real_, imag_ - other.imag_);
}

template <typename T>
Complex<T> Complex<T>::operator*(const Complex& other) const {
    return Complex(real_ * other.real_ - imag_ * other.imag_,
                   real_ * other.imag_ + imag_ * other.real_);
}

template <typename T>
Complex<T> Complex<T>::operator+(const T& scalar) const {
    return Complex(real_ + scalar, imag_);
}

template <typename T>
Complex<T> Complex<T>::operator-(const T& scalar) const {
    return Complex(real_ - scalar, imag_);
}

template <typename T>
Complex<T> Complex<T>::operator*(const T& scalar) const {
    return Complex(real_ * scalar, imag_ * scalar);
}

#endif
