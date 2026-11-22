#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("nums.txt");

    int num, count = 0, sum = 0;
    int min, max;

    if (!fin) {
        cout << "File not found";
        return 0;
    }

    while (fin >> num) {
        if (count == 0)
            min = max = num;

        sum += num;

        if (num < min)
            min = num;

        if (num > max)
            max = num;

        count++;
    }

    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;

    if (count > 0) {
        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
    }

    fin.close();

    return 0;
}