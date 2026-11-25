#include <iostream>
#include <stdexcept>
using namespace std;

class Array {
    int *arr;
    int size;

public:
    Array(int s) : size(s) {
        arr = new int[size];
    }

    ~Array() {
        delete[] arr;
    }

    void setValue(int index, int value) {
        if (index < 0 || index >= size) {
            throw out_of_range("index out of bounds");
        }
        arr[index] = value;
    }

    int getValue(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("index out of bounds");
        }
        return arr[index];
    }
};

int main() {
    try {
        Array myArray(5);
        for (int i = 0; i < 5; i++) {
            myArray.setValue(i, (i + 1) * 10);
            cout << myArray.getValue(i) << endl;
        }
        cout << endl;
        cout << myArray.getValue(5) << endl;
    } catch (const out_of_range &e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
