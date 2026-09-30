#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char *data;

public:
    // Parameterized constructor
    MyString(const char *s) {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // Deep copy constructor
    MyString(const MyString &o) {
        data = new char[strlen(o.data) + 1];
        strcpy(data, o.data);
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    void print() const {
        cout << data << endl;
    }
};

int main() {
    MyString a("hardware");
    MyString b = a;     // Copy constructor runs → deep copy

    a.print();
    b.print();

    return 0;
}