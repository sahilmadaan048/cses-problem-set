// https://cses.fi/problemset/task/1636



// #include <bits/stdc++.h>
// using namespace std;
// #define ll             long long int 
// #define ulli           unsigned long long int 
// #define li             long int 
// #define ff(i,a,b)      for(int i=a;i<b;i++)
// #define fb(i,b,a)      for(int i=b;i>=a;i--)
// #define w(t)           while(--t >= 0)
// #define l(s)           s.length()
// #define ci(n)          cin>>n;
// #define fast           ios_base::sync_with_stdio(false);
// #define sa(a,n)        sort(a,a+n)
// #define sv(v)          sort(v.begin(),v.end())
// #define cy             cout<<"YES\n"
// #define cn             cout<<"NO\n"
// #define nl             cout<<"\n"
// #define minus          cout<<"-1\n";
// #define vi             vector<int>
// #define pb             push_back
// #define tc             int t; cin>>t;
// #define pp             pair<int,int>
// #define input(a,n)     for(int i=0;i<n;i++) cin>>a[i];	
// #define mod            1000000007
// #define co(n)          cout<<n;
// #define ret            return 0
// #define mi             map<int,int>
// #define output(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" ";   
// #define forn(i, n)     ff(i, 0, n)
// #define sz(v)          int((v).size())


// ll countWays(int i, int x, vector<int>& coins, vector<vector<ll>>& dp) {
//     if (x == 0) return 1;
//     if (i == coins.size()) return 0;

//     if (dp[i][x] != -1) return dp[i][x];

//     ll ways = 0;
//     // take current coin (i), stay at same index since unlimited coins
//     if (x >= coins[i]) {
//         ways = countWays(i, x - coins[i], coins, dp);
//     }
//     // skip current coin
//     ways = (ways + countWays(i + 1, x, coins, dp)) % mod;

//     return dp[i][x] = ways;
// }

// void solve() {
//     int n, x;
//     cin >> n >> x;
//     vector<int> coins(n);
//     for (int i = 0; i < n; i++) cin >> coins[i];

//     vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, -1));
//     cout << countWays(0, x, coins, dp) << '\n';
// }

// int main() {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
//     solve();
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // dp[i] = number of ways to make sum i
    vector<ll> dp(x + 1, 0);
    dp[0] = 1; // Base case: 1 way to make sum 0 (using no coins)

    for (int coin : coins) {
        for (int sum = coin; sum <= x; sum++) {
            dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
        }
    }

    cout << dp[x] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}