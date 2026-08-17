// https://cses.fi/problemset/task/1112

// Author - sahilmadaan048

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

#define int long long
#define ff first
#define ss second
#define endl '\n'

const long long inf = 1LL<<60; //1.5e18
const int md = 1000000007;

int dp[1005][105];
int exp(int x, unsigned int y, int p){
    int res=1; x=x%p;
    while(y>0){
        if (y&1) res= (res*x)%p; y=y>>1; x=(x*x)%p;
    }
    return res;
}
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int m = s.size();
    //dp[i][j] = no of strings of length i which do not contain s
    //           and whose suffix of length j is equal to the prefix of s
    //           
    //Let's add one character to each prefix of s and determine the max length 
    //of suffix which is also a prefix of s formed by the addition of each character
    int len[m][26];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            string pre = s.substr(0,i);
            pre += j+'A';
            len[i][j] = 0;
            for (int k = 0; k < pre.size(); k++) {
                if (pre.substr(k) == s.substr(0,pre.size() - k)) {
                    len[i][j] = pre.size() - k;
                    break;
                }
            }
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <=n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++) {
                (dp[i][len[j][k]] += dp[i-1][j])%=md;
            }
        }
    }
    int ans = exp(26,n,md);
    for (int i = 0; i < m; i++) {
        ans = (ans - dp[n][i] + md) % md;
    }
    cout<<ans;
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
