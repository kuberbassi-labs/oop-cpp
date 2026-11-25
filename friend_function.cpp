#include <iostream>
using namespace std;

class B;

class A {
    int x;

public:
    A(int val) : x(val) {}
    friend void findGreatest(A, B);
};

class B {
    int y;

public:
    B(int val) : y(val) {}
    friend void findGreatest(A, B);
};

void findGreatest(A obj1, B obj2) {
    if (obj1.x > obj2.y) {
        cout << "Greatest number is: " << obj1.x << endl;
    } else if (obj2.y > obj1.x) {
        cout << "Greatest number is: " << obj2.y << endl;
    } else {
        cout << "Both numbers are equal: " << obj1.x << endl;
    }
}

int main() {
    int num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    A a(num1);
    B b(num2);
    findGreatest(a, b);

    return 0;
}
