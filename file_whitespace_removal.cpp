#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file: " << inputFileName << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file: " << outputFileName << endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (!isspace(static_cast<unsigned char>(ch))) {
            outputFile.put(ch);
        }
    }

    cout << "Whitespace removed and saved to " << outputFileName << endl;
    return 0;
}
