// https://cses.fi/problemset/task/1132
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

vector<vector<int>> g;

vector<int> dist_from_a, dist_from_b;


int dfs(int node, int parent, int d, vector<int> & dist) {
	dist[node] = d;

	int farthestNode = node;

	for(auto child: g[node]) {
		if(child == parent) continue;

		int candidate = dfs(child, node, d+1, dist);

		if(dist[candidate] > dist[farthestNode]) {
			farthestNode = candidate;
		}
	}
	return farthestNode;
}

void solve(){	
	int n; cin >> n;
	g.resize(n+1);

	dist_from_a.resize(n+1);
	dist_from_b.resize(n+1);

	for(int i=1; i<n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}	

	// lets find the first endpoint of the diameter, start a dfs from any point say 1
	int a = dfs(1, 0, 0, dist_from_a);

	// lets find the second endpoint of that diameters
	int b = dfs(a, 0, 0, dist_from_a);


	// lets do one more dfs to fill the distance from b array
	dfs(b, 0, 0, dist_from_b);

	for(int i=1; i<=n; i++) {
		cout << max(dist_from_a[i], dist_from_b[i]) << " ";
	}

	cout << endl;
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
