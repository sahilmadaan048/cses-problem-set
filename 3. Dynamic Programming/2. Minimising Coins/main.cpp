// https://cses.fi/problemset/task/1634



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
#define sz(v)          int((v).size())\

const int INF = INT_MAX;


int calc(int x, vector<int>& coins, vector<vector<int>>& dp, int ind) {
    if (x == 0) return 0;
    if (ind < 0 || x < 0) return INF;
    
    if (dp[x][ind] != -1) return dp[x][ind];

    int way1 = calc(x, coins, dp, ind - 1);
    
    int way2 = INF;
    if (coins[ind] <= x) {
        way2 = 1 + calc(x - coins[ind], coins, dp, ind);
    }

    return dp[x][ind] = min(way1, way2);
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(x + 1, vector<int>(n + 1, -1));

    int ans = calc(x, coins, dp, n - 1);
    if (ans >= INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
	