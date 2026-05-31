// sir this solution is basicaly a “range query + point update” problem.

// we have:

// 1. update one character
// 2. ask frequency of a character in a range

// example:

// s = "abracadabra"

// query:

// 2 l r c

// means:

// “how many times does character c occur from l to r?”

// first approach (brute force)

// for every query we loop from l to r and count.

// complexity becomes:

// o(r-l+1)

// worst case:

// o(n)

// for q queries total becomes:

// o(nq)

// = 2e5 × 2e5
// = 4e10

// which is too big.

// now which topic fits?

// this is exactly:

// 1. range query
// 2. point update

// so sqrt decomposition fits nicely here.

// main idea:

// divide the string into blocks of size √n.

// if:

// n = length of string

// then:

// number of blocks also becomes nearly √n.

// instead of processing every character everytime we store frequency of characters block wise.

// what to store?

// for every block we maintain:

// freq[block][26]

// where:

// freq[b][0] = count of 'a'
// freq[b][1] = count of 'b'
// ...
// freq[b][25] = count of 'z'

// suppose:

// s = "abracadabra"

// and block size = 3

// then blocks become:

// [abr]
// [aca]
// [dab]
// [ra]

// now every block stores frequency of all characters.

// for example:

// block [aca]

// stores:

// a = 2
// c = 1

// most important math / logic:

// we choose block size as √n because:

// number of blocks = n / √n

// which becomes:

// √n

// so:

// partial traversal cost = o(√n)

// and:

// number of complete blocks is also nearly √n

// therefore total query complexity becomes:

// o(√n)

// preprocessing step:

// traverse the string once.

// for every index i:

// find its block using:

// block_id = i / block_size

// then increase frequency of that character in that block.

// query step:

// suppose query is:

// 2 3 10 a

// we need count of 'a' from index 3 to 10.

// divide the range into 3 parts:

// 1. left partial block
// 2. full middle blocks
// 3. right partial block

// left and right partial blocks are traversed manually.

// for full blocks instead of traversing character by character we directly use stored frequency like:

// answer += freq[block]['a']

// this is where optimisation happens.

// update step:

// suppose query is:

// 1 5 x

// meaning replace index 5 with x.

// first find block containing index 5.

// then:

// decrease old character frequency
// increase new character frequency
// update the string

// time complexities:

// preprocessing:

// o(n)

// query:

// o(√n)

// update:

// o(1)

// dry run:

// s = "abracadabra"

// block size = 3

// blocks are:

// [abr]
// [aca]
// [dab]
// [ra]

// query:

// 2 1 10 a

// means count 'a' from index 1 to 10.

// left partial block traversed manually.

// middle full blocks use stored freqencies directly.

// right partial block again manually.

// final answer = 4

// after update:

// 1 3 x

// string becomes:

// "abxacadabra"

// then query:

// 2 1 10 x

// gives answer = 1 because x occurs once now.

// matrix exponentiation doesnt fit here because it is used for recurrences, transitions and repeated operations like fibonacci or dp transitions while this problem is purely range query + update.

// in short:

// we store character frequencies block wise and answer queries in o(√n).



#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

string s;

int block_size;
int freq[500][26];

void build() {

    int n = s.size();

    block_size = sqrt(n);

    for (int i = 0; i < n; i++) {

        int block_id = i / block_size;

        freq[block_id][s[i] - 'a']++;
    }
}

void update(int idx, char ch) {

    int block_id = idx / block_size;

    freq[block_id][s[idx] - 'a']--;

    s[idx] = ch;

    freq[block_id][s[idx] - 'a']++;
}

int query(int l, int r, char ch) {

    int ans = 0;

    while (l <= r && l % block_size != 0) {

        if (s[l] == ch)
            ans++;

        l++;
    }

    while (l + block_size - 1 <= r) {

        int block_id = l / block_size;

        ans += freq[block_id][ch - 'a'];

        l += block_size;
    }

    while (l <= r) {

        if (s[l] == ch)
            ans++;

        l++;
    }

    return ans;
}

int main() {

    cin >> s;

    build();

    int q;
    cin >> q;

    while (q--) {

        int type;
        cin >> type;

        if (type == 1) {

            int idx;
            char ch;

            cin >> idx >> ch;

            idx--;

            update(idx, ch);
        }

        else {

            int l, r;
            char ch;

            cin >> l >> r >> ch;

            l--;
            r--;

            cout << query(l, r, ch) << "\n";
        }
    }

    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// bool check(long long m, long long h, int n, const vector<long long>& a, const vector<int>& c) {
//     long long d = 0;
//     for (int i = 0; i < n; ++i) {
//         long long count = 1 + (m - 1) / c[i];
//         if (count > 0) {
//             if (a[i] > 0 && count > (h - d + a[i] - 1) / a[i]) {
//                 return true;
//             }
//             d += count * a[i];
//         }
//         if (d >= h) return true;
//     }
//     return d >= h;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     long long h;
//     int n;
//     if (!(cin >> h >> n)) return 0;

//     vector<long long> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     vector<int> c(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> c[i];
//     }

//     long long low = 1, high = 1e18, ans = high;

//     while (low <= high) {
//         long long mid = low + (high - low) / 2;
//         if (check(mid, h, n, a, c)) {
//             ans = mid;
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }

//     cout << ans << "\n";

//     return 0;
// }