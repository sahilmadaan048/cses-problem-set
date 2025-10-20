#include "bits/stdc++.h"
using namespace std;
int n;
vector<int> h, dp;

int glide(int i)
{
    if (dp[i] != -1)
        return dp[i];
    int best = 1;
    for (int j = i + 1; j < n; j++)
    {
        if (h[j] >= h[i])
            continue;
        bool valid = true;
        for (int k = i + 1; k < j; k++)
        {
            if (h[k] >= h[i])
            {
                valid = false;
                break;
            }
        }
        if (valid)
            best = max(best, 1 + glide(j));
    }
    return dp[i] = best;
}

void solve()
{
    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    dp.assign(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, glide(i));
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
