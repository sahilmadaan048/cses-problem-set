#include <bits/stdc++.h>
using  namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int m = pattern.size();

    string s = pattern + '$' + text;

    int n = s.size();

    vector<int> z(n, 0);

    int l = 0, r = 0; 

    for(int i=1; i<n; i++) {
        if(i < r) {
            z[i] = z[i-l];

            // Handle case of z[i] reaching for characters 
            // beyond what we have seen at r

            if(i + z[i] > r) {
                z[i] = r - i;
            }
        }

        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        // update l and r
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }       
    }       

    int cnt = 0;

    for(auto ele : z) {
        if(ele == m) {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}