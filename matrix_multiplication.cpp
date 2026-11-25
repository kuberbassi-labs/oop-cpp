#include <iostream>
using namespace std;

class Matrix {
    int data[10][10];
    int rows, cols;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {}

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    Matrix multiply(const Matrix &other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible\n";
        return 0;
    }

    Matrix a(r1, c1), b(r2, c2);
    cout << "Enter elements of first matrix row-wise:\n";
    a.input();
    cout << "Enter elements of second matrix row-wise:\n";
    b.input();

    Matrix c = a.multiply(b);
    cout << "Result matrix:\n";
    c.display();

    return 0;
}
