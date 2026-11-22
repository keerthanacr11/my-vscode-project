#include <iostream>
using namespace std;

class Shape {
public:
    Shape() {
        cout << "Shape ";
    }
};

class Polygon : public Shape {
public:
    Polygon() {
        cout << "Polygon ";
    }
};

class Rectangle : public Polygon {
public:
    Rectangle() {
        cout << "Rectangle";
    }
};

int main() {
    Rectangle r;

    return 0;
}