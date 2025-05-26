#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x;
set<int> sums; // Stores all reachable sums
vector<vector<bool>> visited; // visited[i][sum]

void dfs(int i, int sum) {
    if (i == n) {
        if (sum > 0) sums.insert(sum);
        return;
    }

    if (visited[i][sum]) return;
    visited[i][sum] = true;

    // Exclude current element
    dfs(i + 1, sum);

    // Include current element
    dfs(i + 1, sum + x[i]);
}

void solve() {
    cin >> n;
    x.resize(n);
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        max_sum += x[i];
    }

    visited.assign(n + 1, vector<bool>(max_sum + 1, false));

    dfs(0, 0);

    cout << (int)sums.size() << "\n";
    for (int val : sums) cout << val << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
