//
// Created by 박혜원 on 2020/03/28.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define RIPED 1
#define NOTRIPED 0

using namespace std;

vector<vector<int>> board;
queue<pair<int, int>> riped_que;

int N, M;
int answer = -1;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void board_initialize() {
    board.resize(N);
    for (int i = 0; i < N; i++) {
        board[i].resize(M);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == RIPED)
                riped_que.push(make_pair(i, j));
        }
    }
}

bool is_boundary(int row, int col) {
    return row >= 0 && col >= 0 && row < N && col < M;
}

void rotten(int row, int col) {

    for (int i = 0; i < 4; i++) {
        int new_row = row + dy[i];
        int new_col = col + dx[i];

        if (is_boundary(new_row, new_col) && board[new_row][new_col] == NOTRIPED) {
            board[new_row][new_col] = RIPED;
            riped_que.push({new_row, new_col});
        }
    }
}
bool all_riped(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == NOTRIPED) return false;
        }
    }
    return true;
}
int solution() {
    while (!riped_que.empty()) {
        int turn = riped_que.size();
        for(int i=0; i < turn; i++){
            int row = riped_que.front().first;
            int col = riped_que.front().second;

            riped_que.pop();
            rotten(row, col);
        }
        answer++;
    }
    if(all_riped())
        return answer;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie(0);

    cin >> M >> N;

    board_initialize();

    cout << solution();

    return 0;
}