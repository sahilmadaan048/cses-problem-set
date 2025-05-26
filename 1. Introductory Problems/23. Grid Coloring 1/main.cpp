// https://cses.fi/problemset/task/3311


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

//do the change so that no 2 characters are the same in that steinf ans then print the string
//we can store the element at the previosus index in terms of index like A=0 and B=1 
//and the current index can be modified to temp[3-i] where temp is the string ABCD
//
//so we HAVE to  hange wevery cell
string temp = "ABCD";

void updateString(int m, string& s) {
    for (int i = 0; i < m; i++) {
        for (int t = 0; t < 4; t++) {
            char c = temp[t];
            if ((i == 0 || c != s[i - 1]) && c != s[i]) {
                s[i] = c;
                break;
            }
        }
    }
}

void solve(){
	int n, m; cin >> n >> m;
	string s;
	while(n--) {
		cin >> s;
		updateString(m, s);
		cout << s << endl;
	}		
	return;
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
