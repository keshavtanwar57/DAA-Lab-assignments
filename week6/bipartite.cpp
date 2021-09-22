#include <bits/stdc++.h>

using namespace std;

void markVisited(int **G, int n, int k)
{
    for (int i = 0; i < n; ++i)
        if (G[i][k] == 1)
            G[i][k] = 2;
}

bool bipartite(int **G, int n)
{
    queue<int> Queue;
    Queue.push(0);
    int color[n] = {1};
    markVisited(G, n, 0);
    while (!Queue.empty())
    {
        int u = Queue.front();
        Queue.pop();
        int curCol = color[u] * -1;
        for (int i = 0; i < n; ++i)
        {
            if (G[u][i] != 0)
            {
                if (color[i] == 0)
                    color[i] = curCol;
                else if (color[i] != curCol)
                    return false;
                if (G[u][i] == 1)
                {
                    Queue.push(i);
                    markVisited(G, n, i);
                }
            }
        }
    }
    return true;
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
    bool isBipartite = bipartite(arr, n);
    if (isBipartite)
        cout << "Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;
    return 0;
}