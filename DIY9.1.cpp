#include <iostream>
using namespace std;

class BankAccount {
    int balance;

public:
    BankAccount() {
        balance = 5000;
    }

    void withdraw(int amount) {
        if (amount > balance)
            throw amount;

        balance -= amount;

        cout << "Remaining balance = " << balance;
    }
};

int main() {
    BankAccount b;
    int amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        b.withdraw(amount);
    }
    catch (int) {
        cout << "Insufficient Funds";
    }

    return 0;
}