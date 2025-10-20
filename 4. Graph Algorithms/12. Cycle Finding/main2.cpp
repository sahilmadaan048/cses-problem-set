#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int n, unordered_map<int, vector<pair<int, int>>> &mpp, vector<int> &temp)
{
    vector<long long> dist(n + 1, 1e15);
    vector<int> parent(n + 1, -1);
    dist[1] = 0;

    int x = -1; // will store a vertex involved in the negative cycle

    // Relax edges n - 1 times
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto &[u, vec] : mpp)
        {
            for (auto &[v, w] : vec)
            {
                if (u <= n && v <= n && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycle on nth iteration
    for (auto &[u, vec] : mpp)
    {
        for (auto &[v, w] : vec)
        {
            if (u <= n && v <= n && dist[u] + w < dist[v])
            {
                parent[v] = u;
                x = v; // vertex part of a negative cycle
                break;
            }
        }
        if (x != -1)
            break;
    }

    if (x == -1)
        return false; // no negative cycle

    // Reconstruct the cycle
    // Move back n times to ensure we reach inside the cycle
    for (int i = 0; i < n; i++)
        x = parent[x];

    int start = x;
    temp.push_back(start);
    x = parent[start];

    while (x != start)
    {
        temp.push_back(x);
        x = parent[x];
    }
    temp.push_back(start);
    reverse(temp.begin(), temp.end());

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> mpp;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        mpp[a].push_back({b, w});
    }

    vector<int> temp; // will store the negative cycle if returned YES

    if (hasCycle(n, mpp, temp))
    {
        cout << "YES\n";
        for (auto ele : temp)
            cout << ele << " ";
        cout << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
