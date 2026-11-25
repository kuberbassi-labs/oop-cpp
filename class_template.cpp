#include <iostream>
using namespace std;

template <typename T>
class Compare {
    T num1, num2;

public:
    Compare(T n1, T n2) : num1(n1), num2(n2) {
        cout << "Constructor: Two numbers initialized." << endl;
    }

    T findBigger() const {
        return (num1 > num2) ? num1 : num2;
    }

    ~Compare() {
        cout << "Destructor: Object destroyed." << endl;
    }
};

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    Compare<int> comp(a, b);
    cout << "Bigger number: " << comp.findBigger() << endl;

    return 0;
}
