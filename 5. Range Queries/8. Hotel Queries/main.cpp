// Author - sahilmadaan048

// https://cses.fi/problemset/task/1143

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

struct Vertex {
    int value;
    int index;
};

const int MAXN = 200005;
Vertex tree[4 * MAXN];
#define INF (-1e9+7);


/*
    
    this generates a segment tree which can give me
    the maximum element in a range as well as the index of that element

*/

void build(vector<int>& h, int v , int tl, int tr) {
    if(tl == tr) {
        tree[v].value = h[tl];
        tree[v].index = tl+1;
        return;
    }
    int mid = (tl + tr) /2 ;
    build(h, 2*v, tl, mid);
    build(h, 2*v+1, mid+1, tr);

    if(tree[2*v].value >= tree[2*v+1].value) {
        tree[v] = tree[2*v];
    }

    else {
        tree[v] = tree[2*v+1];
    }
}

int query(int v, int tl, int tr, int num) {
    if(tree[v].value < num) {
        return 0;
    }

    if(tl == tr) {
        tree[v].value = tree[v].value - num;
        return tree[v].index;
    }

    int mid = (tl + tr) / 2;

    if(tree[2*v].value >= num) {
        int idx = query(2*v, tl, mid, num);
        if(tree[2*v].value >= tree[2*v+1].value) {
            tree[v] = tree[2*v];
        }
        else {
            tree[v] = tree[2*v+1];
        }

        return idx;
    }
    else {
        int idx = query(2*v+1, mid+1,  tr, num);
        if(tree[2*v].value >= tree[2*v+1].value) {
            tree[v] = tree[2*v];
        }
        else {
            tree[v] = tree[2*v+1];
        }
        return idx;
    }

}

void solve() {  
    int n, m;

    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> r(m);
    for(int i=0; i<m; i++) {
        cin >> r[i];
    }

    build(h, 1, 0, n-1);

    for(int i=0; i<m; i++) {
        cout << query(1, 0, n-1, r[i]) << " ";
    }
    cout << "\n";
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
