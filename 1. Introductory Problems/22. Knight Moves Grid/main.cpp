// https://cses.fi/problemset/task/3217



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

//what aare knight moves
//likek a sastika
vector<vector<int>> vis;
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int calMoves(int i, int j, int n) {
    if (i < 0 || j < 0 || i >= n || j >= n) return -1;
    if (i == 0 && j == 0) return 0;

    queue<pair<int, int>> q;
    vis.assign(n, vector<int>(n, -1));
    
    q.push({0, 0});
    vis[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 8; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && vis[nx][ny] == -1) {
                vis[nx][ny] = vis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return vis[i][j];  // return minimum moves to reach (i,j)
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = calMoves(i, j, n);
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
