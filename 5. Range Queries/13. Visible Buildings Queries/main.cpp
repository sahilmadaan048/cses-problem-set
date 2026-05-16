// https://cses.fi/problemset/task/3304
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

struct MergeSortTree {
    int n;
    vector<vector<int>> tree;

    MergeSortTree(int sz) {
        n = sz;
        tree.resize(4 * n);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[node] = {a[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);

        merge(
            tree[2 * node].begin(),
            tree[2 * node].end(),
            tree[2 * node + 1].begin(),
            tree[2 * node + 1].end(),
            back_inserter(tree[node])
        );
    }

    int query(int node, int l, int r, int ql, int qr, int val) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr) {
            return lower_bound(
                tree[node].begin(),
                tree[node].end(),
                val
            ) - tree[node].begin();
        }

        int mid = (l + r) / 2;

        return query(2 * node, l, mid, ql, qr, val)
             + query(2 * node + 1, mid + 1, r, ql, qr, val);
    }
};

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> h(n);

    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> prevGreater(n, -1);

    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() && h[st.top()] < h[i])
            st.pop();

        if (!st.empty())
            prevGreater[i] = st.top();

        st.push(i);
    }

    MergeSortTree mst(n);

    mst.build(1, 0, n - 1, prevGreater);

    while (q--) {

        int a, b;
        cin >> a >> b;

        a--, b--;

        cout << mst.query(1, 0, n - 1, a, b, a) << '\n';
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
