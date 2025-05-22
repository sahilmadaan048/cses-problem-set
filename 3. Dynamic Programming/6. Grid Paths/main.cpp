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

vector<vector<int>> dp;

int calWays(int start, int end, int n, vector<string>& temp) {
    // Boundary check should come first
    if (start < 0 || start >= n || end < 0 || end >= n) return 0;
    
    if (temp[start][end] == '*') return 0;
    if (start == n - 1 && end == n - 1) return 1;

    int right = calWays(start, end + 1, n, temp);
    int down = calWays(start + 1, end, n, temp);

    return (right + down) % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    cout << calWays(0, 0, n, grid) << endl;
}

int main() {
    fast;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}