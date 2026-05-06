// #include <bits/stdc++.h>
// using namespace std;

// vector<int> solution(vector<int> a) {
//     vector<int> x, y;
//     x.push_back(a[0]);
//     y.push_back(a[1]);

//     for (int i = 2; i < a.size(); i++) {
//         int p = 0, q = 0;

//         for (int v : x) if (v > a[i]) p++;
//         for (int v : y) if (v > a[i]) q++;

//         if (p > q) x.push_back(a[i]);
//         else if (q > p) y.push_back(a[i]);
//         else {
//             if (x.size() <= y.size()) x.push_back(a[i]);
//             else y.push_back(a[i]);
//         }
//     }

//     for (int v : y) x.push_back(v);
//     return x;
// }


