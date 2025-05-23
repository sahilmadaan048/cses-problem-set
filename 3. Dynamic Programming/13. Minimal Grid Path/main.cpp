// https://cses.fi/problemset/task/3359


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
string curr, best;

void traverse(int i, int j, int n, vector<string>& grid) {
	if (i == n-1 && j == n-1) {
		if (best.empty() || curr < best) {
			best = curr;
		}
		return;
	}
	
	bool canRight = (j + 1 < n);
	bool canDown = (i + 1 < n);

	if (canRight && canDown) {
		char c1 = grid[i][j+1]; // right
		char c2 = grid[i+1][j]; // down

		if (c1 < c2) {
			curr.push_back(c1);
			traverse(i, j+1, n, grid);
			curr.pop_back();
		}
		else if (c2 < c1) {
			curr.push_back(c2);
			traverse(i+1, j, n, grid);
			curr.pop_back();
		}
		else {
			curr.push_back(c1);
			traverse(i, j+1, n, grid);
			traverse(i+1, j, n, grid);
			curr.pop_back();
		}
	}
	else if (canRight) {
		curr.push_back(grid[i][j+1]);
		traverse(i, j+1, n, grid);
		curr.pop_back();
	}
	else if (canDown) {
		curr.push_back(grid[i+1][j]);
		traverse(i+1, j, n, grid);
		curr.pop_back();
	}
}

void solve() {
	int n; cin >> n;
	vector<string> grid(n);
	for(int i=0; i<n; i++) cin >> grid[i];

	curr.push_back(grid[0][0]);  // important: include first character
	traverse(0, 0, n, grid);
	cout << best << endl;
}


int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
