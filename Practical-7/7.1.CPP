#include <iostream>
using namespace std;

int main() {
    int n, choice, value;
    cout << "Enter queue capacity: ";
    cin >> n;

    int q[100], front = 0, rear = -1, count = 0;

    while (true) {
        cout << "\n1. Join  2. Serve  3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            if (count == n) {
                cout << "Error: Queue is full\n";
            } else {
                cout << "Enter token: ";
                cin >> value;
                rear = (rear + 1) % n;
                q[rear] = value;
                count++;
            }
        } else if (choice == 2) {
            if (count == 0) {



                cout << "Error: Queue is empty\n";
            } else {
                front = (front + 1) % n;
                count--;
            }
        } else {
            break;
        }

        if (count == 0)
            cout << "Front: Empty\n";
        else
            cout << "Front token: " << q[front] << endl;
    }

    return 0;
}
