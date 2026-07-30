// https://cses.fi/problemset/task/3140


// Author - sahilmadaan048

#include <bits/stdc++.h>
using namespace std;

int n;

// Prints a reverse(l, r) query, reads the inversion count.
// Exits immediately if the count is 0 (as required by the problem).
long long queryReverse(int l, int r) {
    cout << l << " " << r << "\n";
    cout.flush();
    long long res;
    if (!(cin >> res)) exit(0);
    if (res == 0) exit(0);
    return res;
}

int main() {
    cin >> n;

    // Step 1: for each prefix length i, find invi = inversions inside [1..i]
    // by reversing it (get cur), then reversing it back (get pre, and restore array).
    // cur - pre = C(i,2) - 2*invi
    vector<long long> invArr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long cur = queryReverse(1, i);
        long long pre = queryReverse(1, i);
        long long C2 = (long long)i * (i - 1) / 2;
        invArr[i] = (C2 - (cur - pre)) / 2;
    }

    // Step 2: b[i] = number of elements before position i that are larger than a[i]
    vector<long long> b(n + 1, 0);
    for (int i = 1; i <= n; i++) b[i] = invArr[i] - invArr[i - 1];

    // Step 3: reconstruct the permutation, placing values 1..n one at a time.
    // For value v, find the largest unfilled position j with b[j] + (filled count in [1, j-1]) == j-1.
    vector<bool> filled(n + 2, false);
    vector<int> a(n + 1, 0);
    vector<long long> prefCount(n + 2, 0);

    for (int v = 1; v <= n; v++) {
        prefCount[0] = 0;
        for (int k = 1; k <= n; k++)
            prefCount[k] = prefCount[k - 1] + (filled[k] ? 1 : 0);

        int chosenJ = -1;
        for (int j = n; j >= 1; j--) {
            if (!filled[j] && b[j] + prefCount[j - 1] == (long long)(j - 1)) {
                chosenJ = j;
                break;
            }
        }
        filled[chosenJ] = true;
        a[chosenJ] = v;
    }

    // Step 4: selection sort via reversal using the now-known array a[].
    for (int i = 1; i < n; i++) {
        int j = -1;
        for (int k = i; k <= n; k++) {
            if (a[k] == i) { j = k; break; }
        }
        if (j != i) {
            reverse(a.begin() + i, a.begin() + j + 1);
            queryReverse(i, j); // will exit(0) automatically once inversions hit 0
        }
    }

    return 0;
}