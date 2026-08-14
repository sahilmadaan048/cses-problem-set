// https://cses.fi/problemset/task/3223
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

const int MAXN = 200005;

int segtree[MAXN * 4];

long long inversion = 0;

long long get() {
    return inversion;
}

void update(int val, int diff, int node = 1, int l = 1, int r = MAXN) {
    if ( l > r or l > val or r < val ) return;
    if ( l == r) {
        segtree[node] += diff;
        return;
    }
    int mid = (l+r)/2;
    update(val, diff, node*2, l, mid);
    update(val, diff, node*2+1, mid+1, r);
    segtree[node] = segtree[node*2] + segtree[node*2+1];
}

int query(int L, int R, int node = 1, int l = 1, int r = MAXN) {
    if( r < L or l > R or l > R ) return 0;
    if( l >= L and r <= R ) return segtree[node];
    int mid = (l+r)/2;
    return query(L,R,node*2,l,mid) + query(L,R,node*2+1,mid+1,r);
}

void add(int val) {
    update(val, 1);
    inversion += query(val+1, MAXN);
}

void remove(int val) {
    update(val, -1);
    inversion -= query(0, val-1);
}

void compress(int ara[], int n){
    set<int> st;
    for(int i=0;i<n;i++) st.insert(ara[i]);
        map<int,int> mp;
    int cnt = 0;
    for(auto s:st) mp[s] = ++cnt;
        for(int i=0;i<n;i++) ara[i] = mp[ ara[i] ];
    }

void solve() {
   
    int n, k;
    cin >> n >> k;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
        compress(ara,n);
    for(int i=0;i<k;i++) add(ara[i]);
        cout << get() << " ";
    for(int i=k;i<n;i++) {
        add(ara[i]);
        remove(ara[i-k]);
        cout << get() << " ";
    }
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
