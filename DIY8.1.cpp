#include <iostream>
using namespace std;

class Account {
public:
    virtual void interest() = 0;
};

class Savings : public Account {
public:
    void interest() {
        cout << "Savings interest: 5%" << endl;
    }
};

class Current : public Account {
public:
    void interest() {
        cout << "Current interest: 2%" << endl;
    }
};

int main() {
    Savings s;
    Current c;

    Account *a[2] = {&s, &c};

    a[0]->interest();
    a[1]->interest();

    return 0;
}