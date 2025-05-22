// https://cses.fi/problemset/task/1637


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

//memoisation array
vector<int> dp;


void solve(){
	int n; cin >> n;
	dp.assign(9+1, 0);	
	//now we have the array we have to find the number of steps to reach 0 by using 
	
	dp[0] = 0;
	
	for(int i=1; i<=n; i++) {
		int res = INT_MAX;
		int temp = i;
		
		while(temp > 0) {
			int d = temp%10;
			temp /= 10;
			if(d == 0) continue;
			res = min(res, 1+dp[i - d]);
		}
		dp[i] = res;
	}
	
	cout << dp[n] << endl;
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}


//it can be further spaec optimsied using an array of sze 10 sice at every momemnt we can need just the previous 9 elements only