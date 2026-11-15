#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

    static int count;

public:
    // Parameterized constructor
    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
        count++;
    }

    // Function overloading
    void display() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    void display(string message) {
        cout << message << endl;
        display();
    }

    // Static member function
    static int getCount() {
        return count;
    }

    // Friend function
    friend void compareMarks(Student s1, Student s2);

    // Operator overloading
    bool operator>(Student s) {
        return marks > s.marks;
    }
};

// Definition of static member
int Student::count = 0;

// Friend function definition
void compareMarks(Student s1, Student s2) {
    if (s1.marks > s2.marks)
        cout << s1.name << " has higher marks." << endl;
    else if (s2.marks > s1.marks)
        cout << s2.name << " has higher marks." << endl;
    else
        cout << "Both students have equal marks." << endl;
}

int main() {
    Student s1(101, "Rahul", 85);
    Student s2(102, "Ananya", 92);

    cout << "Student 1 Details:" << endl;
    s1.display();

    cout << "\nStudent 2 Details:" << endl;
    s2.display("Student Details:");

    cout << "\nTotal Students: "
         << Student::getCount() << endl;

    cout << "\nComparison using Friend Function:" << endl;
    compareMarks(s1, s2);

    cout << "\nComparison using Operator Overloading:" << endl;
    if (s2 > s1)
        cout << "Ananya has higher marks than Rahul." << endl;
    else
        cout << "Rahul has higher or equal marks." << endl;

    return 0;
}