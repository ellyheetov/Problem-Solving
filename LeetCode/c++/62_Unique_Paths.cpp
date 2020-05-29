//
// Created by 박혜원 on 2020/04/25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> board;

    void create_board(int m, int n) {
        board.resize(n);
        for (int i = 0; i < board.size(); i++) {
            board[i].resize(m);
        }
    }

    void setting_board() {

        for (int col = 0; col < board[0].size(); col++) {
            board[0][col] = 1;
        }

        for (int row = 0; row < board.size(); row++) {
            board[row][0] = 1;
        }

        for (int row = 1; row < board.size(); row++) {
            for (int col = 1; col < board[row].size(); col++) {
                board[row][col] = board[row - 1][col] + board[row][col - 1];
            }
        }
    }

    int uniquePaths(int m, int n) {
        create_board(m, n);
        setting_board();
        return board[n - 1][m - 1];
    }
};

int main() {
    int m = 0;
    int n = 0;
    cout << Solution().uniquePaths(m, n);
    return 0;
}