// https://cses.fi/problemset/task/1664
// Author - sahilmadaan048

#include "bits/stdc++.h"
#define int long long
using namespace std;

const int MAXT = 1e6 + 5;
const int LOG = 21;

void solve() {

    int n, q;
    cin >> n >> q;

    vector<pair<int,int>> movies(n);

    for (int i = 0; i < n; i++) {

        int a, b;
        cin >> a >> b;

        movies[i] = {a, b};
    }

    // bestEnd[t]
    // minimum ending movie starting at t
    vector<int> bestEnd(MAXT, INT_MAX);

    for (auto &[a,b] : movies)
        bestEnd[a] = min(bestEnd[a], b);

    // suffix minimum
    // go[t] = best movie ending time
    vector<int> go(MAXT, INT_MAX);

    go[MAXT - 1] = bestEnd[MAXT - 1];

    for (int t = MAXT - 2; t >= 0; t--) {

        go[t] = min(bestEnd[t], go[t + 1]);
    }

    // if impossible
    for (int t = 0; t < MAXT; t++) {

        if (go[t] == INT_MAX)
            go[t] = MAXT - 1;
    }

    // binary lifting
    vector<vector<int>> up(LOG,
                           vector<int>(MAXT));

    for (int t = 0; t < MAXT; t++)
        up[0][t] = go[t];

    for (int k = 1; k < LOG; k++) {

        for (int t = 0; t < MAXT; t++) {

            up[k][t] =
                up[k - 1][up[k - 1][t]];
        }
    }

    while (q--) {

        int a, b;
        cin >> a >> b;

        int ans = 0;
        int cur = a;

        for (int k = LOG - 1; k >= 0; k--) {

            if (up[k][cur] <= b) {

                ans += (1LL << k);

                cur = up[k][cur];
            }
        }

        cout << ans << '\n';
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

/*

   core greedy

   for interval scheduling: 
      alway take theat movie fiurst that ends the earliest

   so for every possible start time t, define

      nextMovie[t]

      = ending time of the best movie starting at or after t

   then queries become:    starting from time a,
                           how many times can we do before exceedign b

                  this is BINARY LIFTING



*/