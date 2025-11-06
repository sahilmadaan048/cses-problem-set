// https://cses.fi/problemset/task/1645
 
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int n; cin >> n;
	vector<int> arr(n), result(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	stack<int> st;
 
	for(int i=0; i<n; i++) {
		while(!st.empty() and arr[st.top()] >= arr[i]){
			st.pop();
		}
 
		if(!st.empty()){
			result[i] = st.top()+1;
		}
		st.push(i);
	}
 
	for(auto ele : result) cout << ele << " " ;
 
	return 0 ;

}
    