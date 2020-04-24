//
// Created by 박혜원 on 2020/03/18.
//

#include <iostream>
#include <vector>

#define VISIT 0
using namespace std;

vector<vector<int>> board;
vector<int> group;
int group_counter = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void board_resize(int size) {
    board.resize(size);
    for (int i = 0; i < size; i++) {
        board[i].resize(size, 0);
    }
}

void make_board(int board_size) {
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            int x;
            cin >> x;
            board[i][j] = x;
        }
    }
}

bool is_boundary(int row, int col) {
    return row >= 0 && col >= 0 && col < board[0].size() && row < board.size();
}

void dfs(int x, int y) {
    board[x][y] = VISIT;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (is_boundary(nx, ny) && board[nx][ny] != VISIT)
            dfs(nx, ny);
    }
}

int find_group() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if(board[i][j]==VISIT) continue;
            dfs(i, j);
            group_counter++;
        }
    }
    group.push_back(group_counter);
    group_counter = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int board_size;
    cin >> board_size;

    board_resize(board_size);
    make_board(board_size);

    return 0;

}