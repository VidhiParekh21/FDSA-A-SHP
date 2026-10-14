#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *front = NULL, *rear = NULL;
    int choice, value;

    while (true) {
        cout << "\n1. Arrive  2. Attend  3. Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient number: ";
            cin >> value;

            Node* newNode = new Node{value, NULL};

            if (front == NULL)
                front = rear = newNode;
            else {
                rear->next = newNode;
                rear = newNode;
            }
        } else if (choice == 2) {
            if (front == NULL) {
                cout << "Error: No patients waiting\n";
            } else {
                Node* temp = front;
                front = front->next;
                delete temp;

                if (front == NULL)
                    rear = NULL;
            }
        } else {
            break;
        }

        if (front == NULL)
            cout << "Front patient: Empty\n";
        else
            cout << "Front patient: " << front->data << endl;
    }

    while (front != NULL) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    return 0;
}
