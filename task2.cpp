#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <limits>

using namespace std;

// Base class
class Student
{
protected:
    int rollNo;
    string name;

public:
    Student(int r, string n)
    {
        rollNo = r;
        name = n;
    }

    virtual void display() const
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }

    virtual ~Student() {}
};

// Derived class
class Result : public Student
{
private:
    float m1, m2, m3;
    float average;

public:
    Result(int r, string n, float a, float b, float c)
        : Student(r, n)
    {
        if (a < 0 || a > 100 ||
            b < 0 || b > 100 ||
            c < 0 || c > 100)
        {
            throw invalid_argument("Invalid marks! Enter marks between 0 and 100.");
        }

        m1 = a;
        m2 = b;
        m3 = c;

        average = (m1 + m2 + m3) / 3.0;
    }

    float getAverage() const
    {
        return average;
    }

    // Runtime polymorphism
    void display() const override
    {
        Student::display();

        cout << "Subject 1 Marks: " << m1 << endl;
        cout << "Subject 2 Marks: " << m2 << endl;
        cout << "Subject 3 Marks: " << m3 << endl;

        cout << "Average Marks: "
             << fixed << setprecision(2)
             << average << endl;

        cout << "--------------------------" << endl;
    }

    // Store records in file
    void saveToFile(ofstream &file) const
    {
        file << rollNo << "|"
             << name << "|"
             << m1 << "|"
             << m2 << "|"
             << m3 << "|"
             << average << endl;
    }
};

int main()
{
    vector<Result> students;
    int n;

    cout << "STUDENT RESULT MANAGEMENT SYSTEM" << endl;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n;)
    {
        try
        {
            int roll;
            string name;
            float a, b, c;

            cout << "\nEnter Roll Number: ";
            cin >> roll;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Student Name: ";
            getline(cin, name);

            cout << "Enter marks in 3 subjects: ";
            cin >> a >> b >> c;

            Result s(roll, name, a, b, c);

            students.push_back(s);
            i++;
        }
        catch (const invalid_argument &e)
        {
            cout << "Exception: " << e.what() << endl;
            cout << "Please enter the student details again.\n";
        }
    }

    // Display all student records
    cout << "\n--- STUDENT DETAILS ---\n";

    for (const Result &s : students)
    {
        const Student *ptr = &s;
        ptr->display();
    }

    // Lambda expression
    float threshold;

    cout << "\nEnter average mark threshold: ";
    cin >> threshold;

    auto aboveThreshold = [threshold](const Result &s)
    {
        return s.getAverage() > threshold;
    };

    cout << "\n--- STUDENTS SCORING ABOVE THRESHOLD ---\n";

    bool found = false;

    for (const Result &s : students)
    {
        if (aboveThreshold(s))
        {
            s.display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No students scored above the threshold.\n";
    }

    // File handling - storing records
    ofstream outFile("student_records.txt");

    if (outFile.is_open())
    {
        for (const Result &s : students)
        {
            s.saveToFile(outFile);
        }

        outFile.close();
        cout << "\nRecords saved successfully.\n";
    }
    else
    {
        cout << "\nUnable to open file for writing.\n";
    }

    // File handling - retrieving records
    ifstream inFile("student_records.txt");

    if (inFile.is_open())
    {
        string line;

        cout << "\n--- RETRIEVED STUDENT RECORDS ---\n";

        while (getline(inFile, line))
        {
            cout << line << endl;
        }

        inFile.close();
    }
    else
    {
        cout << "\nUnable to open file for reading.\n";
    }

    return 0;
}