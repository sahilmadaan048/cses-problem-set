// https://cses.fi/problemset/task/1091
 
 
#include <iostream>
#include <set>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    
    multiset<int> tickets;
    // Read ticket prices and insert into the set
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        tickets.insert(price);
    }
 
    // Process each customer
    for (int i = 0; i < m; ++i) {
        int max_price;
        cin >> max_price;
 
        // Find the largest price <= max_price
        auto it = tickets.upper_bound(max_price);
        if (it == tickets.begin()) {
            // No ticket available within the max price
            cout << -1 << endl;
        } else {
            // Move iterator to the largest price <= max_price
            --it;
            cout << *it << endl;
            // Remove the ticket from the set
            tickets.erase(it);
        }
    }
    return 0;
}
