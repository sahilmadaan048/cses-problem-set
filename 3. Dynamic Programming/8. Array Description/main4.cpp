// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
using namespace std;
#define ll             long long int 
#define mod            1000000007
#define ff(i,a,b)      for(int i=a;i<b;i++)
#define fast           ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi             vector<int>
#define pb             push_back

void solve(){
	int n, m; cin >> n >> m;

	vector<int> x(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}

	// we only need 2 rows for space optimization
	vector<int> prev(m + 2, 0), curr(m + 2, 0);

	// base case for index 0
	if (x[0] == 0) {
		for (int val = 1; val <= m; val++) prev[val] = 1;
	} else {
		prev[x[0]] = 1;
	}

	// fill rows one by one using only previous row
	for (int i = 1; i < n; i++) {
		fill(curr.begin(), curr.end(), 0); // reset current row

		if (x[i] == 0) {
			for (int val = 1; val <= m; val++) {
				curr[val] = ((ll)prev[val - 1] + prev[val] + prev[val + 1]) % mod;
			}
		} else {
			int val = x[i];
			curr[val] = ((ll)prev[val - 1] + prev[val] + prev[val + 1]) % mod;
		}

		swap(prev, curr); // move current row to prev for next iteration
	}

	// sum all valid ways from last row
	int ans = 0;
	for (int val = 1; val <= m; val++) {
		ans = (ans + prev[val]) % mod;
	}

	cout << ans << endl;
}

int main(){
	fast;
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}
