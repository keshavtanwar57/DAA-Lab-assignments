#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int l)
{
    int noc = 0, swap = 0;
    for (int i = 0; i < l - 1; ++i)
    {
        int sm = i;
        for (int j = i + 1; j < l; ++j)
        {
            noc++;
            if (arr[sm] > arr[j])
                sm = j;
        }
        swap++;
        int temp = arr[sm];
        arr[sm] = arr[i];
        arr[i] = temp;
    }
    for (int i = 0; i < l; ++i)
        cout << arr[i] << " ";
    cout << endl;
    cout << "comparisons = " << noc << endl;
    cout << "swaps = " << swap << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int no;
    cin >> no;
    for (int f = 0; f < no; f++)
    {
        int l;
        cin >> l;
        int arr[l];
        for (int i = 0; i < l; ++i)
            cin >> arr[i];
        selectionSort(arr, l);
    }

    return 0;
}