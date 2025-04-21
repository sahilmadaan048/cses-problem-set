// https://cses.fi/problemset/task/1071

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

void solve(){
    long long x, y; cin >> x >> y ;

    //it is an infinite grid with the upper left square = 1
    // x means row, y means column (say)
    if(x > y) {
        //our topic of interest is x only, we will first locate the first member of that row depending on whether the x is odd or even
        //if odd, start = (x-1)^2 + 1 increase by (y-1 units)
        if(x&1) {
            long long start = (x-1)*1LL*(x-1) + 1;
            cout << (start + y - 1) << endl; // fixed: should increase by (y - 1) units, not (x - 1)
        } else {
            //if even, start from (x^2) and decrease till < (x)(x-1)
            long long start = x*1LL*x;
            //now column needs to be filtered, surely y is less than x here, that’s why we are in this nested block
            cout << (start - y + 1) << endl;
        }     
    } else {
        //if odd just start from y^2 and decrease the elements by 1 unit till x
        if(y&1) {
            long long start = y*1LL*y;
            cout << (start - x + 1) << endl;
        } else {
            //if even, use start = (y-1)^2 + 1 and increase till you reach the xth row
            long long start = (y-1)*1LL*(y-1) + 1;
            cout << (start + x - 1) << endl;
        }
    }
    return;
}


int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T ;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    