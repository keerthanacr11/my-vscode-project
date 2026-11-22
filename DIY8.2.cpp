#include <iostream>
using namespace std;

class Logger {
public:
    virtual void write() = 0;
};

class ConsoleLogger : public Logger {
public:
    void write() {
        cout << "Console Logger" << endl;
    }
};

class FileLogger : public Logger {
public:
    void write() {
        cout << "File Logger" << endl;
    }
};

int main() {
    ConsoleLogger c;
    FileLogger f;
    Logger *p;

    p = &c;
    p->write();

    p = &f;
    p->write();

    return 0;
}