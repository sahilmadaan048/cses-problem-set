// https://cses.fi/problemset/task/3397
// Author - sahilmadaan048

#include "bits/stdc++.h"
#define int long long
using namespace std;

using i128 = __int128_t;

void solve() {

    int T;
    cin >> T;

    vector<i128> fact(21);

    fact[0] = 1;

    for (int i = 1; i <= 20; i++)
        fact[i] = fact[i - 1] * i;

    while (T--) {

        int type;
        cin >> type;

        if (type == 1) {

            int n;
            i128 k;

            cin >> n;

            long long tmp;
            cin >> tmp;

            k = tmp;

            k--; // 0-indexed

            vector<int> nums;

            for (int i = 1; i <= n; i++)
                nums.push_back(i);

            vector<int> ans;

            for (int rem = n; rem >= 1; rem--) {

                i128 block = fact[rem - 1];

                int idx = k / block;

                k %= block;

                ans.push_back(nums[idx]);

                nums.erase(nums.begin() + idx);
            }

            for (int x : ans)
                cout << x << ' ';

            cout << '\n';
        }

        else {

            int n;
            cin >> n;

            vector<int> p(n);

            for (int i = 0; i < n; i++)
                cin >> p[i];

            vector<int> nums;

            for (int i = 1; i <= n; i++)
                nums.push_back(i);

            i128 rank = 0;

            for (int i = 0; i < n; i++) {

                int cnt = 0;

                while (nums[cnt] != p[i])
                    cnt++;

                rank += (i128)cnt * fact[n - i - 1];

                nums.erase(nums.begin() + cnt);
            }

            rank++;

            // print i128
            string s;

            if (rank == 0)
                s = "0";

            else {

                while (rank > 0) {

                    s.push_back('0' + rank % 10);

                    rank /= 10;
                }

                reverse(s.begin(), s.end());
            }

            cout << s << '\n';
        }
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}