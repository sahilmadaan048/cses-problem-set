#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(int node, int sum, int end, unordered_map<int, vector<pair<int, int>>> &mpp, priority_queue<int, vector<int>> &pq)
{
    if (node == end)
    {
        pq.push(sum);
        return;
    }

    visited[node] = true;

    for (auto [v, w] : mpp[node])
    {
        if (!visited[v])
        {
            dfs(v, sum + w, end, mpp, pq);
        }
    }

    visited[node] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code here

    int n, m, k;
    cin >> n >> m >> k;

    unordered_map<int, vector<pair<int, int>>> mpp;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        mpp[a].push_back({b, w});
    }

    visited.assign(n + 1, false);
    priority_queue<int> pq; // maxHeap by defaut;

    dfs(1, 0, n, mpp, pq);

    while (k-- and !pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
    return 0;
}
