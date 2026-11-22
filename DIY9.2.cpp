#include <iostream>
using namespace std;

int main() {
    int a[2], top = -1;

    try {
        a[++top] = 10;
        a[++top] = 20;

        if (top == 1)
            throw 1;
    }
    catch (int x) {
        cout << "Stack Overflow" << endl;
    }

    try {
        top = -1;

        if (top == -1)
            throw 2;
    }
    catch (int x) {
        cout << "Stack Underflow";
    }

    return 0;
}