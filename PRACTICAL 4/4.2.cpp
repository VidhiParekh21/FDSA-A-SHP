#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

Node* head = NULL;

// Add patient at end
void insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->token = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete patient by token
void deleteValue(int value)
{
    if (head == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }

    if (head->token == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->token != value)
        temp = temp->next;

    if (temp->next == NULL)
    {
        cout << "Token not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Patient deleted\n";
}

// Display front to back
void display()
{
    Node* temp = head;

    cout << "Front to Back: ";

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Display back to front
void reversePrint(Node* temp)
{
    if (temp == NULL)
        return;

    reversePrint(temp->next);
    cout << temp->token << " ";
}

int main()
{
    int choice, token;

    while (true)
    {
        cout << "\n1 Add Patient";
        cout << "\n2 Delete Patient";
        cout << "\n3 Display Front to Back";
        cout << "\n4 Display Back to Front";
        cout << "\n5 Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter token: ";
            cin >> token;
            insertEnd(token);
        }
        else if (choice == 2)
        {
            cout << "Enter token to delete: ";
            cin >> token;
            deleteValue(token);
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            cout << "Back to Front: ";
            reversePrint(head);
            cout << endl;
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
