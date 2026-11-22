#include <iostream>
using namespace std;

template <class T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T findMax(T arr[], int n) {
    T max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

int main() {
    int a = 10, b = 20;
    swapVals(a, b);

    cout << "Swapped integers: " << a << " " << b << endl;

    int arr1[] = {10, 50, 30, 20};
    cout << "Maximum integer: " << findMax(arr1, 4) << endl;

    double x = 2.5, y = 5.5;
    swapVals(x, y);

    cout << "Swapped doubles: " << x << " " << y << endl;

    double arr2[] = {2.5, 8.5, 4.5, 6.5};
    cout << "Maximum double: " << findMax(arr2, 4) << endl;

    return 0;
}