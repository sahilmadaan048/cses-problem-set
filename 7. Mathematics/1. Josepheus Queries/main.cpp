// https://cses.fi/problemset/task/2164/


/*

We will solve the problem recursively, reducing the problem by at least half at each step. If k<n2
, we can see that the answer would be 2k
. Otherwise, we have removed all the even positions. The odd positions can be renamed from 1,2,…,n2
 and we can recursively find the solution for it. And then we can re-map back to our original n
 by multiplying by 2
 and subtracting 1
.
Time complexity is O(logn)
.


*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f(ll n, ll k)
{
    if (n == 1)
        return 1;

    if(k <= (n+1)/2) {
        if(2*k > n) {   
            return (2 * k) % n;
        }
        else return 2*k;
    }

    ll temp = f(n/2, k - (n+1)/2);

        if(n%2 == 1) {
        return 2*temp + 1;
    }

    return 2*temp - 1;
 }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q; cin >> q;

    int n, k;
    while(q--) {
        cin >> n >> k;
        cout << f(n, k) << endl;
    }
}