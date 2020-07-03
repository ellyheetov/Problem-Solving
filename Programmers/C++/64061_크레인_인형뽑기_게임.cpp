//
// Created by 박혜원 on 2020/07/03.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    for(int index = 0; index < moves.size(); index++){
        int place = moves[index] -1;
        int value = 0;
        for(int i = 0;i < board.size();i++){
            if(board[i][place] != 0) {
                value = board[i][place];
                board[i][place] = 0;
                break;
            }
        }
        if(value == 0) continue;
        if(!st.empty() && st.top() == value) {
            st.pop();
            answer += 2;
        } else
            st.push(value);
    }
    return answer;
}

int main(){
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};

    cout << solution(board,moves);
    return 0;
}