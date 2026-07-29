// https://cses.fi/problemset/task/3305


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



int n, k; 
int ask(int x, int country) {
    if ( x <= 0 ) return 1000000004;
    if ( x > n ) return 0;
    string country_str = (country == 0) ? "F" : "S";
    cout << country_str << " " << x << endl;
    int res;
    cin >> res;
    return res ;
}
void answer(int x) {
    cout << "! " << x << endl;
}

bool tries(int country) {
    int res = -1;
    int l = 1, r = k;
    int dec = k/2;
    while( l <= r) {
        int mid = (l + r) / 2;
        int res1 = ask(mid, country);
        int res2 = ask(k-mid, 1 - country);
        if ( res1 <= res2 ) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if ( res != -1 ) {
        int res1 = ask(res, country);
        int res2 = ask(k-res+1, 1 - country);
        if ( res1 >= res2 ) {
            answer(res1);
            return true;
        } 
    }
    return false;

}

void solve () {
    cin >> n >> k;
    
    bool found = tries(0);
    if ( found ) return;
    found = tries(1);
    if ( found ) return;
    answer(-1);
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
