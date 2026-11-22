#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks;
};

int main() {
    Student s[100];
    int n;

    ofstream fout("student.txt");

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter name and marks: ";
        cin >> s[i].name >> s[i].marks;

        fout << s[i].name << " " << s[i].marks << endl;
    }

    fout.close();

    ifstream fin("student.txt");
    int i = 0;

    while (i < 100 && fin >> s[i].name >> s[i].marks)
        i++;

    int topper = 0;

    for (int j = 1; j < i; j++)
        if (s[j].marks > s[topper].marks)
            topper = j;

    cout << "\nStudent Records:\n";

    for (int j = 0; j < i; j++)
        cout << s[j].name << " " << s[j].marks << endl;

    if (i > 0) {
        cout << "\nTopper: " << s[topper].name << endl;
        cout << "Marks: " << s[topper].marks;
    }

    fin.close();

    return 0;
}