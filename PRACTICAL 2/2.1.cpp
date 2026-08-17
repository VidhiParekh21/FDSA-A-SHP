#include <iostream>
using namespace std;

// Iterative Linear Search
int linearIterative(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target)
            return i;
    }
    return -1;
}

// Recursive Linear Search
int linearRecursive(int a[], int n, int target, int i) {
    if (i == n)
        return -1;

    if (a[i] == target)
        return i;

    return linearRecursive(a, n, target, i + 1);
}

int main() {
    int n, target;

    cout << "Enter number of license plates: ";
    cin >> n;

    int a[100];

    cout << "Enter license plate numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Enter target license plate: ";
    cin >> target;

    int result1 = linearIterative(a, n, target);
    int result2 = linearRecursive(a, n, target, 0);

    cout << "\nIterative Search Position: " << result1 << endl;
    cout << "Recursive Search Position: " << result2 << endl;

    return 0;
}
