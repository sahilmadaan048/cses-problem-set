// Author - sahilmadaan048

#include "bits/stdc++.h"
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Store arrival, departure, original index
    vector<tuple<int, int, int>> customers;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        customers.push_back(make_tuple(a, b, i));
    }

    // Sort by arrival time
    sort(customers.begin(), customers.end());

    // Min-heap: {end_time, room_no}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> assigned(n);
    int nextRoom = 1;

    for (int i = 0; i < n; ++i) {
        int start = get<0>(customers[i]);
        int end = get<1>(customers[i]);
        int idx = get<2>(customers[i]);

        if (!pq.empty() && pq.top().first < start) {
            int room = pq.top().second;
            pq.pop();
            assigned[idx] = room;
            pq.push({end, room});
        } else {
            assigned[idx] = nextRoom;
            pq.push({end, nextRoom});
            nextRoom++;
        }
    }

    cout << nextRoom - 1 << "\n";
    for (int room : assigned)
        cout << room << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
