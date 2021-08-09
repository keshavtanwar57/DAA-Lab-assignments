#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int i, k, comparision = 0;
        int middle = int(n / 2), start = 0, end = n;
        cout << "enter key: ";
        cin >> k;
        if (k >= a[0] && k <= a[n])
        {
            bool found = false;
            while (start + middle != end)
            {
                comparision++;
                if (a[middle] == k)
                {

                    found = true;
                    break;
                }
                else if (a[middle] > k)
                {
                    end = middle;
                    middle = int((start + end) / 2);
                }
                else
                {
                    start = middle;
                    middle = int((start + end) / 2);
                }
            }

            if (found == true)
            {
                cout << "Present " << comparision;
            }
            else
            {
                cout << "Not Present";
            }
        }
        else
        {
            cout << "number not Present";
        }
    }
}