// https://cses.fi/problemset/task/2187

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

const int N = 2000005;

int fact[N], invFact[N];

int power(int a, int b)
{
    if (b == 0)
        return 1;

    int half = power(a, b / 2);

    half = (half * half) % MOD;

    if (b & 1)
    {
        half = (half * a) % MOD;
    }

    return half;
}


void precompute()
{
    fact[0] = 1;

    rep(i, 1, N - 1)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[N - 1] = power(fact[N - 1], MOD - 2);

    for (int i = N - 2; i >= 0; i--)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

int catalanTriangle(int n, int r)
{
    if (n < r)
    {
        return 0;
    }

    int ans = fact[n + r];

    ans = (ans * invFact[r]) % MOD;
    ans = (ans * invFact[n + 1]) % MOD;
    ans = (ans * (n - r + 1)) % MOD;

    return ans;
}

void solve()
{
    precompute();

    int n;
    cin >> n;

    string s;
    cin >> s;

    int balance = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            balance++;
        }
        else
        {
            balance--;
        }

        if (balance < 0)
        {
            cout << 0;
            return;
        }
    }

    int m = sz(s);

    if ((n - m + balance) & 1)
    {
        cout << 0;
        return;
    }

    int remaining = (n - m + balance) / 2;

    cout << catalanTriangle(remaining, remaining - balance);
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
