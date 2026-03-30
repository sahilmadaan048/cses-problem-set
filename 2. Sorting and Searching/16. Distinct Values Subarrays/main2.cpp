#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Coordinate compression
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    vector<int> freq(n, 0);

    int l = 0;
    long long ans = 0;

    for(int r = 0; r < n; r++) {
        freq[a[r]]++;

        while(freq[a[r]] > 1) {
            freq[a[l]]--;
            l++;
        }

        ans += (r - l + 1);
    }

    cout << ans << "\n";
}