#include <bits/stdc++.h>
using namespace std;

int selectLeastResourceTasks(vector<int> resourceConsumption) {
    int n = resourceConsumption.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(make_pair(resourceConsumption[i], i));
    }

    vector<int> prev(n), next(n);
    vector<bool> removed(n, false);

    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = i + 1;
    }

    long long total = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int value = top.first;
        int idx = top.second;

        if (removed[idx]) continue;

        total += value;

        int left = prev[idx];
        int right = next[idx];

        removed[idx] = true;

        if (left >= 0) removed[left] = true;
        if (right < n) removed[right] = true;

        int newLeft = (left >= 0) ? prev[left] : -1;
        int newRight = (right < n) ? next[right] : n;

        if (newLeft >= 0) next[newLeft] = newRight;
        if (newRight < n) prev[newRight] = newLeft;
    }

    return (int)total;
}


// #include <bits/stdc++.h>
// using namespace std;

// int selectLeastResourceTasks(vector<int> resourceConsumption) {
//     int n = resourceConsumption.size();
    
//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
//     for (int i = 0; i < n; i++) {
//         pq.push({resourceConsumption[i], i});
//     }
    
//     vector<bool> removed(n, false);
//     long long total = 0;
    
//     while (!pq.empty()) {
//         auto [val, idx] = pq.top();
//         pq.pop();
        
//         if (removed[idx]) continue;
        
//         total += val;
        
//         removed[idx] = true;
//         if (idx - 1 >= 0) removed[idx - 1] = true;
//         if (idx + 1 < n) removed[idx + 1] = true;
//     }
    
//     return total;
// }

int main() {
    int n; cin >> n;

    vector<int> arr(n);

    cout << selectLeastResourceTasks(arr) << endl; // Output: 4
    return 0;
}