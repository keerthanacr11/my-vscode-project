#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    int *p;

    Derived() {
        p = new int[5];
        cout << "Memory allocated" << endl;
    }

    ~Derived() {
        delete[] p;
        cout << "Derived destructor" << endl;
    }
};

int main() {
    Base *b = new Derived();

    delete b;

    return 0;
}