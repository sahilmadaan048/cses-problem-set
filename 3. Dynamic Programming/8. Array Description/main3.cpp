// https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
using namespace std;
#define ll             long long int 
#define mod            1000000007
#define ff(i,a,b)      for(int i=a;i<b;i++)
#define fb(i,b,a)      for(int i=b;i>=a;i--)
#define fast           ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi             vector<int>
#define pb             push_back

void solve(){
	int n, m; cin >> n >> m;

	vector<int> x(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}

	// dp[i][val] = number of valid ways to build array till index i with value val
	vector<vector<int>> dp(n, vector<int>(m + 2, 0));

	// base case for index 0
	if (x[0] == 0) {
		for (int val = 1; val <= m; val++) dp[0][val] = 1;
	} else {
		dp[0][x[0]] = 1;
	}

	// fill dp table
	for (int i = 1; i < n; i++) {
		if (x[i] == 0) {
			for (int val = 1; val <= m; val++) {
				dp[i][val] = ((ll)dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % mod;
			}
		} else {
			int val = x[i];
			dp[i][val] = ((ll)dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % mod;
		}
	}

	// sum all ways for the last index
	int ans = 0;
	for (int val = 1; val <= m; val++) {
		ans = (ans + dp[n - 1][val]) % mod;
	}

	cout << ans << endl;
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
