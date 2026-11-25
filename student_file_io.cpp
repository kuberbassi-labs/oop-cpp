#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int age;
    char sex;
    float height;
    float weight;

public:
    void getData() {
        cout << "Enter name: ";
        getline(cin >> ws, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter sex (M/F): ";
        cin >> sex;
        cout << "Enter height (in cm): ";
        cin >> height;
        cout << "Enter weight (in kg): ";
        cin >> weight;
    }

    void displayData() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Height: " << height << " cm" << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }

    void writeToFile(ofstream &out) const {
        out << name << '\n'
            << age << '\n'
            << sex << '\n'
            << height << '\n'
            << weight << '\n';
    }

    void readFromFile(ifstream &in) {
        getline(in >> ws, name);
        in >> age >> sex >> height >> weight;
    }
};

int main() {
    Student student;
    student.getData();

    ofstream outFile("student.txt");
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }
    student.writeToFile(outFile);
    outFile.close();

    ifstream inFile("student.txt");
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    Student readStudent;
    readStudent.readFromFile(inFile);
    inFile.close();

    cout << "\nData read from file:\n";
    readStudent.displayData();

    return 0;
}
