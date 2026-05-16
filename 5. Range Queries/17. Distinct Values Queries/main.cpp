// https://cses.fi/problemset/task/1734
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


struct Fenwick {
   int n;

   vector<int> bit;

   Fenwick(int sz) {
      n = sz;
      bit.assign(n+1, 0);
   }

   void add(int idx, int val) {
      for(; idx<=n; idx += idx & -idx) {
         bit[idx] += val;
      }
   }

   int sum(int idx) {
      int sum = 0;

      for(; idx>0; idx -= idx&-idx) {
         sum += bit[idx];
      }
      return sum;
   }

   int rangeSum(int l, int r) {
      return sum(r) - sum(l-1);
   }
};

struct Query {
   int l, r, id;

   bool operator<(const Query& other)
 const {
   return r < other.r;
 }

};

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<Query> queries(q);

    for (int i = 0; i < q; i++) {

        cin >> queries[i].l >> queries[i].r;

        queries[i].id = i;
    }

    sort(queries.begin(), queries.end());

    Fenwick bit(n);

    map<int,int> last;

    vector<int> ans(q);

    int ptr = 1;

    for (auto &qq : queries) {

        while (ptr <= qq.r) {

            int x = a[ptr];

            if (last.count(x))
                bit.add(last[x], -1);

            bit.add(ptr, +1);

            last[x] = ptr;

            ptr++;
        }

        ans[qq.id] =
            bit.rangeSum(qq.l, qq.r);
    }

    for (int x : ans)
        cout << x << '\n';
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


/*

   this is a offline fenwick tree problem

      KEY IDEA:

         process array from left -> right

         mentain: 
            only the latest occurence of each value contributes 1
            order occurences contibute a

            then:    
               sum(l, r)  => number of distint values in [L, R]

         example:
            [3, 2, 3, 1, 2]

            at index 5:

            active positions:
               3 at pos 3
               2 at pos 5
               1 at pos 4


         BIT containis 
            0 0 1 1 1

         range sum now give the distinct counts

         ALGORITHM:
            sort queries by the right endpoint

            as we move r:
               for value x[r]:
                  if seen before at p:
                     remove old contribution
                        bit.add(p, -1)

                  add current contribution
                     bit.add(r, +1)



            then we just have to answrt eh query:  
               bit.sum(r) - bit.sum(l-1)

         COMPLEXITY ANALYSIS :
            O((n+q) * log n)

            prefect for 2e5

*/