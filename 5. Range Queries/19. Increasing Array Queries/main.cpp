// https://cses.fi/problemset/task/2416
// Author - sahilmadaan048


#include "bits/stdc++.h"
#define int long long
using namespace std;

const int LOG = 20;

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // prefix sums
    vector<int> pref(n + 1);

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];

    // next greater element
    vector<int> nxt(n + 2, n + 1);

    stack<int> st;

    for (int i = n; i >= 1; i--) {

        while (!st.empty() && a[st.top()] <= a[i])
            st.pop();

        if (!st.empty())
            nxt[i] = st.top();

        st.push(i);
    }

    // binary lifting
    vector<vector<int>> up(LOG, vector<int>(n + 2, n + 1));

    // add[k][i]
    // total target contribution for 2^k jumps
    vector<vector<int>> add(LOG, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++) {

        up[0][i] = nxt[i];

        add[0][i] =
            a[i] * (nxt[i] - i);
    }

    for (int k = 1; k < LOG; k++) {

        for (int i = 1; i <= n; i++) {

            up[k][i] =
                up[k - 1][up[k - 1][i]];

            add[k][i] =
                add[k - 1][i]
                + add[k - 1][up[k - 1][i]];
        }
    }

    while (q--) {

        int l, r;
        cin >> l >> r;

        int cur = l;

        int targetSum = 0;

        // take complete segments
        for (int k = LOG - 1; k >= 0; k--) {

            if (up[k][cur] <= r) {

                targetSum += add[k][cur];

                cur = up[k][cur];
            }
        }

        // final partial segment
        targetSum += a[cur] * (r - cur + 1);

        int original =
            pref[r] - pref[l - 1];

        cout << targetSum - original
             << '\n';
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}


/*
   
   the key obervation hers is: 

   to make a subarray nondescending using only incerements, every element myst becomome ar least the maximu mseen so far

   so fgor a subarray [l, r]

   target[i] = max(a[l....i])

   answer:  
      summation target[i] - summation a[i]

*/