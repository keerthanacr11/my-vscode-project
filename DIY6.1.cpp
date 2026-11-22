// Program 6.5 – Money arithmetic using operator overloading

#include <iostream>
using namespace std;

class Money
{
    int rupees, paise;

public:
    // Constructor
    Money(int r = 0, int p = 0)
    {
        rupees = r + p / 100;
        paise = p % 100;
    }

    // Overloading + operator
    Money operator+(const Money &m) const
    {
        int totalPaise = paise + m.paise;
        int totalRupees = rupees + m.rupees;

        if (totalPaise >= 100)
        {
            totalRupees++;
            totalPaise -= 100;
        }

        return Money(totalRupees, totalPaise);
    }

    // Overloading - operator
    Money operator-(const Money &m) const
    {
        int totalRupees = rupees - m.rupees;
        int totalPaise = paise - m.paise;

        if (totalPaise < 0)
        {
            totalRupees--;
            totalPaise += 100;
        }

        return Money(totalRupees, totalPaise);
    }

    // Display function
    void show() const
    {
        cout << rupees << " rupees " << paise << " paise" << endl;
    }
};

int main()
{
    Money a(10, 75);
    Money b(5, 50);

    Money sum = a + b;
    Money diff = a - b;

    cout << "Money 1: ";
    a.show();

    cout << "Money 2: ";
    b.show();

    cout << "Addition: ";
    sum.show();

    cout << "Subtraction: ";
    diff.show();

    return 0;
}