// Author - sahilmadaan048
// https://cses.fi/problemset/task/2220

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

int xpow(int x, unsigned int y){
    int res=1;
    while(y>0){
        if (y&1) res= (res*x); y=y>>1; x=(x*x);
    }
    return res;
}


int solve(int x) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    int flag = 1;
    while(flag) {
        flag = 0;
        for (int i = log10(x) - 1; i >= 0; i--) {
            int m = xpow(10, i);
            if (x/(m*10)%10 == x/m%10) {
                x = (x/m - 1)*m + (m-1);
                flag = 1;
            }
        }
    }
    int n = log10(x)+1;
    int dp[n+1][2] = {0}; //dp[n][0] = free, dp[n][1] = contrained
    dp[0][0] = 1, dp[0][1] = 1;
    int ans = 1;
    int m = 1;
    for (int i = 1; i < n; i++, m *= 10) {
        dp[i][0] = xpow(9, i);
        dp[i][1] = (x/m%10)*dp[i-1][0] + dp[i-1][1];
        if (x/m%10 > x/(m*10)%10) dp[i][1] -= dp[i-1][0];
        ans += dp[i][0];
    }
    dp[n][1] = (x/m%10 - 1)*dp[n-1][0] + dp[n-1][1];
    return ans + dp[n][1];   
}

int32_t main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int T = 1;
   while (T--)
   {
    int x, y; cin>>x>>y;
    cout<<solve(y) - solve(x-1) << endl;
}
return 0;
}
