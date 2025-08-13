// https://cses.fi/problemset/task/1192


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


int delrow[] = {-1, 0, 1,0};
int delcol[] = {0, 1, 0, -1};
 
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& temp){
	vis[row][col] = 1;
 
	int n = temp.size();
	int m = temp[0].size();
 
	for(int i=0; i<4; i++){
		int nrow = row+delrow[i];
		int ncol = col+delcol[i];
 
		if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && temp[nrow][ncol] == '.'){
			dfs(nrow, ncol, vis, temp);
		}
	}
	return;
}
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>> temp(n , vector<char>(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m ;j++){
			cin >> temp[i][j];
		}
	}
 
	vector<vector<int>> vis(n, vector<int>(m, 0));
	int count = 0;
	for(int i=0 ;i<n; i++){
		for(int j=0; j<m ; j++){
			if(!vis[i][j] && temp[i][j] == '.'){
				dfs(i, j, vis, temp);
				count++;
			}
		}
	}
 
	cout << count << endl;
    return;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    