// https://cses.fi/problemset/task/2185/
// Author - sahilmadaan048

#include "bits/stdc++.h"
using namespace std;


#define int long long 

typedef __int128 lll; 

int n, k; 

int gcdll(int a, int b) {
	return b ? gcdll(b, a%b) : a;
}

void solve() {
	cin >> n >> k;

	vector<long long> a(k);

	for(int i=0; i<k; i++) {
		cin >> a[i];
	} 

	long long ans = 0;

	for(int mask=1; mask<(1<<k); mask++) {
		lll lcm = 1;
		bool bad = false;
		int bits = 0;

		for(int i=0; i<k; i++) {
			if(mask & (1 << i)) {   // is the ith element included in the subset
				bits++;

				long long g = gcdll((long long)lcm, a[i]);

				lcm = (lcm / g) * a[i];

				if(lcm > n) {
					bad = true;
					break;
				}
			}
		}

		// this subset contributes nothing, so skip it 
		if(bad) {
			continue;
		}

		long long cnt = n / (long long)lcm;

		// if number of elements included in that subset is odd, add the contribution
		if(bits&1) {
			ans += cnt;
		}
		else {
			ans -= cnt;
		}
	}

	cout << ans << "\n";
}

signed  main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
