//
// Created by 박혜원 on 2020/03/19.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define VISIT 0

using namespace std;

vector<vector<int>> board;
vector<int> group;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int group_index = 0;

void resize(int size) {
    board.resize(size);
    for (int i = 0; i < size; i++) {
        board[i].resize(size);
    }
}

bool is_boundary(int x, int y) {
    return x >= 0 && y >= 0 && x < board.size() && y < board.size();
}

void dfs(int x, int y) {
    board[x][y] = VISIT;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!(is_boundary(nx, ny) && board[nx][ny] != VISIT)) continue;
        dfs(nx, ny);
        group[group_index]++;
    }
}

void group_counting() {

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] != VISIT) {
                group.push_back(1);
                dfs(i, j);
                group_index++;
            }
        }
    }
}

int main() {

    int size;
    cin >> size;

    resize(size);
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            scanf("%1d", &board[row][col]);
        }
    }
    group_counting();
    cout << (int) group.size() << '\n';
    sort(group.begin(), group.end());
    for (int i = 0; i < group.size(); i++) {
        cout << group[i] << '\n';
    }
    return 0;
}