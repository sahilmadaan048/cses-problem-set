// https://cses.fi/problemset/task/1140




// https://cses.fi/problemset/task/1140
#include <bits/stdc++.h>
using namespace std;

struct Project {
    long long start, end, reward;
};

void solve() {
    int n;
    cin >> n;
    vector<Project> projects(n);
    for (int i = 0; i < n; i++) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), [](const auto &a, const auto &b) {
        return a.end < b.end;
    });

    vector<long long> dp(n + 1, 0);
    vector<long long> ends(n);
    for (int i = 0; i < n; i++) ends[i] = projects[i].end;

    for (int i = 1; i <= n; i++) {
        int j = upper_bound(ends.begin(), ends.end(), projects[i - 1].start - 1) - ends.begin();
        dp[i] = max(dp[i - 1], dp[j] + projects[i - 1].reward);
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
