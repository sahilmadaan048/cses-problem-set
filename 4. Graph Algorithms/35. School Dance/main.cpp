// Author - sahilmadaan048

// https://cses.fi/problemset/task/1696

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

using namespace std;

int n;                          // total nodes in flow graph
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;

  queue<pair<int,int>> q;
  q.push({s, LLONG_MAX});

  while(!q.empty()) {
    auto [cur, flow] = q.front();
    q.pop();

    for(int next : adj[cur]) {
      if(parent[next] == -1 && capacity[cur][next] > 0) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);

        if(next == t)
          return new_flow;

       q.push({next, new_flow});
    }
 }
}
return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(n);

  int new_flow;
  while((new_flow = bfs(s, t, parent))) {
    flow += new_flow;

    int cur = t;
    while(cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
   }
}
return flow;
}

void solve() {
  int boys, girls, k;
  cin >> boys >> girls >> k;

  int source = boys + girls;
  int sink = boys + girls + 1;

  n = boys + girls + 2;

  capacity.assign(n, vector<int>(n, 0));
  adj.assign(n, vector<int>());

  auto add_edge = [&](int u, int v, int cap) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v] = cap;
 };

    // source -> boys
 for(int i = 0; i < boys; i++)
    add_edge(source, i, 1);

    // girls -> sink
 for(int i = 0; i < girls; i++)
    add_edge(boys + i, sink, 1);

    // boy -> girl edges
 for(int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
        // add_edge(a, boys + b, 1);
    int girl = boys + b;
    if(capacity[a][girl] == 0) {
      add_edge(a, girl, 1);
   }
}

int result = maxflow(source, sink);
cout << result << "\n";

    // print matching pairs
for(int i = 0; i < boys; i++) {
 for(int next : adj[i]) {
   if(next >= boys && next < boys + girls && capacity[i][next] == 0) {
     cout << i + 1 << " " << next - boys + 1 << "\n";
  }
}
}
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}