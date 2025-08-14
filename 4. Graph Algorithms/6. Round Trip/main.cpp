// https://cses.fi/problemset/task/1669

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool vis[MAXN];
vector<int> path;

bool dfs(int node, int parent)
{
    vis[node] = true;
    path.push_back(node);

    for (int neighbor : adj[node])
    {
        if (!vis[neighbor])
        {
            if (dfs(neighbor, node))
                return true;
        }
        else if (neighbor != parent)
        {
            path.push_back(neighbor);
            return true;
        }
    }

    path.pop_back();
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            path.clear();
            if (dfs(i, 0))
            {
                vector<int> cycle;
                int start = path.back();
                cycle.push_back(start);

                for (auto it = path.rbegin() + 1; it != path.rend(); ++it)
                {
                    cycle.push_back(*it);
                    if (*it == start)
                        break;
                }

                cout << cycle.size() << "\n";
                for (int x : cycle)
                    cout << x << " ";
                cout << "\n";
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
 