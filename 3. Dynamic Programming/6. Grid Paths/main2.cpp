// https://cses.fi/problemset/task/1638


#include <bits/stdc++.h>
using namespace std;
#define ll             long long int 
#define ulli           unsigned long long int 
#define li             long int 
#define ff(i,a,b)      for(int i=a;i<b;i++)
#define fb(i,b,a)      for(int i=b;i>=a;i--)
#define w(t)           while(--t >= 0)
#define l(s)           s.length()
#define ci(n)          cin>>n;
#define fast           ios_base::sync_with_stdio(false);
#define sa(a,n)        sort(a,a+n)
#define sv(v)          sort(v.begin(),v.end())
#define cy             cout<<"YES\n"
#define cn             cout<<"NO\n"
#define nl             cout<<"\n"
#define minus          cout<<"-1\n";
#define vi             vector<int>
#define pb             push_back
#define tc             int t; cin>>t;
#define pp             pair<int,int>
#define input(a,n)     for(int i=0;i<n;i++) cin>>a[i];
#define mod            1000000007
#define co(n)          cout<<n;
#define ret            return 0
#define mi             map<int,int>
#define output(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" ";   
#define forn(i, n)     ff(i, 0, n)
#define sz(v)          int((v).size())

int calWays(int row, int col, int n, vector<string>& grid, vector<vector<int>>& dp) {
    // Out of bounds or blocked cell
    if (row < 0 || row >= n || col < 0 || col >= n) return 0;
    if (grid[row][col] == '*') return 0;

    if (row == n - 1 && col == n - 1) return 1;

    if (dp[row][col] != -1) return dp[row][col];

    int right = calWays(row, col + 1, n, grid, dp);
    int down  = calWays(row + 1, col, n, grid, dp);

    return dp[row][col] = (right + down) % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    // Memoization table initialized with -1
    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << calWays(0, 0, n, grid, dp) << '\n';
}

int main() {
    fast;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}