#include <iostream>
#include "complex.h"

int main()
{
    Complex<double> z0;
    Complex<double> z1(3.0, 4.0);
    Complex<double> z2(1.5, -2.0);

    std::cout << "z0 = " << z0 << "\n";
    std::cout << "z1 = " << z1 << "\n";
    std::cout << "z2 = " << z2 << "\n\n";

    std::cout << "z1 + z2 = " << (z1 + z2) << "\n";
    std::cout << "z1 - z2 = " << (z1 - z2) << "\n";
    std::cout << "z1 * z2 = " << (z1 * z2) << "\n\n";

    std::cout << "z1 + 2.0 = " << (z1 + 2.0) << "\n";
    std::cout << "2.0 + z1 = " << (2.0 + z1) << "\n";

    std::cout << "z1 - 2.0 = " << (z1 - 2.0) << "\n";
    std::cout << "2.0 - z1 = " << (2.0 - z1) << "\n";

    std::cout << "z1 * 2.0 = " << (z1 * 2.0) << "\n";
    std::cout << "2.0 * z1 = " << (2.0 * z1) << "\n\n";

    Complex<int> a(3, 4);
    Complex<int> b(1, -2);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";

    return 0;
}
