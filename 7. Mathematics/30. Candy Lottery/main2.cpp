#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    long double ans = 0.0L;

    for (int i = 1; i <= K; i++) {
        long double p1 = powl((long double)i / K, N);
        long double p2 = powl((long double)(i - 1) / K, N);

        ans += (p1 - p2) * i;
    }

    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}