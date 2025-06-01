#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    list<int> people;
    
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }
 
    auto it = people.begin();
    while (!people.empty()) {
        it++;  // Move to the next person (skipping one)
        if (it == people.end()) it = people.begin();  // Circular condition
 
        cout << *it << " ";  // Print the eliminated person
        it = people.erase(it);  // Remove from the circle
 
        if (it == people.end()) it = people.begin();  // Adjust iterator if needed
    }
    cout << endl;
}
 
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}