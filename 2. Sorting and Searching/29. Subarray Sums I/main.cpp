 // https://cses.fi/problemset/task/1660
//  author - sahilmadaan048

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    ll x; // Use long long for x to handle large sums
    cin >> n >> x;
    
    vector<ll> temp(n); // Use long long for temp to handle large sums
    for (int i = 0; i < n; i++) cin >> temp[i];
     
    unordered_map<ll, ll> prefixCount; // To store the frequency of prefix sums
ll currentPrefixSum = 0;
ll count = 0;

    // Traverse through the array
for (int i = 0; i < n; i++) {
        currentPrefixSum += temp[i]; // Calculate the current prefix sum
        
        // Check if the current prefix sum equals x
        if (currentPrefixSum == x) count++;
        
        // Check if (currentPrefixSum - x) exists in the map
        if (prefixCount.find(currentPrefixSum - x) != prefixCount.end()) {
            count += prefixCount[currentPrefixSum - x];
        }
        
        // Update the frequency of the current prefix sum in the map
        prefixCount[currentPrefixSum]++;
    }
    
    cout << count << "\n";
    return 0;
}