#include <iostream>

using namespace std;

int main()
{

    int t;
    cout << "Enter Number of test case: ";
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n, key;
        cout << "Enter the size of the array: ";
        cin >> n;
        int arr[n];
        cout << "Enter Array : " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter key: ";
        cin >> key;
        bool found = false;
        int comparison = 0;
        for (int i = 0; i < n; i++)
        {
            comparison++;
            if (arr[i] == key)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << " Present" << endl;
        }
        else
        {
            cout << "Not Present" << endl;
        }
        cout << "Number of comparision = " << comparison;
    }
}