// https://cses.fi/problemset/task/1746



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

	//use binary search to calculate the number of possoble between 1 and m such that the value at index
	//ind does not conflict with its neighbouring elements
	//that is the differencr e still remains atmost 1
	
int checkCount(int ind, vector<int>& x, int m) {
    int count = 0;
    for (int val = 1; val <= m; ++val) {
        bool valid = true;
        if (ind > 0 && x[ind - 1] != 0 && abs(x[ind - 1] - val) > 1) valid = false;
        if (ind < x.size() - 1 && x[ind + 1] != 0 && abs(x[ind + 1] - val) > 1) valid = false;
        if (valid) count++;
    }
    return count;
}

// int countWays(vector<int>& x, int m, vector<int>& temp, int ind) {
// 	if(ind == 0) {
// 		return checkCount(ind, x, m);
// 	}

// 	//nahi to shift to the next index and do thne smae
// 	return countWays(x, m, temp, ind-1);
// }

int countWays(vector<int>& x, int m, vector<int>& temp, int ind) {
    if(ind < 0) {
        return 1;
    }

    int idx = temp[ind];
    int total = 0;

    // try all values from 1 to m and count the valid ones recursively
    for(int val = 1; val <= m; val++) {
        bool valid = true;
        if(idx > 0 && x[idx - 1] != 0 && abs(x[idx - 1] - val) > 1) valid = false;
        if(idx < x.size() - 1 && x[idx + 1] != 0 && abs(x[idx + 1] - val) > 1) valid = false;

        if(valid) {
            x[idx] = val; // assign value
            total += countWays(x, m, temp, ind - 1); // recurse
            x[idx] = 0; // backtrack
        }
    }

    return total;
}

void solve(){
	int n, m; cin >> n >> m;
	
	vector<int> x(n);
	vector<int> temp;
	for(int i=0; i<n; i++) {
		 cin >> x[i];
		 if(x[i] == 0) temp.push_back(i);
	}
	//temp stores the indexes with hte unknows values
	//simple recursioon se kaise karenge
	//recursively for every value in temp array we have to find a suitable match bvetween 1 and m
	//and then count the number of such arrays possible of size n

	cout <<countWays(x, m, temp, temp.size() - 1) << endl;
}

int main(){
	fast;
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}