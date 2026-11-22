#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual void area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void area() override {
        float r;
        cout << "Enter radius: ";
        cin >> r;
        cout << "Area of Circle = " << 3.14 * r * r << endl;
    }
};

class Rectangle : public Shape {
public:
    void area() override {
        float l, b;
        cout << "Enter length and breadth: ";
        cin >> l >> b;
        cout << "Area of Rectangle = " << l * b << endl;
    }
};

class Triangle : public Shape {
public:
    void area() override {
        float b, h;
        cout << "Enter base and height: ";
        cin >> b >> h;
        cout << "Area of Triangle = " << 0.5 * b * h << endl;
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    int n;

    cout << "Enter number of shapes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;

        cout << "Enter shape name (Circle/Rectangle/Triangle): ";
        cin >> name;

        if (name == "Circle")
            shapes.push_back(make_unique<Circle>());
        else if (name == "Rectangle")
            shapes.push_back(make_unique<Rectangle>());
        else if (name == "Triangle")
            shapes.push_back(make_unique<Triangle>());
        else {
            cout << "Invalid shape!" << endl;
            continue;
        }

        shapes.back()->area();
    }

    return 0;
}