#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrow records: ";
    cin >> n;

    int book[n];

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }
    cout << "Books borrowed more than once are: ";

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        // Skip if already checked
        bool checked = false;
        for (int k = 0; k < i; k++)
        {
            if (book[i] == book[k])
            {
                checked = true;
                break;
            }
        }

        if (checked)
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (book[i] == book[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            cout << book[i] << " ";
        }
    }

    return 0;
}
