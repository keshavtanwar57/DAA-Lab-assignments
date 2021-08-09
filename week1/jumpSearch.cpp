#include <iostream>

using namespace std;

int main()
{
    int t;
    cout << "Enter total number of test cases: ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k, jumpSize;
        cout << "Enter the size: ";
        cin >> n;
        int a[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        cout << "enter key: ";
        cin >> k;
        cout << "Enter jump Size: ";
        cin >> jumpSize;
        bool found = false;
        int UpperBound, lowerBound, comparision = 0;
        for (int j = 0; j < n; j += jumpSize)
        {
            comparision++;
            if (a[j] == k)
            {
                found = true;
                break;
            }
            if (a[j] > k)
            {
                UpperBound = j;
                lowerBound = j - jumpSize;

                for (int l = lowerBound; l < UpperBound; l++)
                {
                    comparision++;
                    if (a[l] == k)
                    {
                        found = true;
                        break;
                    }
                }
            }
        }
        if (found)
        {
            cout << "Present ";
            cout << comparision;
        }
        else
        {
            cout << "Not Present";
        }
    }
}