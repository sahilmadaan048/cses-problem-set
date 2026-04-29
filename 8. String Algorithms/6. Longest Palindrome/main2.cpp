// // https://cses.fi/problemset/task/1111
// // Author - sahilmadaan048

// // ACCEPTED SOLUTION => Manacher implementation

// #include "bits/stdc++.h"
// #define int long long
// #define uint unsigned long long
// #define vi vector<int>
// #define vvi vector<vi >
// #define vb vector<bool>
// #define vvb vector<vb >
// #define fr(i,n) for(int i=0; i<(n); i++)
// #define rep(i,a,n) for(int i=(a); i<=(n); i++)
// #define nl cout<<"\n"
// #define dbg(var) cout<<#var<<"="<<var<<" "
// #define all(v) v.begin(),v.end()
// #define sz(v) (int)(v.size())
// #define srt(v)  sort(v.begin(),v.end())         // sort 
// #define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
// #define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
// #define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// // make sure to sort before applying unique // else only consecutive duplicates would be removed 
// #define bin(x,y)  bitset<y>(x) 
// using namespace std;
// int MOD=1e9+7;      // Hardcoded, directly change from here for functions!


// void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
// void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
// void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// // ================================== take ip/op like vector,pairs directly!==================================
// template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
// template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
// template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
// template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
// template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// // ===================================END Of the input module ==========================================


// void solve() {
//     string s;
//     cin >> s;

//     string t = "#";
//     for (char c : s) {
//         t += c;
//         t += "#";
//     }

//     int n = t.size();
//     vector<int> p(n);

//     int center = 0, right = 0;
//     int max_len = 0, max_center = 0;

//     for (int i = 0; i < n; i++) {
//         int mirror = 2 * center - i;

//         if (i < right)
//             p[i] = min(right - i, p[mirror]);

//         while (i - p[i] - 1 >= 0 &&
//                i + p[i] + 1 < n &&
//                t[i - p[i] - 1] == t[i + p[i] + 1])
//             p[i]++;

//         if (i + p[i] > right) {
//             center = i;
//             right = i + p[i];
//         }

//         if (p[i] > max_len) {
//             max_len = p[i];
//             max_center = i;
//         }
//     }

//     int start = (max_center - max_len) / 2;
//     cout << s.substr(start, max_len) << "\n";
// }
// int32_t main()
// {
 
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);

//     int T = 1;
//     while (T--)
//     {
//         solve();
//     }
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>

// using namespace std;

// // Paste the getOptimalTeamSize function here
// int getOptimalTeamSize(vector<int> lowerSkill, vector<int> higherSkill) {
//     int n = lowerSkill.size();
//     int low = 0, high = n, ans = 0;
//     while (low <= high) {
//         int k = low + (high - low) / 2;
//         if (k == 0) { low = 1; continue; }
//         vector<pair<int, int>> intervals;
//         for (int i = 0; i < n; i++) {
//             int L = k - higherSkill[i];
//             int R = lowerSkill[i] + 1;
//             if (L <= R && R >= 1 && L <= k) 
//                 intervals.push_back({max(1, L), min(k, R)});
//         }
//         if (intervals.size() < k) { high = k - 1; continue; }
//         sort(intervals.begin(), intervals.end());
//         priority_queue<int, vector<int>, greater<int>> pq;
//         int count = 0, idx = 0;
//         for (int pos = 1; pos <= k; pos++) {
//             while (idx < (int)intervals.size() && intervals[idx].first <= pos) {
//                 pq.push(intervals[idx].second);
//                 idx++;
//             }
//             while (!pq.empty() && pq.top() < pos) pq.pop();
//             if (!pq.empty()) { pq.pop(); count++; } 
//             else break;
//         }
//         if (count == k) { ans = k; low = k + 1; } 
//         else high = k - 1;
//     }
//     return ans;
// }

// int main() {
//     // Manually entering Sample Case 0
//     vector<int> lower = {1, 3, 2, 2, 2};
//     vector<int> higher = {2, 2, 1, 1, 3};
    
//     int result = getOptimalTeamSize(lower, higher);
//     cout << "Sample Case 0 Result: " << result << endl; 
//     // Expected: 3
    
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int getOptimalTeamSize(vector<int> lowerSkill, vector<int> higherSkill) {
    int n = lowerSkill.size();
    
    auto canForm = [&](int k) {

        vector<int> candidates;
        candidates.reserve(n);

        for (int i = 0; i < n; i++) {
            if (i + 1 + higherSkill[i] >= k) {
                candidates.push_back(i);
            }
        }


        if ((int)candidates.size() < k) return false;


        sort(candidates.begin(), candidates.end());

        for (int j = 0; j < k; j++) {
            int idx = candidates[j];
            if (lowerSkill[idx] < j) return false;
        }
        return true;
    };
    
    int lo = 0, hi = n, best = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (canForm(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<int> lowerSkill(n), higherSkill(n);
    for (int i = 0; i < n; i++) {
        cin >> lowerSkill[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> higherSkill[i];
    }
    
    int result = getOptimalTeamSize(lowerSkill, higherSkill);
    cout << result << "\n";
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int getOptimalTeamSize(vector<int> lowerSkill, vector<int> higherSkill) {
    int n = lowerSkill.size();

    vector<pair<int,int>> devs(n);
    for (int i = 0; i < n; i++) {
        devs[i] = {lowerSkill[i], higherSkill[i]};
    }
    
    auto canForm = [&](int k) -> bool {
        for (int l = 0; l + k - 1 < n; l++) {
            bool valid = true;
            for (int j = 0; j < k; j++) {
                int idx = l + j;
                if ((k - 1 - j)> devs[idx].second) {
                    valid = false;
                }
            }
            if (valid) return true;
        }
        return false;
    };
    
    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canForm(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}


int main() {
    struct TestCase {
        vector<int> lowerSkill;
        vector<int> higherSkill;
        int expected;
    };

    vector<TestCase> tests = {
        // Sample Case 0 (from problem images)
        {{0, 4, 2, 3, 3}, {0, 1, 3, 2, 4}, 3},
        
        // Problem statement example: n=5, lowerSkill=[1,3,2,2,2], higherSkill=[2,2,1,1,3]
        {{3, 4, 2, 1, 2, 5}, {1, 3, 4, 5, 3, 5}, 4},
        

        {{1, 3, 2, 2, 2}, {2, 2, 1, 1, 3}, 3},
        
        // Edge: single developer, always OK
        {{0}, {0}, 1},
        
        // Edge: all reject everyone (0,0 means must be alone)
        {{0, 0, 0}, {0, 0, 0}, 1},
        
        // All very permissive
        {{4, 4, 4, 4, 4}, {4, 4, 4, 4, 4}, 5},
        
        // Two developers, both OK with each other
        {{1, 1}, {1, 1}, 2},
    };

    int passed = 0;
    for (int i = 0; i < (int)tests.size(); i++) {
        int result = getOptimalTeamSize(tests[i].lowerSkill, tests[i].higherSkill);
        bool ok = (result == tests[i].expected);
        cout << "Test " << i << ": "
             << (ok ? "PASS" : "FAIL")
             << "  got=" << result
             << "  expected=" << tests[i].expected
             << "\n";
        if (ok) passed++;
    }
    cout << "\n" << passed << "/" << tests.size() << " tests passed.\n";
    return 0;
}