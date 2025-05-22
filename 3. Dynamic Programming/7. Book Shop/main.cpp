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

int calPages(vector<int>& h, vector<int>& s, int x, int n, int ind) {
	if(x <= 0 || ind < 0) return 0;
	//either take this book
	int way1 = 0;
	if(h[ind] <= x) {
		way1 = s[ind] + calPages(h, s, x - h[ind], n, ind - 1);
	}
	//or dont take it
	int way2 = calPages(h, s, x, n, ind - 1);

	return max(way1, way2);
}

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
	cout << calPages(h, s, x, n, n-1) << endl;
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
