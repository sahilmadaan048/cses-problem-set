// Author - sahilmadaan048

#include "bits/stdc++.h"
// #define int long long
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



/*
   conditiosn to satify for a Euerian path
      - all nodes must have an even degree
      - all vertices with non zero degree myust belong to one connected component
   

   Hierholzer algorithm 
      - traverse each vertex only once and return to the start

   
   key ideas 
      - instead of trying to "choose perfectly", we 
         - start from node 1
         - keep walking unused edges
         - when struck - backtrack
         - buld answer in reverse
      it works because
         - all degreesa re even
         - so whenever we enter a node, there's always a way to leave (until edges are exhausted)

*/


void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i});
        adj[b].push_back({a, i});

        degree[a]++;
        degree[b]++;
    }

    // All degrees must be even
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] % 2 != 0)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    // If edges exist but node 1 has no edges
    if (m > 0 && degree[1] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    // Connectivity check (only nodes with degree > 0 matter)
    vector<bool> visited(n + 1, false);

    function<void(int)> dfs = [&](int u)
    {
        visited[u] = true;

        for (auto edge : adj[u])
        {
            int v = edge.first;

            if (!visited[v])
            {
                dfs(v);
            }
        }
    };

    if (m > 0)
    {
        dfs(1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (degree[i] > 0 && !visited[i])
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    // Hierholzer's algorithm
    vector<bool> used(m, false);
    stack<int> st;
    vector<int> path;

    st.push(1);

    while (!st.empty())
    {
        int u = st.top();

        while (!adj[u].empty() && used[adj[u].back().second])
        {
            adj[u].pop_back();
        }

        if (adj[u].empty())
        {
            path.push_back(u);
            st.pop();
        }
        else
        {
            pair<int,int> edge = adj[u].back();
            adj[u].pop_back();

            int v = edge.first;
            int id = edge.second;

            if (!used[id])
            {
                used[id] = true;
                st.push(v);
            }
        }
    }

    if ((int)path.size() != m + 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    reverse(path.begin(), path.end());

    for (int x : path)
    {
        cout << x << " ";
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
