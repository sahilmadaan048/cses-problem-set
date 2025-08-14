// https://cses.fi/problemset/task/1081/ 
 
#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main() {
    io;
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Read input
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        max_val = max(max_val, arr[i]);
    }
 
    // Frequency array to count occurrences of each number
    vector<int> freq(max_val + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    // Array to store the number of elements divisible by each index
    vector<int> multiple_count(max_val + 1, 0);
 
    // Compute the count of multiples for each number from 1 to max_val
    for (int i = 1; i <= max_val; i++) {
        for (int j = i; j <= max_val; j += i) {
            multiple_count[i] += freq[j];
        }
    }
 
    // Find the maximum GCD where there are at least two multiples
    for (int g = max_val; g >= 1; g--) {
        if (multiple_count[g] > 1) {
            cout << g << "\n";
            return 0;
        }
    }
 
    return 0;
}

/*
We have to basically find the largest divisor such that it divides atleast 2 numbers in the array x
. So we iterate from the max possible answer i.e. 1e6
 to 1
, and increase the divisor count if the number is present in array. Time complexity is O(nlogn)

*/