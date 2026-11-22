#include <iostream>
using namespace std;

class Employee {
public:
    string name = "Ravi";
    int id = 1;
};

class Manager : public Employee {
public:
    int team = 5;
};

class Engineer : public Employee {
public:
    string skill = "C++";
};

int main() {
    Manager m;
    Engineer e;

    cout << m.name << " " << m.id
         << " " << m.team << endl;

    cout << e.name << " " << e.id
         << " " << e.skill;

    return 0;
}