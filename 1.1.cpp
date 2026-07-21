#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of items: ";
    cin >> n;

    int items[n];

    cout << "Enter the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;

    h = h % n;   // Reduce unnecessary rotations

    for (int k = 0; k < h; k++)
    {
        int first = items[0];

        for (int i = 0; i < n - 1; i++)
        {
            items[i] = items[i + 1];
        }

        items[n - 1] = first;
    }

    cout << "Final display order: ";
    for (int i = 0; i < n; i++)
    {
        cout << items[i] << " ";
    }

    return 0;
}

