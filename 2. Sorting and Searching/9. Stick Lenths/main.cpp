// https://cses.fi/problemset/task/1074
 
 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define vi vector<int>
#define fast ios_base::sync_with_stdio(false); cin.tie(0);
 
// again greedy method suubtracted from the median value
// will give the minimum total cost

void solve(){
    int n; cin >> n;
    vi temp(n);
    for(int i = 0; i < n; i++) cin >> temp[i];
    sort(temp.begin(), temp.end());
    int median = temp[n / 2];
    ll cnt = 0;
    for(int i = 0; i < n; i++) cnt += abs(temp[i] - median);
    cout << cnt << "\n";
}
 
int main(){
    fast;
    solve();
    return 0;
}
