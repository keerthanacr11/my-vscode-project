// Fraction I/O #include <iostream> using namespace std;
class Fraction { public:
int n, d;
Fraction(int a, int b) { n = a;
d = b;
}
void display() { int a = n, b = d; while (b != 0) {
int r = a % b;
a = b;
b = r;
}
cout << n / a << "/" << d / a;
}
};
int main() { Fraction f(8, 12); f.display(); return 0;
}
