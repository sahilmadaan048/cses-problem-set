// https://cses.fi/problemset/task/1674/
// author - sahilmadaan048

#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> graph;
vector<int> subtree_size;
 
int dfs(int node) {
    // Start by considering the current node itself
    int size = 0;  // No need to include the node itself in the count
    for (int child : graph[node]) {
        size += 1 + dfs(child); // Add the size of the subtree of the child and the child itself
    }
    subtree_size[node] = size;
    return size;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> temp(n + 1);
    graph.resize(n + 1);
    subtree_size.resize(n + 1, 0);
    
    // Input parent-child relations
    for (int i = 2; i <= n; i++) {
        cin >> temp[i];
        // Create the graph where 'temp[i]' is the parent of 'i'
        graph[temp[i]].push_back(i);
    }
    
    // Perform DFS from the root node (usually node 1)
    dfs(1);
    
    // Output the number of descendants for each node
    for (int i = 1; i <= n; i++) {
        cout << subtree_size[i] << " ";
    }
    
    return 0;
}