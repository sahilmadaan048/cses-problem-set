// #include<bits/stdc++.h>
// using namespace std;

// long long solution(vector<int> structures) {
//     int n = structures.size();
    
//     long long baseAsc = LLONG_MIN, baseDesc = LLONG_MIN;
//     for (int i = 0; i < n; i++) {
//         baseAsc  = max(baseAsc,  (long long)structures[i] - i);
//         baseDesc = max(baseDesc, (long long)structures[i] + i);
//     }
    
//     long long asc = 0, desc = 0;
//     for (int i = 0; i < n; i++) {
//         asc  += (baseAsc  + i) - structures[i];
//         desc += (baseDesc - i) - structures[i];
//     }
    
//     return min(asc, desc);
// }

// int main(){
//     cout << solution({1, 4, 3, 2})      << endl;
//     cout << solution({5, 7, 9, 4, 11})  << endl;
//     return 0;
// }


long long solution(vector<int> structures) {
    int n = structures.size();
    
    long long baseAsc = LLONG_MIN, baseDesc = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        baseAsc  = max(baseAsc,  (long long)structures[i] - i);
        baseDesc = max(baseDesc, (long long)structures[i] + i);
    }
    
    long long asc = 0, desc = 0;
    for (int i = 0; i < n; i++) {
        asc  += (baseAsc  + i) - structures[i];
        desc += (baseDesc - i) - structures[i];
    }
    
    return min(asc, desc);
}


// // aiyaan

// #include <bits/stdc++.h>
// using namespace std;

// long long f(vector<int>& a, int t) {
//     int n = a.size();
//     long long r = 0;

//     for (int i = 0; i < n; i++) {
//         long long v = 1LL * t + i;
//         if (v < a[i]) return (long long)4e18;
//         r += v - a[i];
//     }

//     return r;
// }

// long long solution(vector<int> a) {
//     int n = a.size();

//     long long x = 4e18, y = 4e18;

//     for (int i = 0; i < n; i++) {
//         x = min(x, f(a, a[i] - i));
//     }

//     reverse(a.begin(), a.end());

//     for (int i = 0; i < n; i++) {
//         y = min(y, f(a, a[i] - i));
//     }

//     return min(x, y);
// }

// int main(){
//     cout << solution({1, 4, 3, 2})      << endl;
//     cout << solution({5, 7, 9, 4, 11})  << endl;
//     return 0;
// }
