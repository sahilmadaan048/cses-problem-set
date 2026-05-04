// https://cses.fi/problemset/task/1628

// author - sahilmadaan048

#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int mid = n / 2;

    vector<ll> left, right;

    // left half
    for(int mask = 0; mask < (1 << mid); mask++) {
        ll sum = 0;
        for(int j = 0; j < mid; j++) {
            if(mask & (1 << j))
                sum += a[j];
        }
        left.push_back(sum);
    }

    // right half
    int rem = n - mid;
    for(int mask = 0; mask < (1 << rem); mask++) {
        ll sum = 0;
        for(int j = 0; j < rem; j++) {
            if(mask & (1 << j))
                sum += a[mid + j];
        }
        right.push_back(sum);
    }

    sort(right.begin(), right.end());

    ll ans = 0;

    for(auto s : left) {
        ll need = x - s;
        auto low = lower_bound(right.begin(), right.end(), need);
        auto high = upper_bound(right.begin(), right.end(), need);
        ans += (high - low);
    }

    cout << ans << "\n";
}