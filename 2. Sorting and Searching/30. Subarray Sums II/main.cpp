// Author - sahilmadaan048
// https://cses.fi/problemset/task/1661

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) cin >> temp[i];

    map<long long, long long> mpp;
    long long count = 0, currSum = 0;
    mpp[0] = 1;

    for (int i = 0; i < n; i++) {
        currSum += temp[i];
        count += mpp[currSum - x];
        mpp[currSum]++;
    }

    cout << count << "\n";
}

int main() {
    solve();
    return 0;
}