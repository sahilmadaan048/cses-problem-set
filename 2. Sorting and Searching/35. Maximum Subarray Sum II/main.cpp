// Author - sahilmadaan048
// https://cses.fi/problemset/task/1644


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
#ifndef SYMBOL
#define SYMBOL value
#endifusing namespace std;
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



void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n+1, 0); // 1-based for prefix

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    // Prefix sum
    vector<int> prefix(n+1, 0);
    for (int i = 1; i <= n; ++i)
        prefix[i] = prefix[i-1] + arr[i];

    multiset<int> window; // holds prefix[j - 1] for j in [i - b, i - a]
    int ans = LLONG_MIN;

    for (int i = a; i <= n; ++i) {
        // Insert prefix[i - a]
        window.insert(prefix[i - a]);

        // Erase prefix[i - b - 1] if i - b - 1 >= 0
        if (i - b - 1 >= 0) {
            window.erase(window.find(prefix[i - b - 1]));
        }

        // Get minimum prefix in the window
        int min_prefix = *window.begin();

        // Update answer
        ans = max(ans, prefix[i] - min_prefix);
    }

    cout << ans << endl;
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

    