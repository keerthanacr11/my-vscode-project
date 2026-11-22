#include <iostream>
#include <queue>
#include <string>
using namespace std;

template <class T>
class Queue {
    T arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(T value) {
        if (rear == 99) {
            cout << "Queue is full" << endl;
            return;
        }

        arr[++rear] = value;
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Deleted: " << arr[front++] << endl;
    }

    void displayFront() {
        if (front > rear)
            cout << "Queue is empty" << endl;
        else
            cout << "Front: " << arr[front] << endl;
    }
};

int main() {
    Queue<string> q;

    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Mango");

    q.displayFront();
    q.dequeue();
    q.displayFront();

    return 0;
}