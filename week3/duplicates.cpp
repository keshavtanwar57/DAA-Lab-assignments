#include <bits/stdc++.h>

using namespace std;

void merge(int a[], int l, int m, int h)
{

    int b[h - l + 1], i, j, k;
    for (i = l, j = m + 1, k = 0; i <= m && j <= h;)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for (; i <= m; ++i)
        b[k++] = a[i];
    for (; j <= h; ++j)
        b[k++] = a[j];
    for (int i = l, j = 0; i <= h; ++i, ++j)
        a[i] = b[j];
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

bool haveDuplicates(int arr[], int l)
{
    for (int i = 1; i < l; ++i)
        if (arr[i] == arr[i - 1])
            return true;
    return false;
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
        mergeSort(arr, 0, l - 1);
        if (haveDuplicates(arr, l))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}