#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code here
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> basis; // XOR basis

    for (long long x : a)
    {
        for (long long b : basis)
        {
            x = min(x, x ^ b);
        }
        if (x)
        {
            basis.push_back(x);
        } // new independent element
    }

    int k = basis.size();
    cout << (1LL << k) << "\n"; // total distinct subset XORs

    return 0;
}
