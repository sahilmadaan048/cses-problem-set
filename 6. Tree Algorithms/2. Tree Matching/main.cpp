#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N];
bool matched[N];  // matched[i] = true if node i is already matched
int answer = 0;

void dfs(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);

        // Try to match u and v if both are unmatched
        if (!matched[u] && !matched[v]) {
            matched[u] = matched[v] = true;
            answer++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);
    cout << answer << '\n';

    return 0;
}
