#include <iostream>
using namespace std;
struct Node {
    string name;
    Node *next;
    Node *prev;
};
Node *head1 = NULL;
Node *head2 = NULL;
void addSingly() {
    string name;
    cout << "Enter student name: ";
    cin >> name;
    Node *n = new Node;
    n->name = name;
    if (head1 == NULL) {
        head1 = n;
        n->next = head1;
    } else {
        Node *temp = head1;
        while (temp->next != head1)
            temp = temp->next;
        n->next = head1;
        temp->next = n;
    }
}
void removeSingly() {
    if (head1 == NULL) {
        cout << "Circle is empty!\n";
        return;
    }
    string name;
    cout << "Enter student to remove: ";
    cin >> name;
    Node *temp = head1;
    Node *prev = NULL;
    do {
        if (temp->name == name)
            break;
        prev = temp;
        temp = temp->next;
    } while (temp != head1);
    if (temp->name != name) {
        cout << "Student not found!\n";
        return;
    }
    if (temp == head1) {
        if (head1->next == head1) {
            delete head1;
            head1 = NULL;
        } else {
            Node *last = head1;
            while (last->next != head1)
                last = last->next;
            head1 = head1->next;
            last->next = head1;
            delete temp;
        }
    } else {
        prev->next = temp->next;
        delete temp;
    }
}
void displaySingly() {
    if (head1 == NULL) {
        cout << "Circle is empty!\n";
        return;
    }
    Node *temp = head1;
    cout << "Singly Circular: ";
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head1);
    cout << endl;
}
void addDoubly() {
    string name;
    cout << "Enter student name: ";
    cin >> name;
    Node *n = new Node;
    n->name = name;
    if (head2 == NULL) {
        head2 = n;
        n->next = head2;
        n->prev = head2;
    } else {
        Node *last = head2->prev;
        n->next = head2;
        n->prev = last;
        last->next = n;
        head2->prev = n;
    }
}
void removeDoubly() {
    if (head2 == NULL) {
        cout << "Circle is empty!\n";
        return;
    }
    string name;
    cout << "Enter student to remove: ";
    cin >> name;
    Node *temp = head2;
    do {
        if (temp->name == name)
            break;
        temp = temp->next;
    } while (temp != head2);
    if (temp->name != name) {
        cout << "Student not found!\n";
        return;
    }
    if (temp->next == temp) {
        head2 = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == head2)
            head2 = temp->next;
    }
    delete temp;
}
void displayDoubly() {
    if (head2 == NULL) {
        cout << "Circle is empty!\n";
        return;
    }
    Node *temp = head2;
    cout << "Doubly Circular: ";
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head2);
    cout << endl;
}
int main() {
    int choice;
    do {
        cout << "\n1. Join student\n";
        cout << "2. Leave student\n";
        cout << "3. Display circles\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "\nSingly Circular List\n";
            addSingly();
            cout << "Doubly Circular List\n";
            addDoubly();
            displaySingly();
            displayDoubly();
        } else if (choice == 2) {
            cout << "\nSingly Circular List\n";
            removeSingly();
            cout << "Doubly Circular List\n";
            removeDoubly();
            displaySingly();
            displayDoubly();
        } else if (choice == 3) {
            displaySingly();
            displayDoubly();
        } else if (choice == 4) {
            cout << "Program ended.\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
