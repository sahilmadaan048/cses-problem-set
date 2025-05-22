// https://cses.fi/problemset/task/1158



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

void solve(){
	int n, x; cin >> n >> x;
	vector<int> h(n), s(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	
	// 0/1 knapsack problem
	vector<vector<int>> dp(n, vector<int>(x+1, 0));
	
	// Initialize base case: first book (i = 0)
	for (int j = 0; j <= x; ++j) {
		if (j >= h[0])
			dp[0][j] = s[0];
	}

	for(int i=1; i<n; i++) {
		for(int j=0; j<=x; j++) {
			int way2 = dp[i-1][j];
			
			int way1 = 0;
			if(j - h[i] >= 0) {
				way1 = s[i] + dp[i-1][j - h[i]];
			}
			dp[i][j] = max(way1, way2);
		}
	}
	
	cout << dp[n-1][x] << endl;
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
