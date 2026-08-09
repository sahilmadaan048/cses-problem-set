// https://cses.fi/problemset/task/3138

// Author - sahilmadaan048



#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector
#define sz(a) a.size()
#define rep(a, b, c) for (int a = b; a < c; ++a)

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

vector<int> ans;

array<vi<int>, 2> manacher(const string &s)
{
    // 0 is manacher even
    int n = sz(s);

    array<vi<int>, 2> p = {vi<int>(n + 1), vi<int>(n)};

    rep(z, 0, 2)
    {
        for (int i = 0, l = 0, r = 0; i < n; i++)
        {
            int t = r - i + !z;

            if (i < r)
                p[z][i] = min(t, p[z][l + t]);

            int L = i - p[z][i];
            int R = i + p[z][i] - !z;

            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
            {
                p[z][i]++;
                L--;
                R++;

                if (z == 0)
                {
                    int len = p[z][i];

                    if (len == 0)
                        continue;

                    int end = i + len - 1;
                    int dist = len * 2;

                    if (0 <= end && end < n)
                        ans[end] = max(ans[end], dist);
                }
                else
                {
                    int len = p[z][i];

                    if (len == 0)
                        continue;

                    int end = i + len;
                    int dist = (len * 2) + 1;

                    if (0 <= end && end < n)
                        ans[end] = max(ans[end], dist);
                }
            }

            if (R > r)
            {
                l = L;
                r = R;
            }
        }
    }

    return p;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    ans.assign(n, 0);

    auto man = manacher(s);

    for (auto i : ans)
    {
        cout << (i == 0 ? 1 : i) << ' ';
    }

    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif

    // cin >> t;

    for (int i = 0; i < t; ++i)
    {
        solve();
    }

#ifdef ONPC
    cerr << '\n'
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec\n";
#endif

    return 0;
}
