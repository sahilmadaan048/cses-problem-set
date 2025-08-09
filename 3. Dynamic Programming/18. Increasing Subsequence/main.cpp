// https://cses.fi/problemset/task/1145


#include <bits/stdc++.h>
using namespace std;

int getAns(vector<int>& temp, int n, int ind, int prev_idx, vector<vector<int>>& dp) {
    if (ind == n) return 0;

    if (dp[ind][prev_idx + 1] != -1) 
        return dp[ind][prev_idx + 1];

    // Option 1: skip this element
    int notTake = getAns(temp, n, ind + 1, prev_idx, dp);

    // Option 2: take this element (if increasing)
    int take = 0;
    if (prev_idx == -1 || temp[ind] > temp[prev_idx]) {
        take = 1 + getAns(temp, n, ind + 1, ind, dp);
    }

    return dp[ind][prev_idx + 1] = max(take, notTake);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) cin >> temp[i];

    // dp[ind][prev_idx+1] => store result when at index 'ind' with prev element at 'prev_idx'
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << getAns(temp, n, 0, -1, dp) << "\n";
}
