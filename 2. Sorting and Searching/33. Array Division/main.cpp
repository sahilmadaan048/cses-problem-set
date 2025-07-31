// Author - sahilmadaan048
// https://cses.fi/problemset/task/1085

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


// bool is_valid(vector<int>& temp, long long max_sum, int k) {
//     long long currentSum = 0;
//     int parts = 1;

//     for (auto ele : temp) {
//         if (ele > max_sum) return false; // prevent illegal case
//         if (currentSum + ele > max_sum) {
//             parts++;
//             currentSum = ele;
//         } else {
//             currentSum += ele;
//         }
//     }

//     return parts <= k;
// }


// void solve(){
//     int n, k; cin >> n >> k;
//     vector<int> temp(n);
//     for(int i=0; i<n; i++) cin >> temp[i];

//     // lets use binary search
//     long long low =  *max_element(temp.begin(), temp.end());
//     long long high = accumulate(temp.begin(), temp.end(), 0);

//     long long answer = high;

//     while(low <= high) {
//         int mid = low + (high - low)/2;
//         if(is_valid(temp, mid, k)) {
//             answer = mid;
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }
//     cout << answer << endl;    
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

//     

#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<int>& a, long long max_sum, int k) {
    long long current_sum = 0;
    int parts = 1;  // Start with one subarray

    for (int num : a) {
        if (current_sum + num > max_sum) {
            parts++;
            current_sum = num;
        } else {
            current_sum += num;
        }
    }
    return parts <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    long long low = *max_element(a.begin(), a.end());
    long long high = accumulate(a.begin(), a.end(), 0LL);
    long long answer = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (is_valid(a, mid, k)) {
            answer = mid;
            high = mid - 1;  // Try smaller
        } else {
            low = mid + 1;   // Need bigger max sum
        }
    }

    cout << answer << "\n";
    return 0;
}
