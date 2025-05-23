// https://cses.fi/problemset/task/3403



#include <bits/stdc++.h>
using namespace std;
#define ll             long long int 
#define ulli           unsigned long long int 
#define li             long int 
#define ff(i,a,b)      for(int i=a;i<b;i++)
#define fb(i,b,a)      for(int i=b;i>=a;i--)
#define w(t)           while(--t >= 0)
#define l(s)           s.length()
#define ci(n)          cin>>n;
#define fast           ios_base::sync_with_stdio(false);
#define sa(a,n)        sort(a,a+n)
#define sv(v)          sort(v.begin(),v.end())
#define cy             cout<<"YES\n"
#define cn             cout<<"NO\n"
#define nl             cout<<"\n"
#define minus          cout<<"-1\n";
#define vi             vector<int>
#define pb             push_back
#define tc             int t; cin>>t;
#define pp             pair<int,int>
#define input(a,n)     for(int i=0;i<n;i++) cin>>a[i];
#define mod            1000000007
#define co(n)          cout<<n;
#define ret            return 0
#define mi             map<int,int>
#define output(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" ";   
#define forn(i, n)     ff(i, 0, n)
#define sz(v)          int((v).size())

vector<int> currentLCS, bestLCS;

int lcs(vector<int>& a, vector<int>& b, int i, int j) {
    if (i == 0 || j == 0) {
        if (currentLCS.size() > bestLCS.size()) {
            bestLCS = currentLCS;
        }
        return 0;
    }

    if (a[i - 1] == b[j - 1]) {
        currentLCS.push_back(a[i - 1]);
        int res = 1 + lcs(a, b, i - 1, j - 1);
        currentLCS.pop_back();
        return res;
    }

    int left = lcs(a, b, i - 1, j);
    int right = lcs(a, b, i, j - 1);
    return max(left, right);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    bestLCS.clear();
    currentLCS.clear();

    int length = lcs(a, b, n, m);
    cout << length << '\n';

    // Reverse the result to print in correct order
    reverse(bestLCS.begin(), bestLCS.end());
    for (int x : bestLCS) cout << x << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}