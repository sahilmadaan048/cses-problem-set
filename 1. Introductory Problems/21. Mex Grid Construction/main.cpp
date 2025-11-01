// https://cses.fi/problemset/task/3419



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
	int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Track used numbers in current row to the left and column above
            set<int> used;

            // Elements to the left in the same row
            for (int k = 0; k < j; ++k)
                used.insert(grid[i][k]);

            // Elements above in the same column
            for (int k = 0; k < i; ++k)
                used.insert(grid[k][j]);

            // Find the smallest nonnegative integer not in `used`
            int val = 0;
            while (used.count(val)) ++val;

            grid[i][j] = val;
        }
    }

    // Print the grid
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << grid[i][j] << " ";
        cout << "\n";
    }

}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
