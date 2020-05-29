//
// Created by 박혜원 on 2020/05/06.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> board;

    void board_initial(int col, int row) {
        board.resize(row + 1);
        for (int i = 0; i < row + 1; i++) {
            board[i].resize(col + 1, 0);
        }
    }

    int calc_board_value(int i, int j) {
        return board[i - 1][j] >= board[i][j - 1] ? board[i - 1][j] : board[i][j - 1];
    }

    int longestCommonSubsequence(string text1, string text2) {

        board_initial(text1.length(), text2.length());
        for (int i = 1; i <= text2.length(); i++) {
            for (int j = 1; j <= text1.length(); j++) {
                if (text1[j - 1] == text2[i - 1]) {
                    board[i][j] = board[i - 1][j - 1] + 1;
                    continue;
                }
                board[i][j] = calc_board_value(i, j);
            }
        }
        //print(text1, text2);
        return board[text2.length()][text1.length()];
    }
};

int main() {
    string str1 = "bl";
    string str2 = "yby";

    cout << Solution().longestCommonSubsequence(str1, str2);
    return 0;
}