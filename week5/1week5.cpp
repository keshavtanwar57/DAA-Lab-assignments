#include <iostream>

using namespace std;

int main()
{
    int t;
    cout << "Test Case: ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int duplicate = 0;
        int a[26] = {};
        int n;
        cout << "Array Size: ";
        cin >> n;
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {

            int index = int(s[j]) - 'a';
            if (index == 2)
            {
                duplicate = 1;
            }
            a[index]++;
        }
        if (duplicate == 0)
        {
            cout << "No Duplicate";
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (a[j] > 1)
                {
                    cout << char(j + 'a') << "-" << a[j] << endl;
                }
            }
        }
    }
    return 0;
}