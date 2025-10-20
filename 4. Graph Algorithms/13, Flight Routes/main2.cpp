#include <bits/stdc++.h>
using namespace std;

int n, m, k;

// max-heap to store the k shortest path sums
priority_queue<long long> pq;

void dfs(int node, long long sum, int end, unordered_map<int, vector<pair<int, int>>> &mpp, int depth)
{
    // limit recursion to avoid infinite loops in cycles
    if (depth > n * k)
        return;

    if (node == end)
    {
        if (pq.size() < k)
        {
            pq.push(sum);
        }
        else if (sum < pq.top())
        {
            pq.pop();
            pq.push(sum);
        }
        return;
    }

    for (auto [v, w] : mpp[node])
    {
        dfs(v, sum + w, end, mpp, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    unordered_map<int, vector<pair<int, int>>> mpp;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        mpp[a].push_back({b, c});
    }

    dfs(1, 0, n, mpp, 0);

    // extract results from max-heap into a vector and sort
    vector<long long> res;
    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    sort(res.begin(), res.end());

    for (long long x : res)
        cout << x << " ";
    cout << "\n";

    return 0;
}
