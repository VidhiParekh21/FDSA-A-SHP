
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> shelf[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter book code: ";
        cin >> code;

        int index = code % 10;
        shelf[index].push_back(code);
    }

    cout << "\nLibrary shelves:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        for (int code : shelf[i])
            cout << code << " -> ";
        cout << "NULL\n";
    }

    return 0;
}
