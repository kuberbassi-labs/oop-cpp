#include <iostream>
using namespace std;

template <typename T>
T square(T num) {
    return num * num;
}

int main() {
    int intNum;
    double doubleNum;
    float floatNum;

    cout << "Enter an integer: ";
    cin >> intNum;
    cout << "Enter a double: ";
    cin >> doubleNum;
    cout << "Enter a float: ";
    cin >> floatNum;

    cout << "Square of " << intNum << " is: " << square(intNum) << endl;
    cout << "Square of " << doubleNum << " is: " << square(doubleNum) << endl;
    cout << "Square of " << floatNum << " is: " << square(floatNum) << endl;

    return 0;
}
