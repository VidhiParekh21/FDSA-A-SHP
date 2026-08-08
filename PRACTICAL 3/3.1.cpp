#include <iostream>
using namespace std;

void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {78, 45, 92, 61, 35, 88, 50};
    int n = 7;

    // Bubble Sort
    int b[7];
    for (int i = 0; i < n; i++)
        b[i] = a[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    cout << "Bubble Sort: ";
    display(b, n);

    // Selection Sort
    int s[7];
    for (int i = 0; i < n; i++)
        s[i] = a[i];

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[min])
                min = j;
        }

        int temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }

    cout << "Selection Sort: ";
    display(s, n);

    // Insertion Sort
    int in[7];
    for (int i = 0; i < n; i++)
        in[i] = a[i];

    for (int i = 1; i < n; i++) {
        int key = in[i];
        int j = i - 1;

        while (j >= 0 && in[j] > key) {
            in[j + 1] = in[j];
            j--;
        }

        in[j + 1] = key;
    }

    cout << "Insertion Sort: ";
    display(in, n);

    return 0;
}
