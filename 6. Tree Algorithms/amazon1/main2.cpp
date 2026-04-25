#include <bits/stdc++.h>
using namespace std;

int minimumExecutionTime(vector<int> jobSize, vector<int> throughput) {
    sort(jobSize.begin(), jobSize.end());
    sort(throughput.begin(), throughput.end());

    if(jobSize.back() > throughput.back()) return -1;

    long long n = jobSize.size();
    long long low = 1, high = 2 * n - 1;
    long long ans = high;

    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long cap = (mid + 1) / 2;

        __int128 total = (__int128)cap * throughput.size();

        if(total >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return (int)ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> jobSize(n);
    for(int i = 0; i < n; i++) cin >> jobSize[i];

    cin >> m;
    vector<int> throughput(m);
    for(int i = 0; i < m; i++) cin >> throughput[i];

    cout << minimumExecutionTime(jobSize, throughput) << '\n';

    return 0;
}