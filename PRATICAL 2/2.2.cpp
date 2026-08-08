#include <iostream>
using namespace std;

// Iterative Binary Search
int binaryIterative(int a[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == target)
            return mid;
        else if (target < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}// Recursive Binary Search
int binaryRecursive(int a[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (a[mid] == target)
        return mid;
    else if (target < a[mid])
        return binaryRecursive(a, low, mid - 1, target);
    else
        return binaryRecursive(a, mid + 1, high, target);
}

int main() {
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int n = 7;
    int target = 50;

    int result1 = binaryIterative(a, n, target);
    int result2 = binaryRecursive(a, 0, n - 1, target);

    cout << "Iterative Search Position: " << result1 << endl;
    cout << "Recursive Search Position: " << result2 << endl;

    return 0;
}
