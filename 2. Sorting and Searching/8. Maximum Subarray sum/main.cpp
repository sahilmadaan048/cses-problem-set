// https://cses.fi/problemset/task/1643


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(0);
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
 
    for (int i = 0; i < n; i++) cin >> a[i];
 
    ll max_sum = LLONG_MIN, current_sum = 0;
 
    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0) current_sum = 0;
    }
 
    cout << max_sum << "\n";
}
 
int main() {
    fast;
    solve();
    return 0;
}