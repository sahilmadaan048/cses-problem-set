// https://cses.fi/problemset/task/1641
 
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x; cin >> n >> x;
    vector<pair<int, int>> temp(n);
    for(int i=0; i<n; i++) {
        cin >> temp[i].first;
        temp[i].second = i+1;
    }
 
    sort(temp.begin(), temp.end());
 
    for(int i=0; i<n; i++){
        if(i>0 and temp[i] == temp[i-1]) continue;
 
        int left = i+1, right = n-1;
        int temp_sum = x-temp[i].first;
        while(left<right){
            int sum = temp[left].first + temp[right].first;
 
            if(sum == temp_sum){
                cout << temp[i].second << " " << temp[left].second << " " << temp[right].second;
                return 0;
            }
            else if(sum < temp_sum){
                left++;
            }
            else right--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
 
}
