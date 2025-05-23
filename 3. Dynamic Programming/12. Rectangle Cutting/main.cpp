// https://cses.fi/problemset/task/1744



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

const int MAX = 501;
vector<vector<int>> dp(MAX, vector<int>(MAX, -1));

int countways(int a, int b) {
	if(a == b) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	
	int res = 1e9;
	
	//vertical cuts
	for(int i=1; i<a; i++) {
		res = min(res, 1 + countways(i, b) + countways(a-i, b));
	}
	
	//ohrizontak cuts
	for(int j=1; j<b; j++) {
		res = min(res, 1 + countways(a, j) + countways(a, b-j));
	}

	return dp[a][b] = res;
}

void solve(){
	int a, b; cin >> a >> b;
	
	//recursively find the numb e r of ways then dp can be applied as per need
	cout << countways(a, b) << endl;
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
