#include <cstring>
#include <iostream>
using namespace std;

class String {
    char str[100];

public:
    String() {
        str[0] = '\0';
    }

    String(const char s[]) {
        strncpy(str, s, sizeof(str) - 1);
        str[sizeof(str) - 1] = '\0';
    }

    String operator+(const String &s) const {
        String temp;
        strncpy(temp.str, str, sizeof(temp.str) - 1);
        temp.str[sizeof(temp.str) - 1] = '\0';
        strncat(temp.str, s.str, sizeof(temp.str) - strlen(temp.str) - 1);
        return temp;
    }

    String &operator=(const String &s) {
        if (this != &s) {
            strncpy(str, s.str, sizeof(str) - 1);
            str[sizeof(str) - 1] = '\0';
        }
        return *this;
    }

    bool operator<=(const String &s) const {
        return strcmp(str, s.str) <= 0;
    }

    void displayLength() const {
        cout << "Length of \"" << str << "\": " << strlen(str) << endl;
    }

    void tolower() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32;
            }
        }
    }

    void toupper() {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 32;
            }
        }
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;

    cout << "Concatenation (s1 + s2): ";
    s3.display();

    String s4;
    s4 = s1;
    cout << "Copy (s4 = s1): ";
    s4.display();

    if (s1 <= s2) {
        cout << "\"Hello\" is smaller than or equal to \"World\"" << endl;
    } else {
        cout << "\"Hello\" is greater than \"World\"" << endl;
    }

    s3.displayLength();

    String s5("HELLO WORLD");
    s5.tolower();
    cout << "Lowercase: ";
    s5.display();

    String s6("hello world");
    s6.toupper();
    cout << "Uppercase: ";
    s6.display();

    return 0;
}
