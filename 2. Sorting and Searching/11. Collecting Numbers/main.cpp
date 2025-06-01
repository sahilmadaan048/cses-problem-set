// https://cses.fi/problemset/task/2183
 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(0);
 
void solve(){
    int n; cin >> n;
    vi temp(n);
    for(int i = 0; i < n; i++) cin >> temp[i];
    sort(temp.begin(), temp.end());
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        if (temp[i] > ans) break;
        ans += temp[i];
    }
    cout << ans << "\n";
}
 
int main(){
    fast;
    solve();
    return 0;
}