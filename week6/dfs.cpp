#include <bits/stdc++.h>

using namespace std;

void markVisited(int **G, int n, int k)
{
    for (int i = 0; i < n; ++i)
        G[i][k] = 2;
}

bool dfs(int **G, int n, int s, int d)
{
    vector<int> st;
    st.push_back(s);
    markVisited(G, n, s);
    while (!st.empty())
    {
        int x = st.back();
        st.pop_back();
        if (G[x][d] == 1)
            return true;
        else
        {
            for (int i = 0; i < n; ++i)
                if (G[x][i] == 1)
                    st.push_back(i);
            markVisited(G, n, x);
        }
    }
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
    int n;
    cin >> n;

    int **arr;
    arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; ++i)
        arr[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    int s, d;
    cin >> s >> d;
    bool isPresent = dfs(arr, n, s - 1, d - 1);
    if (isPresent)
        cout << "Yes Path Exists" << endl;
    else
        cout << "No Path Does Not Exist" << endl;
    return 0;
}