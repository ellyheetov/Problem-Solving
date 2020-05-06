//
// Created by 박혜원 on 2020/05/06.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> board;

    void initial_board(int size) {
        board.resize(size + 1);
        for (int i = 0; i < board.size(); i++) {
            board[i].resize(size + 1, 0);
        }
    }

    void print() {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    int find_next_val(int i, int j) {
        return board[i - 1][j] >= board[i][j - 1] ? board[i - 1][j] : board[i][j - 1];
    }

    int longestPalindromeSubseq(string s) {
        initial_board(s.length());
        string reverse_str = s;
        reverse(reverse_str.begin(), reverse_str.end());

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= s.length(); j++) {
                if (s[i - 1] == reverse_str[j - 1])
                    board[i][j] = board[i - 1][j - 1] + 1;
                else
                    board[i][j] = find_next_val(i,j);
//                    board[i][j] = max(board[i][j-1], board[i][j-1]);
            }
        }
//        print();
        return board[s.length()][s.length()];
    }
};

int main() {
    string str = "bbbab";
    cout << Solution().longestPalindromeSubseq(str);
    return 0;
}