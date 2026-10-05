#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string page;
    Node* next;
};

int main()
{
    Node* top = NULL;
    string currentPage = "Home";
    int operations;
    cout << "Current page: " << currentPage << endl;
    cout << "Enter number of operations: ";
    cin >> operations;
    for (int i = 0; i < operations; i++)
    {
        int choice;
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string page;
            cout << "Enter page name: ";
            cin >> page;
            Node* newNode = new Node;
            newNode->page = currentPage;
            newNode->next = top;
            top = newNode;
            currentPage = page;
            cout << "Current page: " << currentPage << endl;
        }
        else if (choice == 2)
        {
            if (top == NULL)
            {
                cout << "No history. Already on first page." << endl;
            }
            else
            {
                Node* temp = top;
               currentPage = top->page;
                top = top->next;
                delete temp;
                cout << "Current page: " << currentPage << endl;
            }
        }
        else
        {
            cout << "Invalid choice";
        }
    }
   return 0;
}
