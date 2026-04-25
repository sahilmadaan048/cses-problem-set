#include <bits/stdc++.h>
using namespace std;

bool canFinish(vector<int>& jobSize, vector<int>& throughput, long long T) {
    long long capacity_per_worker = (T + 1) / 2;
    map<int, long long> workerSlots;
    for (int t : throughput) workerSlots[t] += capacity_per_worker;
    
    vector<int> jobs = jobSize;
    sort(jobs.begin(), jobs.end(), greater<int>());
    
    for (int job : jobs) {
        auto it = workerSlots.lower_bound(job);
        if (it == workerSlots.end()) return false;
        it->second--;
        if (it->second == 0) workerSlots.erase(it);
    }
    return true;
}

int minimumExecutionTime(vector<int> jobSize, vector<int> throughput) {
    int n = jobSize.size();
    int maxThroughput = *max_element(throughput.begin(), throughput.end());
    
    for (int job : jobSize)
        if (job > maxThroughput) return -1;
    
    long long lo = 1, hi = 2LL * n - 1, ans = 2LL * n - 1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (canFinish(jobSize, throughput, mid)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    return (int)ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> jobSize(n);
    for (int i = 0; i < n; i++) {
        cin >> jobSize[i];
    }

    int m;
    cin >> m;

    vector<int> throughput(m);
    for (int i = 0; i < m; i++) {
        cin >> throughput[i];
    }

    cout << minimumExecutionTime(jobSize, throughput) << "\n";

    return 0;
}