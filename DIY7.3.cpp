#include <iostream>
using namespace std;

class Person {
public:
    int id = 10;
};

class Student : virtual public Person {};

class Employee : virtual public Person {};

class TA : public Student, public Employee {};

int main() {
    TA t;

    cout << t.id;

    return 0;
}