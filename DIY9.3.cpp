#include <iostream>
using namespace std;

class MathError {};

class DivideByZero : public MathError {};

int main() {
    try {
        throw DivideByZero();
    }
    catch (DivideByZero e) {
        cout << "DivideByZero caught" << endl;
    }
    catch (MathError e) {
        cout << "MathError caught" << endl;
    }

    return 0;
}