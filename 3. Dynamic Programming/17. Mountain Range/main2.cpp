#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!

void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

int f(int i, int prev, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == arr.size()) return 0;
    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
    int notTake = f(i + 1, prev, arr, dp);
    int take = 0;
    if (prev == -1 || arr[i] < arr[prev]) take = 1 + f(i + 1, i, arr, dp);
    return dp[i][prev + 1] = max(take, notTake);
}

void solve(){
    int n; cin >> n;
    vector<int> temp(n);
    for(int i=0; i<n; i++) {
        cin >> temp[i];
    }

    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    cout << f(0, -1, temp, dp) << "\n";
    return;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);

 cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}

// ⚙️ So, Conclusion

// 🔹 It’s not the same as the longest decreasing subsequence (LDS).

// 🔹 It’s more like finding the longest visible decreasing path using stack-based visibility rules.