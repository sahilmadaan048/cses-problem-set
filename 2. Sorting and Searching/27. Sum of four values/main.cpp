// https://cses.fi/problemset/task/
 
 
 
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x; 
    cin >> n >> x;
    vector<pair<int, int>> temp(n);
    
    // Read input and store in a vector of pairs
    for(int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        temp[i] = {a, i + 1};
    }  
    
    // Sort the vector by the first element of the pairs
    sort(temp.begin(), temp.end());
    
    // Iterate through all pairs (i, j) and use two pointers for the remaining elements
    for(int i = 0; i < n - 3; i++) {
        for(int j = i + 1; j < n - 2; j++) {
            int target = x - temp[i].first - temp[j].first;
            int left = j + 1, right = n - 1;
            
            while(left < right) {
                int sum = temp[left].first + temp[right].first;
                if(sum == target) {
                    cout << temp[i].second << " " << temp[j].second << " " << temp[left].second << " " << temp[right].second << "\n";
                    return 0;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE" << "\n";
    return 0;
}
 
 
