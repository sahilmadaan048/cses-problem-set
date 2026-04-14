// Author - sahilmadaan048

// https://cses.fi/problemset/task/1692

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << "01\n";
        return;
    }

    int nodes = 1 << (n - 1);
    vector<vector<int>> adj(nodes);

    // Build graph
    for (int mask = 0; mask < nodes; mask++)
    {
        for (int bit = 0; bit <= 1; bit++)
        {
            int next = ((mask << 1) & (nodes - 1)) | bit;
            adj[mask].push_back(next);
        }
    }

    vector<int> path;
    stack<int> st;

    st.push(0);

    while (!st.empty())
    {
        int u = st.top();

        if (!adj[u].empty())
        {
            int v = adj[u].back();
            adj[u].pop_back();
            st.push(v);
        }
        else
        {
            path.push_back(u);
            st.pop();
        }
    }

    reverse(path.begin(), path.end());

    string answer;

    // first node gives first n-1 bits
    for (int i = n - 2; i >= 0; i--)
    {
        answer += ((path[0] >> i) & 1) + '0';
    }

    // each next node contributes 1 bit
    for (int i = 1; i < path.size(); i++)
    {
        answer += (path[i] & 1) + '0';
    }

    cout << answer << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}