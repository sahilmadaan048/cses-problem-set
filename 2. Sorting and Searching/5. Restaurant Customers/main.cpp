 
// https://cses.fi/problemset/task/1619
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    map<int, int> events;
 
    // Read intervals and mark the start and end times
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        events[start]++; // Customer arrives
        events[end + 1]--; // Customer leaves (end + 1 for non-inclusive end)
    }
 
    int max_customers = 0;
    int current_customers = 0;
 
    // Traverse the map to compute the maximum number of customers
    for (const auto& event : events) {
        current_customers += event.second;
        max_customers = max(max_customers, current_customers);
    }
 
    cout << max_customers << endl;
 
    return 0;
}