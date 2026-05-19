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
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));

using namespace std;

int MOD = 1e9+7;

vector<vi> graph;

vi depth, subtree, ans;

void dfs1(int node, int parent) {

	subtree[node] = 1;

	for(auto child : graph[node]) {

		if(child == parent) continue;

		depth[child] = depth[node] + 1;

		dfs1(child, node);

		subtree[node] += subtree[child];
	}
}

void dfs2(int node, int parent, int n) {

	for(auto child : graph[node]) {

		if(child == parent) continue;

		// nodes outside subtree become +1 farther
		// nodes inside subtree become -1 closer

		ans[child] = ans[node] + n - 2*subtree[child];

		dfs2(child, node, n);
	}
}

void solve() {

	int n; cin >> n;

	graph.resize(n+1);

	depth.resize(n+1);
	subtree.resize(n+1);
	ans.resize(n+1);

	fr(i, n-1) {

		int a, b; cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs1(1, 0);

	rep(i,1,n) {
		ans[1] += depth[i];
	}

	dfs2(1, 0, n);

	rep(i,1,n) {
		cout << ans[i] << " ";
	}
	nl;
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;

	while(T--) {
		solve();
	}

	return 0;
}