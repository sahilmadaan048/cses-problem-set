// chatgpt

// vector<int> solution(vector<int> memory, vector<vector<int>> queries) {
//     int n = memory.size();
//     vector<int> result;
//     vector<int> id(n, 0);
//     int counter = 1;

//     for (auto &q : queries) {
//         if (q[0] == 0) {
//             int x = q[1];
//             int pos = -1;

//             for (int i = 0; i + x <= n; i += 8) {
//                 bool ok = true;
//                 for (int j = i; j < i + x; j++) {
//                     if (memory[j] != 0) {
//                         ok = false;
//                         break;
//                     }
//                 }
//                 if (ok) {
//                     pos = i;
//                     break;
//                 }
//             }

//             if (pos == -1) {
//                 result.push_back(-1);
//             } else {
//                 for (int j = pos; j < pos + x; j++) {
//                     memory[j] = 1;
//                     id[j] = counter;
//                 }
//                 result.push_back(pos);
//                 counter++;
//             }
//         } else {
//             int target = q[1];
//             int len = 0;
//             for (int i = 0; i < n; i++) {
//                 if (id[i] == target) {
//                     memory[i] = 0;
//                     id[i] = 0;
//                     len++;
//                 }
//             }
//             if (len == 0) result.push_back(-1);
//             else result.push_back(len);
//         }
//     }

//     return result;
// }



// #include<bits/stdc++.h>
// using namespace std;

// vector<int> solution(vector<int> memory, vector<vector<int>> queries) {
//     int n = memory.size();
//     int s = 8;
//     int counter = 0;
//     map<int, pair<int,int>> blocks;
//     vector<int> result;

//     for (auto& q : queries) {
//         if (q[0] == 0) {
//             int x = q[1];
//             int start = -1;
//             for (int i = 0; i <= n - x; i++) {
//                 if (i % s != 0) continue;
//                 bool ok = true;
//                 for (int j = i; j < i + x; j++) {
//                     if (memory[j] != 0) { ok = false; break; }
//                 }
//                 if (ok) { start = i; break; }
//             }
//             if (start == -1) {
//                 result.push_back(-1);
//             } else {
//                 counter++;
//                 for (int j = start; j < start + x; j++) memory[j] = 1;
//                 blocks[counter] = {start, x};
//                 result.push_back(start);
//             }
//         } else {
//             int id = q[1];
//             if (blocks.find(id) == blocks.end()) {
//                 result.push_back(-1);
//             } else {
//                 auto [st, len] = blocks[id];
//                 for (int j = st; j < st + len; j++) memory[j] = 0;
//                 blocks.erase(id);
//                 result.push_back(len);
//             }
//         }
//     }
//     return result;
// }

// int main(){
//     vector<int> memory = {0,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1};
//     vector<vector<int>> queries = {{0,2},{0,1},{0,1},{1,1},{0,3},{1,4},{0,4}};

//     vector<int> ans = solution(memory, queries);
//     for(int i = 0; i < ans.size(); i++){
//         cout << ans[i];
//         if(i != ans.size()-1) cout << ", ";
//     }
//     cout << endl;
//     return 0;
// }

// claude

vector<int> solution(vector<int> memory, vector<vector<int>> queries) {
    int n = memory.size();
    int s = 8;
    int counter = 0;
    map<int, pair<int,int>> blocks;
    vector<int> result;

    for (auto& q : queries) {
        if (q[0] == 0) {
            int x = q[1];
            int start = -1;
            for (int i = 0; i <= n - x; i++) {
                if (i % s != 0) continue;
                bool ok = true;
                for (int j = i; j < i + x; j++) {
                    if (memory[j] != 0) { ok = false; break; }
                }
                if (ok) { start = i; break; }
            }
            if (start == -1) {
                result.push_back(-1);
            } else {
                counter++;
                for (int j = start; j < start + x; j++) memory[j] = 1;
                blocks[counter] = {start, x};
                result.push_back(start);
            }
        } else {
            int id = q[1];
            if (blocks.find(id) == blocks.end()) {
                result.push_back(-1);
            } else {
                auto [st, len] = blocks[id];
                for (int j = st; j < st + len; j++) memory[j] = 0;
                blocks.erase(id);
                result.push_back(len);
            }
        }
    }
    return result;
}

