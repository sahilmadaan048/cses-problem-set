// // https://cses.fi/problemset/task/1636



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


// void solve() {
//     int n, x;
//     cin >> n >> x;
//     vector<int> coins(n);
//     for (int i = 0; i < n; i++) cin >> coins[i];

//     // dp[i][j] = number of ways to make sum j using first i coins
//     vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));

//     // base case: 1 way to make sum 0
//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = 1;
//     }

//     for (int i = 1; i <= n; i++) {
//         for (int sum = 0; sum <= x; sum++) {
//             // don't take current coin
//             dp[i][sum] = dp[i - 1][sum];

//             // take current coin (i-1 because 0-based indexing)
//             if (sum - coins[i - 1] >= 0) {
//                 dp[i][sum] = (dp[i][sum] + dp[i][sum - coins[i - 1]]) % mod;
//             }
//         }
//     }

//     cout << dp[n][x] << "\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     solve();
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

vector<int> coins;
vector<vector<ll>> memo;

ll solve(int pos, int sum) {
    if (sum == 0) return 1; // Base case: 1 way to make sum 0
    if (pos == coins.size() || sum < 0) return 0; // No coins left or invalid sum
    if (memo[pos][sum] != -1) return memo[pos][sum]; // Return memoized result

    // Option 1: Skip the current coin
    ll ways = solve(pos + 1, sum) % MOD;

    // Option 2: Take the current coin (if possible)
    if (sum >= coins[pos]) {
        ways = (ways + solve(pos, sum - coins[pos])) % MOD;
    }

    return memo[pos][sum] = ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Initialize memoization table with -1 (uncomputed)
    memo.assign(n + 1, vector<ll>(x + 1, -1));

    cout << solve(0, x) << "\n";

    return 0;
}
