#include <bits/stdc++.h>
using namespace std;

// Check if we can finish all fragments within 'T' seconds
bool canFinish(vector<int>& jobSize, vector<int>& throughput, long long T) {
    int n = jobSize.size();
    int m = throughput.size();
    
    // Each worker can handle ceil(T/2) fragments in T seconds
    long long capacity_per_worker = (T + 1) / 2;
    
    // Sort jobSize ascending, throughput ascending
    // Greedy: assign smallest jobs to weakest capable workers
    // Count how many jobs each worker can take
    
    // For each job (sorted), find if any worker can handle it
    // Use multiset to greedily assign
    
    // Total capacity of workers that can handle each job
    // Better: sort jobs desc, sort workers desc
    // Assign largest job to smallest sufficient worker
    
    vector<int> sortedJobs = jobSize;
    vector<int> sortedWorkers = throughput;
    sort(sortedJobs.begin(), sortedJobs.end(), greater<int>());
    sort(sortedWorkers.begin(), sortedWorkers.end(), greater<int>());
    
    // Use multiset of (throughput) for available workers
    multiset<int> available(sortedWorkers.begin(), sortedWorkers.end());
    
    long long totalCapacity = 0;
    
    // For each unique job size group, find workers that can handle them
    // Simpler: check if every job has at least one worker
    // Then check total capacity
    
    // Check 1: every job must be handleable by at least one worker
    // (already checked before calling this in main)
    
    // Check 2: total capacity >= n
    // But capacity depends on which workers are assigned jobs
    // Greedy: assign jobs to weakest capable worker to maximize remaining capacity
    
    // Actually for minimum time check:
    // Sort jobs descending, for each job find the weakest worker >= jobSize
    // that still has capacity, assign one slot to it
    
    // Track remaining slots per worker
    // Use a map: throughput -> remaining_slots
    
    map<int, long long> workerSlots;
    for (int t : throughput) {
        workerSlots[t] += capacity_per_worker;
    }
    
    // Sort jobs descending
    vector<int> jobs = jobSize;
    sort(jobs.begin(), jobs.end(), greater<int>());
    
    for (int job : jobs) {
        // Find weakest worker with throughput >= job and remaining slots > 0
        auto it = workerSlots.lower_bound(job);
        if (it == workerSlots.end()) return false; // no worker can handle this job
        
        it->second--;
        if (it->second == 0) {
            workerSlots.erase(it);
        }
    }
    
    return true;
}

int minimumExecutionTime(vector<int> jobSize, vector<int> throughput) {
    int n = jobSize.size();
    int m = throughput.size();
    
    int maxThroughput = *max_element(throughput.begin(), throughput.end());
    
    // Check if any job can't be done by any worker
    for (int job : jobSize) {
        if (job > maxThroughput) return -1;
    }
    
    // Binary search on time T
    // Min possible T = 1, Max = 2*n - 1 (one worker doing all n jobs)
    long long lo = 1, hi = 2LL * n - 1, ans = 2LL * n - 1;
    
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (canFinish(jobSize, throughput, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    
    return (int)ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ---- Test Case 1 (from problem example) ----
    // Expected output: 1
    {
        vector<int> jobSize = {2, 5, 3};
        vector<int> throughput = {6, 2, 4};
        cout << "Test 1: " << minimumExecutionTime(jobSize, throughput) << " (expected: 1)" << endl;
    }
    
    // ---- Test Case 2 (Sample Case 0) ----
    // jobSize = [2,5,8], throughput = [6,7,4]
    // Fragment 8 exceeds all workers -> -1
    {
        vector<int> jobSize = {2, 5, 8};
        vector<int> throughput = {6, 7, 4};
        cout << "Test 2: " << minimumExecutionTime(jobSize, throughput) << " (expected: -1)" << endl;
    }
    
    // ---- Test Case 3 ----
    // 4 jobs, 2 workers
    // jobSize = [1,1,1,1], throughput = [5,5]
    // Each worker handles 2 jobs: T=3 (1 work, 1 cool, 1 work)
    {
        vector<int> jobSize = {1, 1, 1, 1};
        vector<int> throughput = {5, 5};
        cout << "Test 3: " << minimumExecutionTime(jobSize, throughput) << " (expected: 3)" << endl;
    }
    
    // ---- Test Case 4 ----
    // 1 job, 1 worker
    // Expected: 1
    {
        vector<int> jobSize = {3};
        vector<int> throughput = {5};
        cout << "Test 4: " << minimumExecutionTime(jobSize, throughput) << " (expected: 1)" << endl;
    }
    
    // ---- Test Case 5 ----
    // 5 jobs, 1 worker
    // T needed: 1,_,1,_,1,_,1,_,1 = 9 seconds
    // ceil(T/2) = 5 -> T = 9
    {
        vector<int> jobSize = {1, 1, 1, 1, 1};
        vector<int> throughput = {5};
        cout << "Test 5: " << minimumExecutionTime(jobSize, throughput) << " (expected: 9)" << endl;
    }
    
    // ---- Interactive input ----
    cout << "\n--- Enter your own test case ---" << endl;
    int n, m;
    cout << "Enter n (number of jobs): ";
    cin >> n;
    vector<int> jobSize(n);
    cout << "Enter jobSize: ";
    for (int i = 0; i < n; i++) cin >> jobSize[i];
    
    cout << "Enter m (number of workers): ";
    cin >> m;
    vector<int> throughput(m);
    cout << "Enter throughput: ";
    for (int i = 0; i < m; i++) cin >> throughput[i];
    
    cout << "Answer: " << minimumExecutionTime(jobSize, throughput) << endl;
    
    return 0;
}