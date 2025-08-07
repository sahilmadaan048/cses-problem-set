// author - sahilmadaan048
// https://cses.fi/problemset/task/1133/

//bruthe force will be to do a bfs or dfs from every node which will take O(n^2)
#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5 + 7;
vector<int> graph[N];

int bfs(int src) {
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push(make_pair(src, 0));
    visited[src] = true;

    int sum = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int node = p.first;
        int dist = p.second;

        sum += dist;

        for (int v : graph[node]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(make_pair(v, dist + 1));
            }
        }
    }

    return sum;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int a, b;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cout << bfs(i) << " ";
    }
    cout << endl;

    return 0;
}
