#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int main() {
#ifndef ONLINE_JUDGE
   freopen("error.txt", "w", stderr);
#endif

   int n;
    cin >> n;

    vector<tuple<int, int, int>> intervals(n); // (l, r, index)
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        intervals[i] = make_tuple(l, r, i);
    }

    sort(intervals.begin(), intervals.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
        if (get<0>(a) == get<0>(b))
            return get<1>(a) > get<1>(b);
        return get<0>(a) < get<0>(b);
    });

    vector<bool> contains(n, false);
    vector<bool> contained(n, false);

    int max_r = 0;
    for (int i = 0; i < n; ++i) {
        int l = get<0>(intervals[i]);
        int r = get<1>(intervals[i]);
        int idx = get<2>(intervals[i]);

        if (r <= max_r)
            contained[idx] = true;
        max_r = max(max_r, r);
    }

    int min_r = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        int l = get<0>(intervals[i]);
        int r = get<1>(intervals[i]);
        int idx = get<2>(intervals[i]);

        if (r >= min_r)
            contains[idx] = true;
        min_r = min(min_r, r);
    }

    for (int i = 0; i < n; ++i) cout << contains[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i) cout << contained[i] << " ";
    cout << "\n";

    return 0;
}



// https://cses.fi/problemset/task/2168