#include <bits/stdc++.h>
using namespace std;

string dfs(int i, int j, int n, vector<string>& grid, vector<vector<string>>& dp) {
    if (i == n-1 && j == n-1)
        return string(1, grid[i][j]);

    if (!dp[i][j].empty()) return dp[i][j];

    string res = "~"; // '~' is lexicographically larger than any lowercase letter

    // move down
    if (i + 1 < n) {
        string temp = grid[i][j] + dfs(i + 1, j, n, grid, dp);
        res = min(res, temp);
    }

    // move right
    if (j + 1 < n) {
        string temp = grid[i][j] + dfs(i, j + 1, n, grid, dp);
        res = min(res, temp);
    }

    return dp[i][j] = res;
}

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<vector<string>> dp(n, vector<string>(n));
    cout << dfs(0, 0, n, grid, dp) << endl;
}


int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
