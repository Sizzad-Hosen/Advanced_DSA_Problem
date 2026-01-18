#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a); // undirected
    }

    // Print whole adjacency list
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : mat[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
