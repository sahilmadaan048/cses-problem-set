// https://cses.fi/problemset/task/3403



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

vector<vector<int>> dp;
vector<int> a, b;

// Recursive LCS with memoization
int lcs(int i, int j) {
    if (i == 0 || j == 0) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];

    if (a[i - 1] == b[j - 1])
        return dp[i][j] = 1 + lcs(i - 1, j - 1);
    else
        return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
}

// Reconstruct the LCS sequence from the memoized table
vector<int> getLCS(int i, int j) {
    vector<int> result;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result.push_back(a[i - 1]);
            i--; j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    dp.assign(n + 1, vector<int>(m + 1, -1));
    int len = lcs(n, m);

    cout << len << '\n';

    vector<int> lcs_seq = getLCS(n, m);
    for (int x : lcs_seq) cout << x << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
