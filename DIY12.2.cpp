#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    cout << "Top 3 largest elements:" << endl;

    int count = 0;

    while (!pq.empty() && count < 3) {
        cout << pq.top() << endl;
        pq.pop();
        count++;
    }

    return 0;
}