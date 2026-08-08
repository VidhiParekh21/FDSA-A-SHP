#include <iostream>
using namespace std;

// Iterative Linear Search
int linearIterative(int a[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (a[i] == target)
            return i;
    }
    return -1;
}// Recursive Linear Search
int linearRecursive(int a[], int n, int target, int i) {
    if (i == n)
        return -1;

    if (a[i] == target)
        return i;

    return linearRecursive(a, n, target, i + 1);
}
int main() {
    int a[] = {25, 12, 45, 30, 18, 45};
    int n = 6;
    int target = 45;

    int result1 = linearIterative(a, n, target);
    int result2 = linearRecursive(a, n, target, 0);

    cout << "Iterative Search Position: " << result1 << endl;
    cout << "Recursive Search Position: " << result2 << endl;

    return 0;
}
