#include <iostream>
using namespace std;

class Box {
    int w, h, d;

public:
    // Parameterized constructor
    Box(int w, int h, int d) : w(w), h(h), d(d) {}

    // Default constructor - delegates
    Box() : Box(1, 1, 1) {}

    // Single parameter constructor - cube, delegates
    Box(int s) : Box(s, s, s) {}

    int volume() const {
        return w * h * d;
    }
};

int main() {
    Box a;
    Box b(3);
    Box c(2, 3, 4);

    cout << a.volume() << " "
         << b.volume() << " "
         << c.volume() << endl;

    return 0;
}