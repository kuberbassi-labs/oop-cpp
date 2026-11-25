#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(float a) : real(a), imag(a) {}

    Complex(float r, float i) : real(r), imag(i) {}

    Complex add(const Complex &c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(5);
    Complex c2(2, 4);
    Complex c3 = c1.add(c2);

    cout << "First Number:  ";
    c1.display();
    cout << "Second Number: ";
    c2.display();
    cout << "Sum:           ";
    c3.display();

    return 0;
}
