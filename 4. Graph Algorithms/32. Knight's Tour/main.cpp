// Author - sahilmadaan048
// https://cses.fi/problemset/task/1689

#include <bits/stdc++.h>
using namespace std;

int board[8][8];

int dx[8] = {2,2,-2,-2,1,1,-1,-1};
int dy[8] = {1,-1,1,-1,2,-2,2,-2};

bool inside(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int degree(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inside(nx, ny) && board[nx][ny] == 0)
            cnt++;
    }
    return cnt;
}

bool solveTour(int x, int y, int moveNum) {

    board[x][y] = moveNum;

    if(moveNum == 64)
        return true;

    vector<pair<int,int>> candidates;

    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(inside(nx, ny) && board[nx][ny] == 0) {
            candidates.push_back({nx, ny});
        }
    }

    sort(candidates.begin(), candidates.end(), [&](auto &a, auto &b){
        return degree(a.first, a.second) < degree(b.first, b.second);
    });

    for(auto [nx, ny] : candidates) {
        if(solveTour(nx, ny, moveNum + 1))
            return true;
    }

    board[x][y] = 0;
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> y >> x;

    // find a combination in which he travels wach of the 64 places exactly once
    // and since it is a knight we are talking about , each time it can only do either
    // (x +- 2, y +- 1) or (x+-1, y+-2)

    /* Warnsdorff’s Rule:

       - move to the square that has the minimum number of onward movoes
       - this reduces the branching drastically
    */

    x--; 
    y--;

    memset(board, 0, sizeof(board));

    bool ok = solveTour(x, y, 1);

    // CSES guarantees solution exists, so ok should always be true

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}