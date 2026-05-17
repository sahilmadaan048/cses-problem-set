// https://cses.fi/problemset/task/1739
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


struct Fenwick2D {

    int n;

    vector<vector<int>> bit;

    Fenwick2D(int sz) {

        n = sz;

        bit.assign(n + 1,
                   vector<int>(n + 1, 0));
    }

    void add(int y, int x, int val) {

        for (int i = y; i <= n; i += i & -i) {

            for (int j = x; j <= n; j += j & -j) {

                bit[i][j] += val;
            }
        }
    }

    int sum(int y, int x) {

        int res = 0;

        for (int i = y; i > 0; i -= i & -i) {

            for (int j = x; j > 0; j -= j & -j) {

                res += bit[i][j];
            }
        }

        return res;
    }

    int query(int y1, int x1,
              int y2, int x2) {

        return
            sum(y2, x2)
          - sum(y1 - 1, x2)
          - sum(y2, x1 - 1)
          + sum(y1 - 1, x1 - 1);
    }
};

void solve() {

    int n, q;
    cin >> n >> q;

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    Fenwick2D bit(n);

    // build BIT
    for (int y = 1; y <= n; y++) {

        for (int x = 1; x <= n; x++) {

            if (grid[y - 1][x - 1] == '*')
                bit.add(y, x, 1);
        }
    }

    while (q--) {

        int type;
        cin >> type;

        if (type == 1) {

            int y, x;
            cin >> y >> x;

            if (grid[y - 1][x - 1] == '*') {

                grid[y - 1][x - 1] = '.';

                bit.add(y, x, -1);
            }
            else {

                grid[y - 1][x - 1] = '*';

                bit.add(y, x, +1);
            }
        }

        else {

            int y1, x1, y2, x2;

            cin >> y1 >> x1 >> y2 >> x2;

            cout << bit.query(y1, x1,
                              y2, x2)
                 << '\n';
        }
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


/*
   
   this is a standard 2D Fenwick tREE (bit) PROBLEM

   WE NEED 
      point updates
      rectangle sum queries

   rctangle query 
      sum(y1, x1, y2, x2) 

      becomes inclusion-exclusion principle: 
      
      P(y2, x2) - P(y1-1, x2) - P(y2, x1-1) + P(y1-1 , x1-1)
   
*/