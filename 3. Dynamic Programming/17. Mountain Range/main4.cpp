#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n, 1);
    stack<int> st;
    int ans = 1;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) dp[i] = dp[st.top()] + 1;
        st.push(i);
        ans = max(ans, dp[i]);
    }

    cout << ans;
}
