#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int n, unordered_map<int, vector<pair<int, int>>> &mpp, vector<int> &temp)
{
    vector<int> dist(n + 1, 1e9); // <-- +1 for 1-based safety
    vector<int> parent(n+1, -1);
    dist[1] = 0; // assuming graph starts from 1

    int x = -1;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto &[u, vec] : mpp)
        {
            for (auto &[v, w] : vec)
            {
                if (u <= n && v <= n && dist[u] != 1e9 && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    for (auto &[u, vec] : mpp)
    {
        for (auto &[v, w] : vec)
        {
            if (u <= n && v <= n && dist[u] != 1e9 && dist[u] + w < dist[v])
            {
                parent[v]=u;
                x = v;
                break;
            }
        }
        if(x != -1) {
            break;
        }
    }

    if(x == -1) {
        return false; // no -ve cycle found
    }


    for(int i=0; i<n; i++) {
        x = parent[x];
    }
    int start = x;
    temp.push_back(start);
    x = parent[start];

    while(x != start) {
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

    vector<int> temp;

    if (hasCycle(n, mpp, temp))
    {
        cout << "YES\n";
        for (auto ele : temp) cout << ele << " ";        
        cout << "\0n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
